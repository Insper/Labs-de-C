#include <stdio.h>

/* TODO: implemente sua função soma aqui */

# define assertEquals(str, a, b) {if ((a) == (b)) printf("OK  : %s\n", str); else printf("FAIL: %s\n", str); }

int main() {
    double arr1[] = {1, 2, 3};
    assertEquals("Chamada simples", soma(arr1, 3), 6.0);
    assertEquals("Subvetor", soma(arr1, 2), 3.0);
    assertEquals("Array vazio", soma(arr1, 0), 0.0);
    assertEquals("Tamanho inválido", soma(arr1, -1), 0.0);

    return 0;
}