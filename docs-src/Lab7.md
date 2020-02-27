# Lab 7 - Manipulando bits

!!! note
    Esse lab. considera o GCC como compilador.

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

## Rodando o lab

Você deverá modificar o arquivo 

