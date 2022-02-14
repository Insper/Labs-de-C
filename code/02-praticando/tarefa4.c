// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa4.c"

#include <stdio.h>

// TODO: declare função modulo aqui. Veja abaixo como ela será usada





// não mexer...
int main() {
    
    // assertEquals é uma função do mutirão que confere
    // se o segundo argumento é igual ao terceiro.
    // Neste caso, se ele checa a chamada de modulo retorna o valor esperado. 
    assertEquals("mod(34) = 34", modulo(34), 34);
    assertEquals("mod(-34) = 34", modulo(-34), 34);
    assertEquals("mod(0) = 0", modulo(0), 0);
    assertEquals("mod(1) = 1", modulo(1), 1);
    assertEquals("mod(13) = 13", modulo(-13), 13);

    printSummary

    return 0;
}
