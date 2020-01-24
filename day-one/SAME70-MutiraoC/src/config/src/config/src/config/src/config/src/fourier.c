#include "arm_const_structs.h"

#include "fourier.h"


float32_t *offset(int width, int height) {
	ili9488_color_t *imgOutLCD = (ili9488_color_t *) BOARD_SDRAM_ADDR;

	return imgOutLCD + width * height * 3;
}


void pad(ili9488_color_t image[320][320], int img_width, int img_height, float32_t *padded, int pad_width, int pad_height) {
	int x, y;

	for(y = 0; y < img_height; y++) {
		for(x = 0; x < img_width; x++) {
			*padded = image[y][x];
			padded++;
			*padded = 0;
			padded++;
		}

		for(; x < pad_width; x++) {
			*padded = 0;
			padded++;
			*padded = 0;
			padded++;
		}
	}

	for(; y < pad_height; y++) {
		for(x = 0; x < pad_width; x++) {
			*padded = 0;
			padded++;
			*padded = 0;
			padded++;
		}
	}
}


void copy_row_to_buffer(float32_t *padded, int width, int height, int y, float32_t buffer[1024]) {
	padded += y * width * 2;

	for(int x = 0; x < width * 2; x++) {
		buffer[x] = *padded;
		padded++;
	}
}

void copy_buffer_to_row(float32_t buffer[1024], float32_t *padded, int width, int height, int y) {
	padded += y * width * 2;

	for(int x = 0; x < width * 2; x++) {
		*padded = buffer[x];
		padded++;
	}
}

void copy_col_to_buffer(float32_t *padded, int width, int height, int x, float32_t buffer[1024]) {
	padded += x * 2;

	for(int y = 0; y < height * 2; y += 2) {
		buffer[y] = *padded;
		buffer[y + 1] = *(padded + 1);
		padded += width * 2;
	}
}

void copy_buffer_to_col(float32_t buffer[1024], float32_t *padded, int width, int height, int x) {
	padded += x * 2;

	for(int y = 0; y < height * 2; y += 2) {
		*padded = buffer[y];
		*(padded + 1) = buffer[y + 1];
		padded += width * 2;
	}
}

void dft(float32_t x[1024], float32_t X[1024], int N, int sign) {
	for(int k = 0; k < N; k++) {
		float A = 0;
		float B = 0;

		for(int n = 0; n < N; n++) {
			float a = x[2 * n];
			float b = x[2 * n + 1];

			float t = sign * (2 * PI * k * n) / N;

			float s = sin(t);
			float c = cos(t);

			A += b * s + a * c;
			B += b * c - a * s;
		}

		X[2 * k] = A;
		X[2 * k + 1] = B;
	}

	for(int n = 0; n < N * 2; n++) {
		x[n] = X[n];
	}
}

void dft_forward(float32_t buffer[1024], float32_t sub_buffer[1024], int length) {
	dft(buffer, sub_buffer, length, 1);
}

void dft_inverse(float32_t buffer[1024], float32_t sub_buffer[1024], int length) {
	dft(buffer, sub_buffer, length, -1);

	for(int i = 0; i < length * 2; i++) {
		buffer[i] /= length;
	}
}

void fft_forward(float32_t buffer[1024], float32_t sub_buffer[1024], int length) {
	arm_cfft_f32(&arm_cfft_sR_f32_len512, buffer, 0, 1);
}

void fft_inverse(float32_t buffer[1024], float32_t sub_buffer[1024], int length) {
	arm_cfft_f32(&arm_cfft_sR_f32_len512, buffer, 1, 1);
}

void blur(float32_t *padded, int width, int height, float32_t buffer[1024], float32_t sub_buffer[1024], int fast) {
	int x, y;

	// forward transform

	for(y = 0; y < height; y++) {
		copy_row_to_buffer(padded, width, height, y, buffer);
		if(fast) {
			fft_forward(buffer, sub_buffer, width);
		}
		else {
			dft_forward(buffer, sub_buffer, width);
		}
		copy_buffer_to_row(buffer, padded, width, height, y);
	}

	for(x = 0; x < width; x++) {
		copy_col_to_buffer(padded, width, height, x, buffer);
		if(fast) {
			fft_forward(buffer, sub_buffer, height);
		}
		else {
			dft_forward(buffer, sub_buffer, height);
		}
		copy_buffer_to_col(buffer, padded, width, height, x);
	}

	// filter

	int center_y = height / 2;
	int center_x = width / 2;

	float variance = -2 * SIGMA * SIGMA;

	float32_t *temp = padded;

	for(y = 0; y < height; y++) {
		for(x = 0; x < width; x++) {
			int dy = center_y - (y + center_y) % height;
			int dx = center_x - (x + center_x) % width;

			float d = dy * dy + dx * dx;

			float g = 1 - exp(d / variance);

			*temp *= g;
			temp++;
			*temp *= g;
			temp++;
		}
	}

	// inverse transform

	for(y = 0; y < height; y++) {
		copy_row_to_buffer(padded, width, height, y, buffer);
		if(fast) {
			fft_inverse(buffer, sub_buffer, width);
		}
		else {
			dft_inverse(buffer, sub_buffer, width);
		}
		copy_buffer_to_row(buffer, padded, width, height, y);
	}

	for(x = 0; x < width; x++) {
		copy_col_to_buffer(padded, width, height, x, buffer);
		if(fast) {
			fft_inverse(buffer, sub_buffer, height);
		}
		else {
			dft_inverse(buffer, sub_buffer, height);
		}
		copy_buffer_to_col(buffer, padded, width, height, x);
	}
}


void unpad(float32_t *padded, int pad_width, int pad_height, ili9488_color_t image[320][320], int img_width, int img_height) {
	int x, y;

	int delta = 2 * (pad_width - img_width);

	for(y = 0; y < img_height; y++) {
		for(x = 0; x < img_width; x++) {
			image[y][x] = min(max(0, (int) round(*padded)), 255);
			padded += 2;
		}
		padded += delta;
	}
}
