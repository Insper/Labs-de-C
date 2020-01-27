# Lab 5 - juntando tudo

!!! info
    Este roteiro não apresenta nenhum conceito novo. Vocês podem fazê-lo apenas com o que já foi apresentado nos roteiros anteriores. Se você está precisando consultar materiais extras é um sinal de que sua solução é complicada demais. 

Vamos neste roteiro revisar os conceitos dos dois roteiros anteriores fazendo modificações para tornar seu programa mais legível e organizado. 

1. Crie uma estrurura `imagem` para guardar largura, altura e a matriz da imagem. Você pode supor que ela tem tamanho máximo $640\times 480$. 
1. Modifique sua função `le_imagem` que carrega o conteúdo de uma imagem do terminal e escreve em uma estrutura `imagem`. Quais parâmetros sua função recebe?
1. Modifique sua função `escreve_imagem` para receber um tipo `imagem`. Você deve usar apontadores nesta função?
1. Modifique sua função `limiar` para receber um tipo `imagem`. Você deve usar apontadores nesta função?

!!! warning 
    Valide sua implementação com os professores antes de seguir. 

## Exercícios avançados

faça estes exercícios para praticar o uso de ponteiros, estruturas e matrizes.

1. **Crop**: crie uma função `crop` que corta uma imagem. Sua função deverá receber dois tipos `imagem`: um para a imagem original e outra para a imagem cortada. Quais parâmetros sua função deve receber? Você deve usar apontadores?
1. **Borramento**: crie uma função *blur* que faz o borramento de uma imagem. Ela deverá receber dois tipos `imagem`: um contendo a imagem original e um que receberá a imagem processada. Para borrar a imagem compute, para cada ponto, a média entre seu valor e o valor de seus vizinhos (incluindo diagonais).
1. **Detector de bordas**: você pode detectar bordas em uma imagem computando, para cada ponto, a diferença entre 4 vezes seu valor e o valor dos seus vizinhos. 

!!! warning
    Valide visualmente cada exercício antes de prosseguir. 
