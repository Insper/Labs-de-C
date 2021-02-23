// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab4-"
#define SOLUTIONFILE "tarefa2.c"


#include <stdio.h>

/* TODO: implemente sua função soma aqui */


int main() {
    double arr1[] = {1, 2, 3, 4, 5, 6};
    assertEquals("Chamada simples", soma(arr1, 6), 21);
    assertEquals("Subvetor", soma(arr1, 2), 3.0);
    assertEquals("Subvetor II", soma(arr1+2, 3), 12.0);
    assertEquals("Array vazio", soma(arr1, 0), 0.0);
    assertEquals("Tamanho inválido", soma(arr1, -1), 0.0);

    printSummary

    #include "../telemetry.c"

    return 0;
}