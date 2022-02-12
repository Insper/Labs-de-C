# Lab 7 - Escopo de variáveis

- http://linguagemc.com.br/funcoes-e-escopo-de-variaveis/

Em C possuímos três escopos distintos chamados de: **global**, **local** ou **parâmetros formais**, o escopo define as regras de utilização das variáveis de um programa: onde elas são criadas e destruídas e como elas podem ser modificadas (escrita/leitura).

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

    Em qual linha do código anterior você deve declar a variável `glo` para que ela seja global?

    - [x] Linha 2
    - [ ] Linha 4
    - [ ] Linha 7
    - [ ] Linha 9

    !!! answer
        Para uma variável ser glogal ela deve ser declarada fora de funcão, ==mas atencão!!== Você deve declarar a variável antes do seu uso, se não terá erro de compilacão. O exemplo a seguir não compilaria:

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
    void inc (int counter) {
        counter++;
    }

    void dec (int counter) {
        counter--;
    }
    ```

## Variáveis locais

São as variáveis declaradas dentro das funções, e que são alocadas quando a função é chamada e a região de memória liberada quando a função retorna.

- As variáveis locais não podem ser modificadas por outras funções !!!

No exemplo a seguir iremos declarar duas variáveis locais, em duas funções distintas:

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
    void get_temp (int &temp) {
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

São tratados como variáveis locais e possuem precedência sobre as variáveis globais. Como demonstrado no exemplo a seguir:

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

!!! note
    A saída do programa anterior é ==2==.
