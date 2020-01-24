# Lab 4 - Organização de dados

Na última aula trabalhamos com conceitos básicos de  *C* e com tipos de dados simples (inteiros e números fracionários). Hoje veremos as primeiras estruturas complexas em *C*: vetores, matrizes e strings. 

## Introdução

Criamos vetores **de tamanho fixo** em *C* usando a seguinte sintaxe:

~~~{.c}
long vetor[100];
~~~

Basta adicionar `[]` após o tipo e teremos um vetor de tamanho constante (i.e. não dependente da entrada do usuário). **Não é possível redimensionar o vetor**. Depois de declarado ele terá para sempre o mesmo tamanho. O acesso a elementos também é bastante simples:

~~~{.c}
printf("%ld\n", vetor[0]);
~~~

A linha acima imprime o primeira valor do vetor. O uso com `scanf` segue a mesma lógica dos tipos simples:

~~~{.c}
scanf("%ld", &vetor[0]);
~~~

!!! example "Tarefa 1"
    O código abaixo compila? Se sim, qual é sua saída?
    
<div class="include code" language="c" id="exemplos/erro_comum1.c"></div>

!!! example "Tarefa 2"
    O código acima está no arquivo *exemplos/erro_comum1.c*. Compile e execute ele. Os resultados foram os esperados? Se não, você consegue explicar o por que eles foram diferentes?

Como podemos ver, o código compila, mas seu comportamento é indefinido por duas razões:

1. O vetor não é inicializado com 0 quando é criado. 
1. A posição `vetor[5]` não é válida e pode resultar na leitura de dados inválidos da memória.

!!! tip
    Diferentemente de outras linguagens, *C* não verifica os índices automaticamente nem inicializa o elementos do vetor com 0. Além disto, não é possível obter o tamanho de um vetor a partir de seu nome.

Um ponto importante é que o sistema de tipos não permite a conversão/passagem de vetores do mesmo tipo mas de tamanhos diferentes. Assim, a função abaixo não aceitaria como argumento a variável `double arr[4]`, pois só aceita vetores de tamanho 3.

~~~{.c}
double soma(double arr[3]) {
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

!!! example "Tarefa 3"
    Modifique a função `soma` acima para aceitar vetores de qualquer tamanho. Lembre-se que arrays em *C* não conhecem seu tamanho, então é de sua responsabilidade acessar somente elementos válidos e checar se o vetor não está vazio (ou seja, `n < 1`) \vspace{15em}
 
!!! example "Tarefa 4**: Vamos agora juntar vetores com a aula passada e com a leitura de ontem: escreva do zero um programa que
 
1. Leia um inteiro `n` do terminal (número de elementos do vetor)
1. Leia `n` números fracionários e guardá-los em um array.
1. Chame uma função para calcular a média do vetor.
1. Imprima a média calculada.
 
Seu programa deverá calcular a média usando uma função `avg` escrita por você mesmo e pode supor que `n < 100`. Para facilitar seus testes, escreva dois arquivos de entrada e use `<` para rodar o programa. 

!!! example "Tarefa 5"
    Modifique seu programa acima para que ele imprima também a variância do vetor. 


## Strings

Como visto na expositiva, strings são vetores de caracteres sendo que o último elemento da string contém um caractere `'\0'`. Logo, uma string declarada como `char str[100]` pode guardar strings de **até 99** caracteres (mais 1 para o `'\0'`). Se a string tiver comprimento menor o restante das posições simplesmente não é utilizado.

![String é um vetor de `char` terminado em `'\0'`.](imgs/Lab4/mem-str.png){width=250px}

!!! example "Tarefa 6**: Em Python não existe diferença entre "a" e `'a'`. Isto é verdade em *C*? \vspace{5em}

!!! example "Tarefa 7"
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

Existem pelo menos dois problemas graves neste código. Você consegue identificá-los? \vspace{8em}

!!! example "Tarefa 8"
    Escreva abaixo uma função que recebe uma string como parâmetro e retorne quantas vezes o caractere `1` aparece. \vspace{15em} 

!!! example "Tarefa 9"
    Escreva abaixo uma função que recebe uma string como parâmetro e retorna 1 se ela é um palíndromo ou 0 caso contrário. \vspace{13em}

!!! warning "Valide"
    Valide suas soluções com um professor (ou um colega já validado) antes de prosseguir

Vamos agora partir para leitura e escrita de strings no terminal. Para imprimir uma string no terminal basta usar o código `%s` na string passada para o printf:

~~~{.c}
char str[10] = "world!";
printf("hello %s\n", str);
~~~

Já a leitura de strings é feita usando a função *fgets*, que lê uma linha inteira de caracteres a partir de um arquivo ou do terminal. Veja o exemplo abaixo. O último argumento `stdin` representa o terminal.

~~~{.c}
char str[10];
fgets(str, 10, stdin); // precisamos passar o tamanho máximo + 1 da nossa string. 
~~~

!!! example "Tarefa 8"
    Faça, do zero, um programa que leia uma string (tamanho máximo 200) e crie uma nova string trocando toda letra por maiúsculas. Seu programa deverá imprimir a string original e sua versão em maiúsculas. Seu programa deve funcionar para strings contendo números, símbolos, espaços e letras maiúsculas e minúsculas. Consulte a tabela abaixo, se necessário. 

![Tabela ASCII com valores em decimal e hexa](http://www.asciichars.com/_site_media/ascii/ascii-chars-landscape.jpg)

## Matrizes

Vamos agora retomar os exercícios de imgs/Lab4 e trabalhar com matrizes. Como visto na expositiva, matrizes em *C* nada mais são que vetores colocados um após o outro.

![Representação de matriz de inteiros na memória](imgs/Lab4/mem-mat.png)

Seu acesso é feito com a seguinte notação

~~~{.c}
int matriz[10][20];

matriz[0][3] /* acessa linha 0, coluna 3 */

scanf("%d", &matriz[1][5]); // armazena inteiro digitado na posição 1,5 */
~~~

O formato de imgs/Lab4 mais simples existente é o `pgm`, que reprenta uma imagem em níveis de cinza como uma matriz com valores entre 0 (para preto) e 255 (para branco). Seu formato é o seguinte.

~~~
P2
W H
255
.........
~~~

Ou seja, primeiro lemos uma linha com a string "P2", depois dois inteiros `w` e `h` representando a largura e a altura da imagem, depois o valor 255. Então lemos `w * h` valores representando os pixels da imagem. Disponibilizamos várias imgs/Lab4 de exemplo na pasta *exemplos*. Vocês podem abrí-las com qualquer editor de texto para ver seu conteúdo. 

!!! tip
    Nas tarefas abaixo estamos supondo que você usa `<` para passar o conteúdo das imgs/Lab4 exemplo para seu programa no terminal e `>` para salvar o resultado do terminal em uma nova imagem *pgm*.

Para as tarefas abaixo você pode supor que as imgs/Lab4 tem tamanho máximo $512\times 512$. Para deixar seu código mais limpo, defina duas constantes `MAXW` e `MAXH` para guardar estes valores. 

!!! example "Tarefa 9"
    Crie, do zero, um programa que lê o cabeçalho de uma imagem *pgm* (primeiras três linhas) passada no terminal e imprima as dimensões da imagem. Não se esqueça de ler também o número `255` na terceira linha. \vspace{1em}

!!! example "Tarefa 10"
    Crie uma função `void le_imagem(int mat[MAXH][MAXW], int w, int h)` que lê os valores da matriz da imagem e os escreve em `mat`. \vspace{1em}

!!! example "Tarefa 11"
    Crie uma função `void escreve_imagem(int max[MAXH][MAXW], int w, int h)` que escreve o cabeçalho e todos os pixels de uma imagem no terminal seguindo o formato *pgm* descrito acima. \vspace{1em}

!!! example "Tarefa 12"
    Verifique que seu programa está correto fazendo uma função `main` que simplesmente lê uma imagem e logo em seguida a escreve no terminal. Verifique visualmente que a imagem de saída é igual a original. \vspace{1em}
 
!!! example "Tarefa 13"
    Finalmente, crie uma função `void limiar(int max[MAXH][MAXW], int w, int h, int lim)` que aplica um limiar de 127 na imagem e chame-a na sua função `main`. Verifique visualmente que a imagem de saída é a esperada. \vspace{1em}
