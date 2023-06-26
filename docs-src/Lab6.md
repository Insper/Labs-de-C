# Lab 6 - Juntando tudo


!!! info
    Este roteiro não apresenta nenhum conceito novo. Vocês podem fazê-lo apenas com o que já foi apresentado nos roteiros anteriores. Se você está precisando consultar materiais extras é um sinal de que sua solução é complicada demais.

!!! info
    Você deve fazer tudo do zero. Não há nenhum esqueleto.

!!! tip
    Valide visualmente cada exercício antes de prosseguir.

Vamos neste roteiro revisar os conceitos dos dois roteiros anteriores fazendo modificações para tornar seu programa mais legível e organizado.

!!! exercise
    Crie um struct `imagem` que representa uma imagem, como as usadas no Lab1. Esse struct deve ter:

    * um número que representa a largura da imagem;
    * um número que representa a altura da imagem;
    * uma matriz de números que representa os valores dos pixels da imagem.

    Por simplicidade, você pode supor que nenhuma imagem usada será maior que 640x480.

!!! exercise
    Crie uma função `le_imagem` que carrega o conteúdo de uma imagem PGM, recebida pelo
    terminal (lembre que no Lab3 vimos como simular a digitação do terminal através
    de um arquivo), em um struct `imagem`. Abra o arquivo `cat.pgm` em um editor de
    texto para entender o formato PGM.

    **Dica:** A função deve receber um apontador para um struct `imagem` e preencher
    esse struct. Isso significa que o struct não é criado pela própria função, mas
    por quem *chamou* a função.

!!! exercise
    Crie uma função `escreve_imagem` que recebe um apontador para um struct `imagem`
    e imprime o conteúdo desse struct no terminal, no formato PGM

    **Dica:** Para testar, lembre que no Lab3 vimos como redirecionar os prints
    para um arquivo.

!!! exercise
    Crie uma função `limiar` que *limiariza* um struct `imagem` (tarefa 3 do Lab1).

    **Dica:** para testar, use `le_imagem` e `escreve_imagem`.

!!! warning
    Valide sua implementação com os professores ou um colega validado antes de seguir.

## Exercícios avançados

!!! exercise
    **Crop**: crie uma função `crop` que corta uma imagem. Sua função deverá receber dois structs `imagem`: um para a imagem original e outra para a imagem cortada.

!!! exercise
    **Borramento**: crie uma função *blur* que faz o borramento de uma imagem. Ela deverá receber dois structs `imagem`: um contendo a imagem original e um que receberá a imagem processada. Para borrar a imagem compute, para cada ponto, a média entre seu valor e o valor de seus vizinhos (incluindo diagonais).

!!! exercise
    **Detector de bordas**: você pode detectar bordas em uma imagem computando, para cada ponto, a diferença entre 4 vezes seu valor e o valor dos seus vizinhos (sem incluir diagonais).
