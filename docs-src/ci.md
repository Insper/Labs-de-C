# CI

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
        x = addFiveToNumber (x);
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

