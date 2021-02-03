#include "stdio.h"
#include "pgm.h"

#define IMG_IN  "deepak-kumar-rX9uFci3pfY-unsplash.pgm"
#define IMG_OUT "image-out.pgm"

int process_pixel(int level) {
	int new_level;

	new_level = level;

	return new_level;
}

int main(int argc, char *argv[]) {

    PGMData image;
    readPGM(IMG_IN, &image);

    for (int x=0; x< image.row; x++){
        for (int y=0; y<image.col; y++){
            image.matrix[x][y] = process_pixel(image.matrix[x][y]);
        }
    }

    writePGM(IMG_OUT, &image);
}
