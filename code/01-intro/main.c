/**
 * Rafael Corsi @ insper edu br
 * Versao 21a
 * Lab 1:
 *    - introcuao a C
 */

#include <stdio.h>
#include "pgm.h"
#include "../macros_correcoes.h"

#define IMG_IN  "deepak-kumar-rX9uFci3pfY-unsplash.pgm"
#define IMG_OUT "image-out.pgm"

#define LABNUM "lab1-"

#include SOLUTIONFILE


int main(int argc, char *argv[]) {
    printf("Lab 1 Multirao C: %s \n", SOLUTIONFILE);
    printf("Valide o resultado do programa analisando a imagem gerada: %s\n", IMG_OUT);
    PGMData image;
    readPGM(IMG_IN, &image);

    for (int x=0; x< image.row; x++){
        for (int y=0; y<image.col; y++){
            image.matrix[x][y] = process_pixel(image.matrix[x][y]);
        }
    }

    writePGM(IMG_OUT, &image);
    printf(".... .... \nImagem processada com sucesso.\n");



    #include "../telemetry.c"
}
