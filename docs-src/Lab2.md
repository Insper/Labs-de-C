# Lab 2 - Praticando

| Pasta                | Arquivo  |
|----------------------|----------|
| `code/02-praticando` | `main.c` |

Agora que praticamos um pouco no papel (de novo, habilidade fundamental para
qualquer programador), vamos voltar ao computador.

Vamos começar analisando o código disponível na pasta `code/02-praticando/main.c`

~~~{.c}
    #include <stdio.h>

    int main() {
        printf("Hello World");

        return 0;
    }
~~~

!!! tip
    - Abra o arquivo  `main.c` no seu editor de códigos preferidos
    - Abra um terminal na pasta `code/02-praticando/`
    - Para compilar e executar o programa execute no terminal: `make`

Novamente, temos um código curto mas com vários conceitos importantes:

* a função `main` equivale ao método `main` em Java, ou seja, é a função
  *principal*, chamada quando o programa é rodado;

* diferente de Java, no entanto, essa função é `int` em vez de `void`, pois
  devolve um código que indica se o programa foi bem-sucedido ou não;

* por enquanto, consideraremos apenas a devolução do código `0`, que indica que
  o programa foi, sim,  bem-sucedido;

* `#include` equivale ao `import` em Python e Java, ou seja, amplia o conjunto
  de funcionalidades que o programa pode usar;

* de fato, é justamente por causa do `#include <stdio.h>` que o programa pode
  usar a função `printf`.

* `printf` corresponde à `System.out.print` em Java, ou seja, é a função
  responsável por imprimir texto no terminal.

No entanto, existe uma diferença de uso entre a `printf` do C e a
`System.out.print` do Java. O código abaixo *não* vai funcionar.

~~~{.c}
    #include <stdio.h>

    int main() {
        int n = 1;
        int m = 2;

        printf("Hello World: " + n + ", " + m + "\n");

        return 0;
    }
~~~

A função `printf` usa um sistema de *interpolação* para exibir valores:

~~~{.c}
    #include <stdio.h>

    int main() {
        int n = 1;
        int m = 2;

        printf("Hello World: %d, %d\n", n, m);

        return 0;
    }
~~~

O código acima significa "substitua as duas ocorrências de `%d` pelos valores de
`n` e `m`, pela ordem". Parece complicado, mas note que na verdade é uma sintaxe
mais limpa que a do Java, sem a necessidade de ficar somando strings.

O símbolo a ser substituído é sempre `%` seguido de letras que representam o
tipo do valor. A letra `d` (de "decimal") representa `int`, enquanto as letras
`lf` (de "long float") representam `double`.

~~~{.c}
    #include <stdio.h>

    int main() {
        double n = 1.2;
        double m = 2.1;

        printf("Hello World: %lf, %lf", n, m);

        return 0;
    }
~~~

Antes de apresentar outros conceitos, vamos praticar um pouco.


!!! warning 
    Assim como no lab anterior, cada tarefa já tem um arquivo correspondente. Digite `make tarefaN` para compilar e rodar a tarefa `N`.

!!! example
    ```c
    int s;
    int i;

    i = 0;
    while(i < 10) {
        s += i;
        i++;
    }
    ```

    - Esse código **errado** já apareceu no laboratório anterior. Ele deveria
    calcular a soma de `1` a `10`.

    Rode o código corrigido e faça ele imprimir o resultado com `printf()`

!!! example
    ```c
    int s = 0;
    int i;
    i = 1;
    while (i <= 10) {
      s += i / 2;
      i++;
    }
    ```

    - Esse código **errado** já apareceu no laboratório anterior. Ele deveria calcular a
    *metade* da soma dos númereos de `1` a `10`

    Rode o código corrigido e faça ele imprimir o resultado correto

Vamos agora finalmente escrever um programa com interação de usuário!

~~~{.c}
    #include <stdio.h>

    int main() {
        int n;

        printf("Digite um número: ");
        scanf("%d", &n);

        printf("O número digitado é: %d\n", n);

        return 0;
    }
~~~

Enquanto a função `printf` usa o símbolo `%d` para indicar que quer "escrever um
inteiro", a função `scanf` usa o símbolo `%d` para indicar que quer "ler um
inteiro".

Note também uma diferença importantíssima entre `printf` e `scanf`: apenas no
segundo há um `&` antes da variável. Os detalhes técnicos disso serão revelados
na segunda aula de quarta, mas por enquanto mantenha em mente que **se você
esquecer o `&`, o `scanf` não vai funcionar**.

Preparados para um exemplo mais avançado? O próximo mostra de uma só vez:

* inclusão de outra biblioteca além de `stdio.h`;

* definição de uma constante;

* implementação e chamada de uma função própria.

~~~{.c}
    #include <stdio.h>
    #include <math.h>    /* <---- precisa incluir!!! */

    #define PI 3.141592

    void print_trigo(int a) {
        printf("seno: %lf, cosseno: %lf\n", sin(a), cos(a));
    }

    int main() {
        int angle;

        printf("Digite um ângulo em graus: ");
        scanf("%d", &angle);

        print_trigo(angle);

        return 0;
    }
~~~

Vejamos o que há de novo no código:

* adicionamos `#include <math.h>` e, por causa disso, pudemos usar as funções
  trigonométricas `sin` e `cos` para calcular seno e cosseno respectivamente;

* definimos a constante `PI` como sendo o real `3.141592`;

* implementamos e chamamos a função `print_trigo`, que não precisa de `return`
  por ser do tipo `void`;

A diferença entre variáveis e constantes é que, enquanto uma variável é... er...
variável, uma constante é... er... constante, ou seja, não pode ser alterada: o
código `PI = 5` causaria um erro.

Por falar em `PI`, reparou que definimos a constante mas nunca a usamos? Na
verdade, não foi um acidente...

!!! question
    Qual é o problema no código acima? A dica já está dada: para ser resolvido,
    precisamos usar `PI`...

!!! example
    Resolva o problema!

!!! warning ""
    Não continue antes de validar suas respostas com um dos
    professores. Esse tipo de exercício será avaliado ao longo do semestre.


## Exercícios Avançados

Mesmo que não dê tempo de fazer esses exercícios em sala, é muito importante
que você os faça até quarta para desenferrujar programação e praticar C.

!!! example
    Escreva uma função que recebe um inteiro e devolve o *módulo* desse inteiro.

!!! example
    Escreva uma função que recebe quatro inteiros, representando as coordenadas
    de dois pontos no plano cartesiano, e devolve a *distância de Manhattan*
    (pesquise) entre esses pontos. Vocês já fiazeram esse exercício em
    *Desenvolvimento Colaborativo Ágil*.

 Assim como o `for` padrão do Java, o `for` do C não funciona como o `for` do Python.
Na verdade, é apenas um "açúcar sintático" que facilita a escrita de loops:

~~~{.c}
    for(i = 0; i < 10; i++) {
        instrução
        instrução
        ...
    }
~~~

equivale a

~~~{.c}
    i = 0;
    while(i < 10) {
        instrução
        instrução
        ...
        i++;
    }
~~~

Em Java existe o *enhanced for*, que é mais parecido com o `for` do Python, mas
não existe uma equivalência disso em C. Bem-vindos ao baixo nível! Não temos
bolo, mas temos os ingredientes para você fazer um bolo.

!!! example
    Escreva uma função que recebe um inteiro *n* e, para cada inteiro *i* entre
    *1* e *n*, imprime uma string conforme a seguinte regra:

    * "nenhum" se *i* não for múltiplo de *3* nem *5*;

    * "apenas por três" se *i* for múltiplo de *3* mas não de *5*;

    * "apenas por cinco" se *i* for múltiplo de *5* mas não de *3*;

    * "por três e por cinco" se *i* for múltiplo de *3* e *5*.

    Escreva duas versões: uma usando `while`s e outra usando `for`s.

!!! example
    Escreva uma função que recebe um inteiro *n* e imprime uma "arvorezinha"
    conforme a regra abaixo.

    *n = 1*
    ```
         |

    ```
    *n = 2*

    ```
         |
        /|\

    ```
    *n = 3*

    ```
          |
         /|\
        //|\\
    ```
    e assim em diante para *n = 4, 5, 6...*.

