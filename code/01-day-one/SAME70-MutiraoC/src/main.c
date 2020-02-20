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
#include "mutirao.h"
#include "fourier.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define IMG_HEIGHT 320u // pxs
#define IMG_WIDTH  320u // pxs

#define PAD_HEIGHT 128u // pxs
#define PAD_WIDTH  128u // pxs

#define PARTE1
//#define PARTE2
//#define PARTE3

/************************************************************************/
/* VAR globais                                                          */
/************************************************************************/

// Espaco de memoria reservado para armazenar a imagem pos processamento
ili9488_color_t imgOutProcess[IMG_WIDTH][IMG_HEIGHT];
float32_t buffer[256], sub_buffer[256];

// Variavel global alterada para o valor 1 (pela interrupcao) toda vez
// que o botao SW0  é pressionado, uma vez servido o request deve-se
// atribuir 0 a variavel.
volatile uint8_t buttonFlag = 0;

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

int process_pixel(int level) {
	int new_level;

	new_level = level;

	return new_level;
}

/**
 * Funcao chamada para o processamento de imagem
 * parametros :
 *  in  : imgIn , imagem original no formato IMG_HEIGHT X IMG_WIDTH [px]
 *  out : imgOut, imagem processada no formato IMG_HEIGHT X IMG_WIDTH [px]
 *  in  : imgW  , largura da imagem em pxs
 *  in  : imgH  , altura da imagem em pxs
 */
uint32_t imageProcess(ili9488_color_t imgIn[IMG_WIDTH][IMG_HEIGHT], ili9488_color_t imgOut[IMG_WIDTH][IMG_HEIGHT], int imgW, int imgH){
	int i, j, val;

	// inicializa contagem do tempo de processamento
	uint32_t t0 = tic();

// RAFAEL / IGOR
#ifdef PARTE1
  for(j=1;j<imgW-1;j++) {
		for(i=1;i<imgH-1;i++) {
			val = (int) imgIn[i][j] * 4 - imgIn[i-1][j] - imgIn[i+1][j] - imgIn[i][j-1] - imgIn[i][j+1];
			imgOut[i][j] = abs(val);
		}
   }
#endif 

// HASHI
#ifdef PARTE2
	float32_t *padded = offset(IMG_WIDTH, IMG_HEIGHT);
	pad(imgIn, IMG_WIDTH, IMG_HEIGHT, padded, PAD_WIDTH, PAD_HEIGHT);
	blur(padded, PAD_WIDTH, PAD_HEIGHT, buffer, sub_buffer, 0);
	unpad(padded, PAD_WIDTH, PAD_HEIGHT, imgOut, IMG_WIDTH, IMG_HEIGHT);
#endif

// MUTIRAO	
#ifdef PARTE3
	for(int y = 0; y < IMG_HEIGHT; y++) {
		for(int x = 0; x < IMG_HEIGHT; x++) {
			imgOut[y][x] = process_pixel(imgIn[y][x]);
		}
	}
#endif

	return(toc(t0));
}

/************************************************************************/
/*                                                                      */
/************************************************************************/

int main(void){

	uint32_t time;            // variavel para armazenar tempo de processamento
	uint8_t  imageSelect = 1; // variavle para selecao da imagem a ser exibida
                            // quando o botao for pressionado
                            // 1 = imagem processada
                            // 0 = imagem orignal

	// inicializa placa e seus perifericos
	initBoardMutirao();

	// exibe imagem orignal, tempo de processamento suprimido.
	imgShow(imgRaw, 0);

	// super loop
	// aplicacoes embarcadas não devem sair do while(1).
	while (1) {

		// se buttonFlag = 1 existe alteracao no estado do botao
		if(buttonFlag){

			// Verificamos qual imagem deve ser exibida (toggle)
			// se imageSelect = 1, processar e exibir img processada.
			if(imageSelect){
				// chama a funcao para processamento de imagem, resultando
				// na matriz imgOutProcess
				time = imageProcess(imgRaw, imgOutProcess, IMG_HEIGHT, IMG_WIDTH);

				// exibe imagem processada e seu tempo de processamento
				imgShow(imgOutProcess, time);

				// toggle na variavel, proximo request do botao
				// exibir imagem orignal.
				imageSelect = 0;
			}
			// se imageSelect = 0, exibir img original (imgRaw)
			else{
				// exibe imagem original, tempo de processamento é suprimido.
				imgShow(imgRaw, 0);

				// toggle na variavel, proximo requisicao do botao
				// exibir imagem processada.
				imageSelect = 1;
			}

			// A requisicao foi tratada, devemos agora zerar a flag.
			buttonFlag = 0;
		}
	}
	return 0;
}
