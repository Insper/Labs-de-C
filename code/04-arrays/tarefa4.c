// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab4-"
#define SOLUTIONFILE "tarefa3.c"


#include <stdio.h>

/* TODO: implemente sua função conta_1 aqui */


int main() {
    
    assertEquals("String \"abc\"", conta_1("abc"), 0);
    assertEquals("String \"bccdsfsd123124 sfdf 234\"", conta_1("bccdsfsd123124 sfdf 234"), 2);
    assertEquals("String \"1234354yrkgjdlfjdlk\"", conta_1("1234354yrkgjdlfjdlk"), 1);
    assertEquals("String \"aAa\"", conta_1("aAa"), 0)
    assertEquals("String \"1 1 s w 0 1\"", conta_1("1 1 s w 0 1"), 3);

    
    printSummary

    #include "../telemetry.c"

    return 0;
}