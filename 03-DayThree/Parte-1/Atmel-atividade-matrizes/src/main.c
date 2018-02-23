/**
 * Mutirão C - Aula 1
 * 5 semestre - Eng. da Computação - Insper
 * Igor/ Hashimoto/ Rafael
 *
 * Processamento de imagem embarcado e exibição no LCD
 *
 * Objetivo :
 *  - Introducao aos cursos :
 *    - Sistemas Hardware Software
 *    - Desafios de Programacao
 *    - Computacao Embarcada
 *  - Introducao a linguagem C
 *
 * Material :
 *  - Kit: ATMEL SAME70-XPLD - ARM CORTEX M7
 *  - Dispositivos : maXTouchXPLAINED PRO conectado ao EXT1
 */

#include "asf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ioport.h"
#include "image.h"
#include "image2.h"
#include "mutirao.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define IMG_HEIGHT 320u // pxs
#define IMG_WIDTH  320u // pxs

/************************************************************************/
/* VAR globais                                                          */
/************************************************************************/

// Espaco de memoria reservado para armazenar a imagem pos processamento
ili9488_color_t imgOutProcess[IMG_WIDTH][IMG_HEIGHT];

// Variavel global alterada para o valor 1 (pela interrupcao) toda vez
// que o botao SW0  é pressionado, uma vez servido o request deve-se
// atribuir 0 a variavel.
volatile uint8_t buttonFlag = 0;

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

/**
 * Funcao chamada para o processamento de imagem
 * parametros :
 *  in  : imgIn , imagem original no formato IMG_HEIGHT X IMG_WIDTH [px]
 *  out : imgOut, imagem processada no formato IMG_HEIGHT X IMG_WIDTH [px]
 *  in  : imgW  , largura da imagem em pxs
 *  in  : imgH  , altura da imagem em pxs
 */
uint32_t imageProcess(ili9488_color_t imgIn[IMG_WIDTH][IMG_HEIGHT], ili9488_color_t imgOut[IMG_WIDTH][IMG_HEIGHT], int imgW, int imgH){
	uint32_t timeUs;
	int i, j, l, m, val;	
	// inicializa contagem do tempo de processamento
	tic();

	for (j=1;j<imgW-1;j++){
		for (i=1;i<imgH-1;i++){
			val = (int) imgIn[i][j] * 4 - imgIn[i-1][j] - imgIn[i+1][j] - imgIn[i][j-1] - imgIn[i][j+1];
			imgOut[i][j] = abs(val);
		}
	}
	// retorna tempo de processamento em microsegundos us.
	timeUs = toc();
	return(timeUs);
}

uint32_t threshold(ili9488_color_t imgIn[IMG_HEIGHT][IMG_WIDTH], ili9488_color_t imgOut[IMG_HEIGHT][IMG_WIDTH], int imgW, int imgH) {
	tic();
	// sua implementacao
	return toc();			
}

uint32_t normalize(ili9488_color_t imgIn[IMG_HEIGHT][IMG_WIDTH], ili9488_color_t imgOut[IMG_HEIGHT][IMG_WIDTH], int imgW, int imgH) {
	tic();
	// sua implementacao
	return toc();
}

uint32_t convolution(ili9488_color_t imgIn[IMG_HEIGHT][IMG_WIDTH], ili9488_color_t imgOut[IMG_HEIGHT][IMG_WIDTH], double kernel[3][3], int imgW, int imgH) {
	tic();
	// sua implementacao
	return toc();
}

void zera_imagem(ili9488_color_t imgOut[IMG_WIDTH][IMG_HEIGHT], int imgW, int imgH, int val) {
	int i, j;
	for (i = 0; i < imgH; i++) {
		for (j = 0; j < imgW; j++) {
			imgOut[i][j] = (ili9488_color_t) val;
		}
	}
	tic();
	
	return toc();
}


// Funcao principal chamada na inicalizacao do uC.
int main(void){

	uint32_t time;            // variavel para armazenar tempo de processamento
	uint8_t  imageSelect; // variavle para selecao da imagem a ser exibida
                            // quando o botao for pressionado
                            // 1 = imagem processada
                            // 0 = imagem orignal
	
	char *mensagens[] = {"Original", "Limiar", "Convolucao", "Baixo contraste", "Normalizado", };

	double kernel[3][3];

	// inicializa placa e seus perifericos
	initBoardMutirao();

	// exibe imagem orignal, tempo de processamento suprimido.
	buttonFlag = 1;
	imageSelect = 0;

	// super loop
	// aplicacoes embarcadas não devem sair do while(1).
	while (1) {

		// se buttonFlag = 1 existe alteracao no estado do botao
		if(buttonFlag){
			ili9488_set_foreground_color(COLOR_CONVERT(COLOR_WHITE));
			ili9488_draw_filled_rectangle(0, 0, ILI9488_LCD_WIDTH-1, ILI9488_LCD_HEIGHT-1);
			
			ili9488_set_foreground_color(COLOR_CONVERT(COLOR_TOMATO));
			ili9488_draw_string(90, 30, mensagens[imageSelect]);
			
			if(imageSelect == 0){
				imgShow(imgRaw, 0);
			} else if (imageSelect == 1) {
				zera_imagem(imgOutProcess, IMG_WIDTH, IMG_HEIGHT, 0);
				time = threshold(imgRaw, imgOutProcess, IMG_WIDTH, IMG_HEIGHT);
				imgShow(imgOutProcess, time);
			} else if (imageSelect == 2) {
				zera_imagem(imgOutProcess, IMG_WIDTH, IMG_HEIGHT, 230);
				time = convolution(imgRaw, imgOutProcess, kernel, IMG_WIDTH, IMG_HEIGHT);
				imgShow(imgOutProcess, time);
			} else if (imageSelect == 3) {
				imgShow(image_low_contrast, 0);
			} else if (imageSelect == 4) {
				zera_imagem(imgOutProcess, IMG_WIDTH, IMG_HEIGHT, 127);
				time = normalize(image_low_contrast, imgOutProcess, IMG_WIDTH, IMG_HEIGHT);
				imgShow(imgOutProcess, time);
			}

			imageSelect = (imageSelect + 1) % 5;

			// A requisicao foi tratada, devemos agora zerar a flag.
			buttonFlag = 0;
		}
	}
	return 0;
}
