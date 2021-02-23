// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab5-"
#define SOLUTIONFILE "tarefa6.c"


#include <stdio.h>

typedef struct {
    int x;
    int y;
} ponto;

// TODO: declare função medio aqui. Veja abaixo como ela será usada
int medio(ponto a, ponto b, ponto *m) {
    return 0;
}

int main() {
    
    // assertEquals é uma função do mutirão que confere
    // se o segundo argumento é igual ao terceiro.
    // Neste caso, se ele checa a chamada de medio retorna o valor esperado. 
    ponto p1, p2, res;

    p1 = (ponto) {.x=0, .y=1};
    p2 = (ponto) {.x=2, .y=3};
    
    assertEquals("medio({0, 1}, {2, 3}) == 1", medio(p1, p2, &res), 1);
    assertEquals("medio({0, 1}, {2, 3}) -> res.x == 1", res.x, 1);
    assertEquals("medio({0, 1}, {2, 3}) -> res.y == 2", res.y, 2);

    p1 = (ponto) {.x=0, .y=1};
    p2 = (ponto) {.x=0, .y=2};
    assertEquals("medio({0, 1}, {0, 2}) == 1", medio(p1, p2, &res), 1);
    assertEquals("medio({0, 1}, {0, 2}) -> res.x == 0", res.x, 0);
    assertEquals("medio({0, 1}, {0, 2}) -> res.y == 1", res.y, 1);

    p1 = (ponto) {.x=1, .y=0};
    p2 = (ponto) {.x=2, .y=0};
    assertEquals("medio({1, 0}, {2, 0}) == 1", medio(p1, p2, &res), 1);
    assertEquals("medio({1, 0}, {2, 0}) -> res.x == 1", res.x, 1);
    assertEquals("medio({1, 0}, {2, 0}) -> res.y == 0", res.y, 0);

    p1 = (ponto) {.x=1, .y=2};
    p2 = (ponto) {.x=1, .y=2};
    assertEquals("medio({1, 2}, {1, 2}) == 0", medio(p1, p2, &res), 0);
    
    p1 = (ponto) {.x=0, .y=-1};
    p2 = (ponto) {.x=0, .y=3};
    assertEquals("medio({0, -1}, {0, 3}) == 1", medio(p1, p2, &res), 1);
    assertEquals("medio({0, -1}, {0, 3}) -> res.x == 0", res.x, 0);
    assertEquals("medio({0, -1}, {0, 3}) -> res.y == 1", res.y, 1);


    p1 = (ponto) {.x=-1, .y=0};
    p2 = (ponto) {.x=3, .y=0};
    assertEquals("medio({-1, 0}, {2, 3}) == 1 ", medio(p1, p2, &res), 1);
    assertEquals("medio({-1, 0}, {2, 3}) -> res.x == 1", res.x, 1);
    assertEquals("medio({-1, 0}, {2, 3}) -> res.y == 0", res.y, 0);

    printSummary

    // Configurações do mutirão. Não mexer.
    #include "../telemetry.c"

    return 0;
}