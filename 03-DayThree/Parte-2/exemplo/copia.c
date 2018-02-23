#include <stdio.h>

#define SIZE 13

int main() {
  int a, b;
  char linha[SIZE], c;
  FILE *arquivo;

  arquivo = fopen("entrada.txt", "r");
  fscanf(arquivo, "%d", &a);
  fscanf(arquivo, "%d", &b);

  // justifique este trecho
  do {
    c = getc(arquivo);
  } while(c != '\n');

  fgets(linha, SIZE, arquivo);
  fscanf(arquivo, "%d", &b);
  fclose(arquivo);

  arquivo = fopen("saida.txt", "w");
  fprintf(arquivo, "%d %d\n", a, b);
  fprintf(arquivo, "%s", linha);
  fclose(arquivo);

  return 0;
}
