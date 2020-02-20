#ifndef FOURIER_H_
#define FOURIER_H_

#include "asf.h"
#include "arm_math.h"


#define SIGMA 32


float32_t *offset(int width, int height);

void pad(ili9488_color_t image[320][320], int img_width, int img_height, float32_t *padded, int pad_width, int pad_height);

void blur(float32_t *padded, int width, int height, float32_t buffer[1024], float32_t sub_buffer[1024], int fast);

void unpad(float32_t *padded, int pad_width, int pad_height, ili9488_color_t image[320][320], int img_width, int img_height);


#endif
