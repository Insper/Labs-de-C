/**
 * Computaçao Embarcada
 * Mutirão C
 * Aula 1
 * Rafael Corsi e Fábio Ayres
 *
 * Exibe em bytes o tamanho dos tipos
 */

#include <stdio.h>

/**
 * (isso é um comentário em bloco)
 * Variaveis globais
 */


// Variaveis inteiras
char            var1;
unsigned char   var2;
signed char     var3;
int             var4;
unsigned int    var5;
short           var6;
unsigned short  var7;
long            var8;
unsigned long   var9;

// variaveis flutuantes
float           var10;
double          var11;
long double     var12;



void main(){

    printf(" Tipo           Bytes\n");
    printf(" char           %lu \n" ,(unsigned long)sizeof(var1));
    printf(" unsigned char  %lu \n" ,(unsigned long)sizeof(var2));
    printf(" signed char    %lu \n" ,(unsigned long)sizeof(var3));
    printf(" int            %lu \n" ,(unsigned long)sizeof(var4));
    printf(" unsigned int   %lu \n" ,(unsigned long)sizeof(var5));
    printf(" short          %lu \n" ,(unsigned long)sizeof(var6));
    printf(" unsigned short %lu \n" ,(unsigned long)sizeof(var7));
    printf(" long           %lu \n" ,(unsigned long)sizeof(var8));
    printf(" unsigned long  %lu \n" ,(unsigned long)sizeof(var9));
    printf(" long           %lu \n" ,(unsigned long)sizeof(var10));
    printf(" double         %lu \n" ,(unsigned long)sizeof(var11));
    printf(" long double    %lu \n" ,(unsigned long)sizeof(var12));


}
