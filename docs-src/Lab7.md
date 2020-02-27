# Lab 7 - Manipulando bits

!!! warning
    Esse lab deve ser realizado no Linux.

Na linguagem `C` a menor unidade de armazenamento existente é a do `char`, que possui 8 bits. Mesmo sendo considerada de 'baixo nível' não possuímos uma maneira 'built-in' na linguagem de armazenar e/ou processar um único `bit`. Alguns compiladores para sistemas embarcados fornecem um tipo bit, porém isso é exclusivo dessas plataformas.

!!! note
    No ARM possuímos os seguintes tipos definidos:
    
    | type              | Size in bits | natural alignment in bytes |
    | ------------      | ------------ | -------------------------- |
    | char              |            8 | 1   (byte-aligned)         |
    | short             |           16 | 2   (halfword-aligned)     |
    | int               |           32 | 4   (word-aligned)         |
    | long              |           32 | 4   (word-aligned)         |
    | long long         |           64 | 8   (doubleword-aligned)   |
    | float             |           32 | 4   (word-aligned)         |
    | double            |           64 | 8   (doubleword-aligned)   |
    | long double       |           64 | 8   (doubleword-aligned)   |
    | All pointers      |           32 | 4   (word-aligned)         |
    | _Bool (C only[a]) |            8 | 1   (byte-aligned)         |
     
    [a] **stdbool.h can be used to define the bool macro in C**.
    
    > fonte: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0491c/Babfcgfc.html

A manipulação de bits é muito importante quando utilizamos a linguagem para: interagir com o hardware; verificar e manipular tipos; otimizações. Os objetivos deste lab são

1. obter familiaridade com as operações bitwise em *C*
2. aplicá-las para resolver problemas envolvendo múltiplas operações
3. usar máscaras de bits para sets bits específicos em um inteiro 32 bits
4. usar máscaras de bits para checar se bits específicos estão ligados

## Começando

O lab está localizado na pasta: `code/07-bits-1/` e contém os seguintes arquivos:

- `exercicios.c`: Arquivo em C que deve ser editado
- `Makefile`: Arquivo de configuração e execução do lab

O lab possui teste unitário para as funções que deverão ser desenvolvidas, para
executar os testes basta abrir o terminal na pasta e executar o comando `make`.

```bash
cd code/07-bits-1/
make
```

Você deve implementar as funções de forma sequencial, sendo a primeira a que aparece no começo do arquivo `exercicio.c`. Leia os comentários do código para entender. 

!!! tip 
    Teste o código para cada função feita, não deixe acumular.

## Submetendo

Ao terminal o lab você deve dar um `push` no seu repositório.

!!! warning
    Todos os testes devem estar passando para considerar a entrega concluída.
