#include <stdio.h>
#include "teste.h"

int com_erro = 0;

/* Os exercícios abaixo codificam uma cor em um inteiro de 32 bits.
   Veja o exemplo abaixo.

   0x00RRGGBB
     ^
     | LIXO

   Ou seja, a cor branca corresponde a

   0x00FFFFFF

   A cor vermelho pura corresponde a

   0x00FF0000

   Usaremos operações de bits para criar inteiros definindo cores e
   extrair seus valores a partir de um inteiro.

   Todas as funções tem testes na função main. Se está em dúvida sobre
   o comportamento de alguma delas veja seus testes.
*/

/*
 * As funções abaixo devem extrair os bits correspondente a cada
 *  cor do inteiro 32 bits e retornar este valor.
 *
 *  Para exemplos veja os testes na função main.
*/

unsigned char blue(int rgb)
{
    return 0;
}

unsigned char green(int rgb) {
    return 0;
}

unsigned char red(int rgb) {
    return 0;
}

/* ------------------------------------ */

/*
   Agora vamos montar um inteiro a partir dos valores de
   *r*, *g* e *b* recebidos por argumento.
*/

int rgb_to_int(unsigned char r, unsigned char g, unsigned char b) {
    return 0;
}

/*
   Outra operação comum é "desmontar" um inteiro e retornar
   os valores de cada cor via ponteiros. Complete a função
   abaixo
*/

void int_to_rgb(int rgb, unsigned char *r, unsigned char *g, unsigned char *b) {

}

/*
   Vamos agora trabalhar com funções que mexem em somente um dos três inteiros.
   As funções abaixo deverão ser feitas sem usar as funções `rgb_to_int` e `int_to_rgb`.
   Ou seja, para computar os novos valores você deverá usar somente operações de bits.
*/

int zera_vermelho(int rgb) {
    return 0;
}

int verde_255(int rgb) {
    return 0;
}

/*
   Finalmente, por conta de endianness frequentemente recebemos os dados no formato BGR, ou seja

      bgr: 0xBBGGRR00
      rgb: 0x00RRGGBB

   Faça uma função que converte de bgr para rgb. Você pode usar as funções feitas acima, mas recomendamos
   que faça diretamente usando máscaras de bits.
*/

int bgr_to_rgb(unsigned int bgr) {
    return 0;
}

/* ------------------------------------ */
/*          FIM LAB bits                */
/* ------------------------------------ */

int main() {

    printf("\n\nblue\n=======================\n");
    assertEquals("preto",   blue(0x00000000), 0);
    assertEquals("branco",  blue(0x00FFFFFF), 0xFF);
    assertEquals("amarelo", blue(0x0000FFFF), 0xFF);
    assertEquals("laranja", blue(0x00FFFF00), 0x00);
    assertEquals("numeros", blue(0x12345678), 0x78);

    printf("\n\ngreen\n=======================\n");
    assertEquals("preto",   green(0x00000000), 0);
    assertEquals("branco",  green(0x00FFFFFF), 0xFF);
    assertEquals("amarelo", green(0x0000FFFF), 0xFF);
    assertEquals("laranja", green(0x00FFFF00), 0xFF);
    assertEquals("numeros", green(0x12345678), 0x56);

    printf("\n\nred\n=======================\n");
    assertEquals("preto",   red(0x00000000), 0);
    assertEquals("branco",  red(0x00FFFFFF), 0xFF);
    assertEquals("amarelo", red(0x0000FFFF), 0x00);
    assertEquals("laranja", red(0x00FFFF00), 0xFF);
    assertEquals("numeros", red(0x12345678), 0x34);

    printf("\n\nrgb_to_int\n=======================\n");
    assertEquals("preto", rgb_to_int(0, 0, 0), 0x00000000);
    assertEquals("branco", rgb_to_int(255, 255, 255), 0x00FFFFFF);
    assertEquals("amarelo", rgb_to_int(0, 255, 255), 0x0000FFFF);
    assertEquals("laranja", rgb_to_int(255, 255, 0), 0x00FFFF00);
    assertEquals("numeros", rgb_to_int(0x12, 0x34, 0x56), 0x00123456);

    unsigned char r = 1, g = 1, b = 1;
    printf("\n\nrgb_to_int\n=======================\n");
    int_to_rgb(0x00000000, &r, &g, &b);
    assertEquals("preto", r == 0 && g == 0 && b == 0, 1);

    int_to_rgb(0x00FFFFFF, &r, &g, &b);
    assertEquals("branco", r == 255 && g == 255 && b == 255, 1);

    int_to_rgb(0x0000FFFF, &r, &g, &b);
    assertEquals("amarelo", r == 0 && g == 255 && b == 255, 1);

    int x;

    int_to_rgb(0x00FFFF00, &r, &g, &b);
    assertEquals("laranja", r == 255 && g == 255 && b == 0, 1);

    int_to_rgb(0x12345678, &r, &g, &b);
    assertEquals("branco", r == 0x34 && g == 0x56 && b == 0x78, 1);

    printf("\n\nzera_vermelho\n====================	\n");
    assertEquals("preto ", zera_vermelho(0x00000000), 0x00000000);
    assertEquals("branco", zera_vermelho(0x00FFFFFF), 0x0000FFFF);
    assertEquals("amarelo", zera_vermelho(0x0000FFFF), 0x0000FFFF);
    assertEquals("laranja", zera_vermelho(0x00FFFF00), 0x0000FF00);
    assertEquals("numeros", zera_vermelho(0x00123456), 0x00003456);

    printf("\n\nverde_255\n====================	\n");
    assertEquals("preto ", verde_255(0x00000000), 0x0000FF00);
    assertEquals("branco", verde_255(0x00FFFFFF), 0x00FFFFFF);
    assertEquals("amarelo", verde_255(0x00FF33FF), 0x00FFFFFF);
    assertEquals("laranja", verde_255(0x00FFD212), 0x00FFFF12);
    assertEquals("numeros", verde_255(0x00123456), 0x0012FF56);

    printf("\n\nbgr_to_rgb\n=======================\n");
    assertEquals("preto  ", bgr_to_rgb(0x00000000), 0);
    assertEquals("branco ", bgr_to_rgb(0xFFFFFF00), 0x00FFFFFF);
    assertEquals("amarelo", bgr_to_rgb(0xFFFF0000), 0x0000FFFF);
    assertEquals("laranja", bgr_to_rgb(0x00FFFF00), 0x00FFFF00);
    assertEquals("numeros", bgr_to_rgb(0x12345678), 0x00563412);

    return com_erro;
}
