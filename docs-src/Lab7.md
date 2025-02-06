# Lab 7 - Escopo de variáveis

- http://linguagemc.com.br/funcoes-e-escopo-de-variaveis/

Em C possuímos três escopos distintos: **global**, **local** e **parâmetros formais**. O escopo define as regras de utilização das variáveis de um programa: onde elas são criadas e destruídas e como elas podem ser modificadas (escrita/leitura).

## Variáveis globais

Existem durante toda a execução do programa e são acessíveis para todas as funções. Para uma variável ser global, basta ser declarada fora de qualquer bloco de função.

No exemplo a seguir iremos criar uma variável global `g_counter` do tipo inteiro e a modificar em duas funções diferentes.

```c
int g_counter;

void inc (void) {
    g_counter++;
}

void dec (void) {
    g_counter--;
}
```

!!! exercise choice two-cols
    ```c linenums="1"
    #include <stdio.h>

    void display() {

        printf("%d\n", glo);
    }

    int main() {

        display();
        glo = 10;
        display();
    }
    ```

    Em qual linha do código anterior você deve declarar a variável `glo` para que ela seja global?

    - [x] Linha 2
    - [ ] Linha 4
    - [ ] Linha 7
    - [ ] Linha 9

    !!! answer
        Para uma variável ser global ela deve ser declarada fora de funcão, ==mas atencão!== Você deve declarar a variável antes do seu uso, senão terá erro de compilacão. O exemplo a seguir não compilaria:

        ```c linenums="1" hl_lines="6"
        /* --- Exemplo incorreto --- */
        #include <stdio.h>

        void display() {
            /* glo é utilizado antes de ser declarado */
            printf("%d\n", glo);
        }

        /* --- ERRADO! --- */
        int glo = 10;

        int main() {

            display();
            glo = 10;
            display();
        }
        ```

!!! info
    Trabalhar com variáveis globais em C não é tarefa fácil e pode ser particularmente complicado quando o programa é separado em vários arquivos `.c` e `.h`. Nesses casos talvez você precise usar o *keyword* [extern](https://en.wikipedia.org/wiki/External_variable).

!!! warning
    Evite usar variáveis globais! Elas são difíceis de gerenciar. O exemplo anterior pode ser reescrito para:

    ```c
    void inc (int *counter) {
        (*counter)++;
    }

    void dec (int *counter) {
        (*counter)--;
    }
    ```

## Variáveis locais

São as variáveis declaradas dentro das funções. Elas são alocadas quando a função é chamada e a região de memória é liberada quando a função retorna.

- As variáveis locais não podem ser modificadas por outras funções!

No exemplo a seguir, iremos declarar duas variáveis locais em duas funções distintas:

```c
int foo (void) {
    int var0 = 2;
    return a;
}

int bar (void) {
    int var1 = 3
    return a;
}
```

Notem que:

- `var0` é apenas visível para a função `foo`
- `var1` é apenas visível para a função `bar`
- As variáveis só são criadas quando a função é chamada.

!!! exercise text short
    Qual saída esperada do programa a seguir?

    ```c
    int counter = 5;

    void foo (void) {
        int counter = 2;
        printf("%d", counter);
    }

    void main (void) {
        foo();
    }
    ```

    !!! answer
        Nesses casos a variável local tem preferência e a saída do programa seria: `2`.

!!! exercise choice
    ```c
    void get_temp (int *temp) {
        _arduino_get_temp(temp);
    }

    void main (void) {
        int *temp;
        get_temp(temp)
    }
    ```

    A variável `temp` do código anterior é:

    - [x] local da main.
    - [ ] glo pois foi declarada na main.
    - [ ] local da get_temp.


    !!! answer
        Em C o `main` é uma funcão como qualquer outra! Uma variável declarada dentro dela é visível apenas para a funcão main, a não ser que seja passada como referência como no exemplo anterior.

        Mas a variável continua sendo local da funcão main.

## Parâmetros formais

São tratados como variáveis locais e possuem precedência sobre as variáveis globais, como demonstrado no exemplo a seguir.

```c
int counter = 5;

int foo (int counter) {
    return counter;
}

void main (void) {
    int tmp = foo(2);
    printf("%d", tmp);
}
```

A saída do programa é ==2==.

!!! exercise choice two-cols ":star: QA1"
    O código a seguir apresenta uma função que adiciona cinco a um número. Essa função é chamada pelo main

    ```c

    int somaCincoAoNum (int n) {
        int c = 0;
        // Insira o código aqui
        return c;
    }

    int main () {
        int x = 0;
        x = somaCincoAoNum (x);
        return 0;
    }
    ```

    O código correto a ser inserido no ==Insira o código aqui== é?

    - [ ] `scanf (%d, &n)`
    - [ ] `n = n + 5`
    - [x] `c = n + 5`
    - [ ] `c = x + 5`


!!! exercise choice ":star: QA2"
    O código a seguir apresenta a função subtrairNumeros, que realiza a subtração de dois números inteiros. Essa função é chamada pelo main:

    ```c
    int subtrairNumeros (int b, int a) {
       int c = 0;
       c = b – a;
       return c;
    }

    int main () {
       int a = 20;
       int b = 10;
       // Insira o código aqui
       printf ("20 – 10 = %d", c);
       return 0;
    }
    ```

    O código correto a ser inserido na linha ==Insira o código aqui== é:

    - [x]
    ```
    int c = subtrairNumeros (a, b);
    ```
    - [ ]
    ```
    int c = subtrairNumeros (b, a);
    ```
    - [ ]
    ```
    subtrairNumeros (a, b);
    ```
    - [ ]
    ```
    c = subtrairNumeros (a, b);
    ```
    - [ ]
    ```
    int c = subtrairNumeros (b-a, a);
    ```


!!! exercise choice ":star: QA3"
    Considere a seguinte função main, que exibe o resultado de `2a - b` se `a >= b` e exibe `b – a` caso contrário. A função func é utilizada para gerenciar as subtrações.

    ```c
    1.  int func(int d, int e){
    2.    // Insira o código aqui
    3.    return d − e;
    4.  }
    5.
    6.  int main(){
    7.    int a = 5;
    8.    int b = 7;
    9.    int r;
    10.   if (a >= b){
    11.      // Insira o código aqui
    12.   }
    13.   else {
    14.      r = func(b, a);
    15.   }
    16.   printf("%d ", r);
    17.   return 0;
    18. }
    ```

    - [ ]
    ```c
    Linha 2: //Sem código.
    Linha 11: r = func(a, 2*b);
    ```
    - [ ]
    ```c
    Linha 2: //Sem código
    Linha 11: func(2*a, b);
    ```
    - [ ]
    ```c
    Linha 2: scanf("%d %d", &d, &e);
    Linha 11: r = func(2*a, b);
    ```
    - [ ]
    ```c
    Linha 2: d = 2 * a;
    Linha 11: r = func(a, b);
    ```
    - [x]
    ```c
    Linha 2: //Sem código
    Linha 11: r = func(2*a, b);
    ```

!!! exercise choice two-cols ":star: QA4"
    Considere o seguinte código:

    ```c
    1. int main(){
    2    int x = 10;
    3.   printf("x é %d ", x);
    4.   x = somaDez(x);
    5.   printf("x mais 10 é %d ", x);
    6.   return 0;
    7. }
    ```

    Uma implementação correta da função somaDez seria:

    - [ ]
    ```c
    int somaDez (int n) {
      scanf ("%d", &n);
      return n + 10;
    }
    ```
    - [x]
    ```c
    int somaDez (int n) {
      n = n + 10;
      return n;
    }
    ```
    - [ ]
    ```c
    void somaDez (int n) {
      n = n + 10;
    }
    ```
    - [ ]
    ```c
    int somaDez (int n) {
      int nMaisDez = n;
      return nMaisDez;
    }
    ```

!!! exercise choice ":star: QA5"
    Um exemplo de programa que lê dois valores (`a e b`) e exibe na tela o resultado da subtração `a – b` é:

    - [ ]
    ```c
    void subtracao (int a, int b, int r) {
      r = a - b;
    }

    int main(){
      int a, b, r;
      scanf("%d %d", &a, &b);
      subtracao(a, b, r);
      printf("a – b = %d", r);
      return 0;
    }
    ```
    - [ ]
    ```c
    int subtracao (int a, int b) {
      return a - b;
    }

    int main(){
      int a, b, r;
      scanf ("%d %d", &a, &b);
      r = subtracao(b, a);
      printf("a – b = %d", r);
      return 0;
    }
    ```
    - [x]
    ```c
    int subtracao (int n1, int n2) {
      return n1 - n2;
    }

    int main(){
      int a, b, r;
      scanf("%d %d", &a, &b);
      r = subtracao(a, b);
      printf("a – b = %d", r);
      return 0;
    }
    ```
    - [ ]
    ```c
    int subtracao (int a, int b) {
      return a - b;
    }

    int main(){
      int a, b, r;
      scanf("%d %d", &a, &b);
      subtracao(a, b);
      printf("a – b = %d", r);
      return 0;
    }
    ```
    - [ ]
    ```c
    int subtracao (int a, int b) {
      return a - b;
    }

    int main(){
      int a, b, r;
      scanf("%d %d", &a, &b);
      r = subtracao(a - b, b);
      printf("a – b = %d", r);
      return 0;
    }
    ```
