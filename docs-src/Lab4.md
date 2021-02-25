# Lab 4 - Arrays, Strings e Matrizes

Na última aula trabalhamos com conceitos básicos de  *C* e com tipos de dados simples (inteiros e números fracionários). Hoje veremos as primeiras estruturas complexas em *C*: vetores, matrizes e strings. 

## Arrays em *C*

Criamos *arrays* **de tamanho fixo** em *C* usando a seguinte sintaxe:

~~~{.c}
long A[100];
~~~

Basta adicionar `[]` após o tipo e teremos um array de tamanho constante (i.e. não dependente da entrada do usuário). **Não é possível redimensionar o array**. Depois de declarado ele terá para sempre o mesmo tamanho. 

![Representação de array de `long` na memória](imgs/day4-arrays/mem-array.png)

O acesso a elementos também é bastante simples:

~~~{.c}
printf("%ld\n", A[3]);
~~~

A linha acima imprime o primeiro elemento do vetor. O uso com `scanf` segue a mesma lógica dos tipos simples:

~~~{.c}
scanf("%ld", &vetor[0]);
~~~

!!! question long 
    Simule o código abaixo manualmente e escreva sua saída em um papel!!

    ```c
    #include <stdio.h>

    int main(int argc, char *argv[]) {
        long vetor[5];
        int i;
        
        for(i = 0; i <= 5; i++) {
            if (vetor[i] % 2 == 0) {
                printf("Par! ");
            }
            printf("i: %d, vetor[i]: %ld\n", i, vetor[i]);
        }
        
        return 0;	
    }
    ```

!!! question long 
    O código acima está no arquivo `tarefa1.c`. Compile e execute ele. Os resultados foram os esperados? Se não, você consegue explicar por que eles foram diferentes?

    ??? note "Resposta"
        Como podemos ver, o código compila, mas seu comportamento é indefinido por duas razões:

        1. O vetor não é inicializado com 0 quando é criado. 
        1. A posição `vetor[5]` não é válida e pode resultar na leitura de dados inválidos da memória.

!!! tip
    Diferentemente de outras linguagens, *C* não verifica os índices automaticamente nem inicializa o elementos do vetor com 0. Além disto, não é possível obter o tamanho de um vetor a partir de seu nome.

!!! example
    Conserte o código acima. Você deverá ler as posições do vetor usando `scanf` em um `for` e depois consertar o `for` do exemplo acima para não acessar as posições indevidas. 

    **Sim, seu programa deverá ter dois `for`, um para leitura usando `scanf` que você deverá criar e o outro é o do exemplo acima, que deverá ser consertado.**

    Conserte o código acima no arquivo `tarefa1.c`. Compile e teste sua solução usando `make tarefa1`.

Um ponto importante é que o sistema de tipos não permite a conversão/passagem de vetores do mesmo tipo, mas com tamanhos diferentes. Assim, a função abaixo não aceitaria como argumento a variável `double arr[4]`, pois só aceita vetores de tamanho 3.

~~~{.c}
double soma_3doubles(double arr[3]) {
    double s = 0;
    for (int i = 0; i < 3; i++) {
        s += arr[i];
    }
    return s;
}
~~~

Para fazê-la aceitar vetores de tamanho qualquer poderíamos mudar sua assinatura para não checar o tamanho do vetor e passá-lo como argumento da função. 

~~~{.c}
double soma(double arr[], int n);
~~~

!!! example 
    Trabalharemos com o arquivo `tarefa2.c`. Abra-o e implemente, no local indicado, a função `soma` com a assinatura acima. Lembre-se que em *C* arrays não conhecem seu tamanho, então é de sua responsabilidade acessar somente elementos válidos e checar se o vetor não está vazio (ou seja, `n < 1`)
 
 
!!! question short
    O arquivo usado acima contém vários testes na função `main`. Leia a função `main` e escreva abaixo a notação usada para inicializar um array com valores constantes. Como você inicializaria um vetor de `int` com os valores $0, 2, 3, 2, 5$?

## Strings

Como visto na expositiva, strings são arrays de caracteres sendo que o último elemento da string contém um caractere `'\0'`. Logo, uma string declarada como `char str[100]` pode guardar strings de **até 99** caracteres (mais 1 para o `'\0'`). Se a string tiver comprimento menor o restante das posições simplesmente não é utilizado.

![String é um vetor de `char` terminado em `'\0'`.](imgs/Lab4/mem-str.svg)

!!! note
    Em C podemos usar: `\0`, `NULL`, e `0` para representar a mesma coisa!

!!! tip 
    Uma *string* em *C* nada mais é do que um *array* do tipo `char` cujo último elemento é um `\0`. 
    As duas linhas abaixo tem o mesmo efeito. 
    ```c
    char arr[] = "insper";
    char arr2[] = {'i', 'n', 's', 'p', 'e', 'r', '\0'};
    ```
    Claramente a primeira é muito mais conveniente ;)

!!! question short
     Em *C*, qual a diferença entre `"a"` e `'a'`? 

Para imprimir uma string no terminal basta usar o código `%s` na string de formatação do printf:

~~~{.c}
char str[10] = "world!";
printf("hello %s\n", str);
~~~

Já a leitura de strings é feita usando a função *fgets*, que recebe um array de `char` com tamanho `n` e lê até `n-1` caracteres de um arquivo ou do terminal. *fgets* para quando encher o vetor ou quando encontrar uma quebra de linha `\n`. No exemplo abaixo, `stdin` (*Standard Input*) representa o terminal. 

~~~{.c}
#define STRING_LEN 10          // Tamanho da string 0..9

char str[STRING_LEN];
fgets(str, STRING_LEN, stdin); // precisamos passar o tamanho máximo
                               // + 1 da nossa string. 
~~~

!!! question short
    Para iterar sobre todos os caracteres de uma string precisamos saber seu tamanho? Como podemos fazer isto? **Dica**: reveja a imagem e o exemplo de código do começo da seção.

    ??? note "Solução"
        O último caractere de uma string é sempre `'\0'`! Logo, podemos percorrer os caracteres até que um `'\0'` seja encontrado.

!!! example 
    Crie uma função que:

    1. recebe uma string de tamanho máximo 100
    1. conte o número de vezes que a letra "a" aparece
    1. retorne este valor.

    Implemente no arquivo `tarefa3.c` e teste com `make tarefa3`

!!! example 
    E se fosse necessário contar o número de caracteres "1"? Implemente no arquivo `tarefa4.c` e teste com `make tarefa4`

## Matrizes

Como visto na expositiva, matrizes em *C* nada mais são que vetores colocados um após o outro.

```c
long mat[10][3];

printf("%d", mat[0][2]); /* acessa linha 0, coluna 3 */

scanf("%d", &mat[1][1]); // armazena inteiro digitado na posição 1,5

```

![Representação de matriz de inteiros na memória](imgs/day4-arrays/mem-mat.png)

Perceba que toda a primeira linha é armazenada (contendo 3 `long`s) antes do início da segunda linha. Ou seja, a matriz é armazenada "deitada" na memória, uma linha após a outra.

!!! question short
    Levando em conta que a matriz é guardada como na figura acima, em qual posição da memória estão armazenados os seguintes elementos? Você deve contar a partir do primeiro elemento (`mat[0][0]`).

    * `mat[0][2]`
    * `mat[1][2]`
    * `mat[2][0]` 

!!! warning
    As próximas tarefas devem ser feitas a partir de um arquivo vazio e compiladas usando os conhecimentos que vocês obtiveram no [Lab 3](/Lab3).

!!! example 
    Faça, do zero, um programa que lê uma matriz $5\times 4$ e imprime no terminal a soma de cada uma de suas colunas. 

!!! example 
    Modifique seu programa acima para, além das somas de cada coluna, imprimir também o índice da coluna de maior valor.

## Exercícios 

Agora que já trabalhamos um pouco com *arrays*, *strings* e matrizes está na hora de praticar com exercícios mais complexos. Estes exercícios não são opcionais, sua realização é essencial para cumprir os objetivos do Mutirão. 

### Arrays

!!! example
    Escreva, do zero, um programa que 
 
    1. Leia um inteiro `n` do terminal (número de elementos do vetor)
    1. Leia `n` números fracionários e guardá-los em um array.
    1. Chame uma função para calcular a média do vetor.
    1. Imprima a média calculada.
 
    Seu programa deverá calcular a média usando uma função `avg` escrita por você mesmo e pode supor que `n < 100`. Para facilitar seus testes, escreva dois arquivos de entrada e use `<` para rodar o programa. 

    ==Atenção, em C não podemos fazer isso:==
    ```c
        int s; 
        scanf("%d", &s);
        long vec[s];
    ```
    
    C não suporta alocar memória dinâmica para um vetor. Sugerimos
    vocês criarem um vetor de uma tamanho maior que o usuário
    possa querer usar. Existe uma solução, mas vamos ver mais
    para frente (`malloc`).
    
!!! example
    Modifique seu programa acima para que ele imprima também a variância do vetor. 

### Strings

!!! question long
    Escreva abaixo uma função que recebe uma string como parâmetro e retorna 1 se ela é um palíndromo ou 0 caso contrário.

!!! question medium 
    Um aluno fez a seguinte função para cópia de strings. 

    ~~~{.c}
    void copia_string(char str1[], char str2[]) {
        int i = 0;
        while (str1[i] != '\0') {
            str2[i] = str1[i];
            i++;
        }
    }
    ~~~

    Existem pelo menos dois problemas graves neste código. Você consegue identificá-los? 

!!! example
    Faça, do zero, um programa que leia uma string (tamanho máximo 200) e crie uma nova string trocando toda letra por maiúsculas. Seu programa deverá imprimir a string original e sua versão em maiúsculas. Seu programa deve funcionar para strings contendo números, símbolos, espaços e letras maiúsculas e minúsculas. Consulte a tabela abaixo, se necessário. 

    ![Tabela ASCII com valores em decimal e hexa](http://www.asciichars.com/_site_media/ascii/ascii-chars-landscape.jpg)

### Matrizes

O formato de imagens mais simples existente é o `pgm`, que reprenta uma imagem em níveis de cinza como uma matriz com valores entre 0 (para preto) e 255 (para branco). Seu formato é o seguinte.

~~~
P2
W H
255
.........
~~~

Ou seja, primeiro lemos uma linha com a string "P2", depois dois inteiros `w` e `h` representando a largura e a altura da imagem, depois o valor 255. Então lemos `w * h` valores representando os pixels da imagem. Disponibilizamos várias imagens de exemplo na pasta [/Lab4/exemplos](https://github.com/Insper/Labs-de-C/tree/master/Lab4/exemplos). Vocês podem abrí-las com qualquer editor de texto para ver seu conteúdo. 

!!! warning 
    Nas tarefas abaixo estamos supondo que você usa `<` para passar o conteúdo das imagens exemplo para seu programa no terminal e `>` para salvar o resultado do terminal em uma nova imagem *pgm*.
    
    Exemplo:
    
    ```bash
    $ ./tarega9 < entrada1.pgm
    ```

Para as tarefas abaixo você pode supor que as imagens tem tamanho máximo $512\times 512$. Para deixar seu código mais limpo, defina duas constantes `MAXW` e `MAXH` para guardar estes valores. 

!!! example
    Crie, do zero, um programa que lê o cabeçalho de uma imagem *pgm* (primeiras três linhas) passada no terminal e imprima as dimensões da imagem. Não se esqueça de ler também o número `255` na terceira linha.
    
    Dica, de como ler a primeira linha do arquivo de imagem:
    
    ```c
    // arquivo tarefa9.c
    // 
    // 1. compilar tarefa9.c
    // 2. executar com: ./tarefa9 < entrada1.pgm
    #include <stdio.h>
    
    int main() {
        char linha[100];
        int var;
        
        // header
        fgets(linha, 100, stdin);
        printf(linha);

        // W
        scanf("%d", &var);
        printf("W %d \n", var);

        return 0;
    }
    ```
    
    Agora você pode continuar lendo na sequência com `fgets` ou `scanf`.

!!! example
    Crie uma função `void le_imagem(int mat[MAXH][MAXW], int w, int h)` que lê os valores da matriz da imagem e os escreve em `mat`. 

!!! example
    Crie uma função `void escreve_imagem(int max[MAXH][MAXW], int w, int h)` que escreve o cabeçalho e todos os pixels de uma imagem no terminal seguindo o formato *pgm* descrito acima.

!!! example
    Verifique que seu programa está correto fazendo uma função `main` que simplesmente lê uma imagem e logo em seguida a escreve no terminal. Verifique visualmente que a imagem de saída é igual a original. 

!!! example
    Finalmente, crie uma função `void limiar(int max[MAXH][MAXW], int w, int h, int lim)` que aplica um limiar de 127 na imagem e chame-a na sua função `main`. Verifique visualmente que a imagem de saída é a esperada. 
