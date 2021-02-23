// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab4-"
#define SOLUTIONFILE "tarefa3.c"


#include <stdio.h>

/* TODO: implemente sua função conta_a aqui */


int main() {
    
    assertEquals("String \"abc\"", conta_a("abc"), 1);
    assertEquals("String \"bccdsfsd123124 sfdf 234\"", conta_a("bccdsfsd123124 sfdf 234"), 0);
    assertEquals("String \"1234354yrkgjdlfjdlk\"", conta_a("1234354yrkgjdlfjdlk"), 0);

    // 'a' != 'A' 
    assertEquals("String \"aAa\"", conta_a("aAa"), 2);

    assertEquals("String \"a a a a  \"", conta_a("a a a a"), 4);

    
    printSummary

    #include "../telemetry.c"

    return 0;
}