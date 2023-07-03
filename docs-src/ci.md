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
!!! exercise choice ":star: QB1"
    Considerando o código abaixo:

    ```c
    #include<stdio.h>
    
    void printNumber (int a, int c);
    
    int g = 6;
    
    int main(){
    g = 10;
    int a = 20;
    int b = 30;
    int c = 50;
    int d = 100;
    printNumber (a,b);
    }
    
    void printNumber (int a, int c) {
    int result = a + c;
    result = result + g;
    printf ("Value = %d", result);
    }
    ```

    Qual será o valor exibido no terminal?

    - [x] 
    60
    - [ ] 
    50
    - [ ] 
    O código não será executado, existe um erro na linha 8 e na linha 18: "variable g not declared."
    - [ ] 
    80
    - [ ] 
    Se a linha 18 for alterada para "result = result + d;" o valor exibido no terminal será 150.

!!! exercise choice ":star: QB2"
    No programa abaixo, assuma a existência da função *int existVariable(int var)* :

    A função retorna **1** se *var* existe no escopo (No escopo da chamada da função existVariable), e **0** caso contrário. Essa é uma função especial que sempre **será compilada**, mesmo se a variável *var* não for identificada.

    O código que exibe no terminal "r = 22" é:

    - [ ] 
    ```c
    1. int func(int a, int b){
    2. return a + b + c;
    3. }
    4.
    5. int main(){
    6. int a = 5, b = 7, c = 10;
    7. int r = func (a, b);
    8. printf ("r = %d ", r);
    9. return 0;
    10. }
    ```
    - [x] 
    ```c
    1. int func(int a, int b, int c){
    2. return a + b + c;
    3. }
    4.
    5. int main(){
    6. int a = 5, b = 7, c = 10;
    7. int r = func (a, b, c);
    8. printf ("r = %d ", r);
    9. return 0;
    10. }
    ```
    - [ ] 
    ```c
    1. int func(int a, int b, int c){
    2. return a + b + c;
    3. }
    4.
    5. int main (){
    6. int a = 7, b = 13, c = 2;
    7. int r = func (a, b, b);
    8. printf ("r = %d ", r);
    9. return 0;
    10. }
    ```
    - [ ] 
    ```c
    1. int z = 0;
    2. int func(int a, int b, int c){
    3. z = 1;
    4. return a + b + c;
    5. }
    6.
    7. int main (){
    8. int a = 7, b = 11, c = 4;
    9. int r = func (a, b, c);
    10. r = r + z;
    11. printf ("r = %d ", r);
    12. return 0;
    13. }
    ```
    - [ ] 
    ```c
    1. int z = 0;
    2. int func(){
    3. if (existVariable(z)) {
    4. // z exists in this scope
    5. return -1;
    6. }
    7. else {
    8. // z does not exist in this scope
    9. return 22;
    10. }
    11.
    12. int main (){
    13. int r = func ();
    14. printf ("r = %d ", r);
    15. return 0;
    16. }
    ```

!!! exercise choice ":star: QB3"
    No programa abaixo, assuma a existência da função *int existVariable(int var)* :

    A função retorna **1** se *var* existe no escopo (No escopo da chamada da função existVariable), e **0** caso contrário. Essa é uma função especial que sempre **será compilada**, mesmo se a variável *var* não for identificada.

    O que acontecerá quando o programa abaixo for executado e compilado? 
    
    ```c
    1. int max = 15;
    2. void compare(int a){
    3. if (existVariable(d)) {
    4. a = 100;
    5. }
    6. if (a > max) {
    7. printf("%d is greater than %d ", a, max);
    8. }
    9. else {
    10. printf("%d is not greater than %d ", a, max);
    11. }
    12. }
    13. int main () {
    14. int d = 10;
    15. int a = 20;
    16. max = 25;
    17. compare (d);
    18. }
    ```

    - [ ] `Erro de compilação na linha 6: "A variável max não foi declarada"`
    - [ ] `O programa irá exibir no terminal: "20 is not greater than 25"`
    - [x] `O programa irá exibir no terminal: "10 is not greater than 25"` 
    - [ ] `O programa irá exibir no terminal: "10 is not greater than 15"`
    - [ ] `O programa irá exibir no terminal: "100 is greater than 25"`

!!! exercise choice ":star: QD1"
    Qual dos códigos abaixo imprime corretamente a soma de **todos os inteiros** de 0 a 9?

    - [ ] 
    ```c
    1. int i = 0;
    2. int sum = 0;
    3. while (i < 10) {
    4. sum = sum + i;
    5. i = 1;
    6. }
    7. printf ("The sum is %d", sum);
    ```
    - [ ] 
    ```c
    1. int sum = 0;
    2. for (int i = 0; i <= 9; i++) {
    3. sum = sum + i;
    4. printf ("The sum is %d", sum);
    5. }
    ```
    - [x] 
    ```c
    1. int i = 0;
    2. int sum = 0;
    3. while (i < 10) {
    4. sum += i;
    5. i++;
    6. }
    7. printf ("The sum is %d", sum);
    ```
    - [ ] 
    ```c
    1. int sum = 0;
    2. int array[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    3. int i = 1;
    4. while (i <= 10)
    5. sum = sum + array[i];
    6. i++;
    7. }
    8. printf ("The sum is %d", sum);
    ```
    - [ ] 
    ```c
    1. int sum = 0;
    2. for (int i = 0; i <= 10; i++) {
    3. sum = sum + i;
    4. }
    5. printf ("The sum is %d", sum);
    ```

!!! exercise choice ":star: QD2"
    Por definição, um número n é primo se tiver apenas 2 divisores distintos: 1 e n. Portanto, o número 1 não é primo, mas 2, 3 e 5 são. O algoritmo mais simples (mas não o mais eficiente) para detectar se um número n é primo, é verificar todos os números entre 2 (inclusive ele mesmo) e n -1 procurando algum número que divida n. Na linguagem C, um número **i** divide **n** se o resto
    da divisão de **n** por **i** é 0, ou seja, se **n%i == 0**. 

    A seguinte função isPrime foi projetada para retornar **1** se o número n for primo e **0** se não for:

    ```c
    1. int isPrime (int n) {
    2.
    3. int prime = 1, i;
    4.
    5. if (n < 2) return 0;
    6. if (n == 2) return 1;
    7.
    8. // Insert code here
    9. if (n%i == 0) {
    10. prime = 0;
    11. }
    12. }
    13. return prime;
    14. }
    ```

    O código correto para a linha 8 é:

    - [ ] 
    ```c
    if (n > 2){
    ```  
    - [x] 
    ```c
    for (i = 2; i < n; i++){
    ```  
    - [ ] 
    ```c
    for (i = 2; i < n; i++){
        if (isPrime == 1)
          printf ("Number %d is prime");
        else
          printf ("Number %d is not prime");
    ```  
    - [ ] 
    ```c
    for (i = 2; i <= n; i++){
    ```  
    - [ ] 
    ```c
    for (i = 1; i < n-1; i++){
    ```
!!! exercise choice ":star: QD3"
    Por definição, um número n é primo se tiver apenas 2 divisores distintos: 1 e n. Portanto, o número 1 não é primo, mas 2, 3 e 5 são. O algoritmo mais simples (mas não o mais eficiente) para detectar se um número n é primo, é verificar todos os números entre 2 (inclusive ele mesmo) e n -1 procurando algum número que divida n. Na linguagem C, um número **i** divide **n** se o resto
    da divisão de **n** por **i** é 0, ou seja, se **n%i == 0**. 

    A seguinte função int isDivisible(int a, int b) foi projetada para retornar **1** se o número **a é divisível por b**:

    ```c
    1. int isDivisible(int a, int b) {
    2. if (a % b == 0) return 1;
    3. else return 0;
    4. }
    ```

    O programa abaixo lê um número **n** e exibe se **n é primo ou não**:

    ```c
    1. int main() {
    2. int n;
    3. int i = 2;
    4. // Insert code here
    5. scanf ("%d", &n);
    6. // Insert code here
    7. foundDivisible = isDivisible(n, i);
    8. i++;
    9. }
    10. if (!foundDivisible)
    11. printf("Number %d is prime", n);
    12. else
    13. printf("Number %d is not prime, n);
    14. return 0;
    15. }
    ```

    Considere que o número **n** sempre será igual ou maior que **2**.
    O código correto a ser inserido é:
    
    - [ ] 
    ```c
    4. int foundDivisible = 1;
    6. while (!foundDivisible && i < n) {
    ```
    - [ ] 
    ```c
    4. int foundDivisible = 0;
    6. if (!foundDivisible && i < n) {
    ```
    - [ ] 
    ```c
    4. int foundDivisible = 0;
    6. for (i = 1; i < n-1; i++) {
          if (foundDivisible) break;
    ```
    - [x] 
    ```c
    4. int foundDivisible = 0;
    6. while (!foundDivisible && i < n) {
    ```
!!! exercise choice ":star: QD4"
    O programa a seguir foi projetado para ler dois inteiros, a e b, e imprimir todos os números entre eles. Por exemplo, se a = 5 e b = 10, o programa imprimiria 6,7,8,9, do menor para o maior. Por sua vez, se a=10 e b=5, o programa ainda imprimirá 6,7,8,9.

    ```c
    1. int main() {
    2. int a, b, i, small, large;
    3. scanf("%d %d", &a,&b);
    4. if (a < b) {
    5. small = a;
    6. large = b;
    7. }
    8. else {
    9. small = b;
    10. large = a;
    11. }
    12. // Insert code here
    13. // Insert code here
    14. printf("%d", i);
    15. // Insert code here
    16. }
    17. }
    ```

    O código correto a ser inserido é:
    
    - [x] 
    ```c
    12. i = small + 1;
    13. while (i < large ) {
    15. i++;
    ```
    - [ ] 
    ```c
    12. i = small + 1; 
    13. while (i < large) {
    15. i = a + i;
    ```
    - [ ] 
    ```c
    12. i = a;
    13. while (a < b) {
    15. i = i + 1;
    ```
    - [ ] 
    ```c
    12. i = small;
    13. while (i < large) {
    15. i++;
    ```
    
!!! exercise choice ":star: QD5"
    A implementação correta de um programa desenvolvido para calcular a soma de todos os números de 1 (inclusive ele mesmo) a 10 (inclusive ele mesmo) e imprimir o resultado seria:
    
    - [ ] 
    ```c
    1. int main ( ){
    2. int i = 1;
    3. int sum = 0;
    4. while (i <= 10)
    5. sum = sum + i;
    6. i = 1;
    7. }
    8. printf ("The sum is: %d", sum);
    9. }       
    ```
    - [ ] 
    ```c
    1. int main ( ){
    2. int i = 1;
    3. int sum = 0;
    4. while (i <= 10)
    5. sum = sum + i;
    6. printf ("The sum is: %d", sum);
    7. i = i + 1;
    8. }
    9. printf ("The sum is: %d", sum);
    10. }    
    ```
    - [x] 
    ```c
    1. int main ( ){
    2. int i = 1;
    3. int sum = 0;
    4. while (i < 11)
    5. sum = sum + i;
    6. i = i + 1;
    7. }
    8. printf ("The sum is: %d", sum);
    9. }        
    ```
    - [ ] 
    ```c
    1. int main ( ){
    2. int i = 1;
    3. int sum = 0;
    4. sum = sum + i;
    5. i = i + 1;
    6. printf ("The sum is: %d", sum);
    7. }        
    ```
    - [ ] 
    ```c
    1. int main ( ){
    2. int i;
    3. int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
    4. for (i = 1; i <= 10; i++)
    5. sum = sum + i;
    6. }
    7. printf ("The sum is: %d", sum);
    8. }        
    ```

!!! exercise choice ":star: QE1"
    Considere a **struct**:

    ```c
    1. struct date {
    2. int day;
    3. int month;
    4. int year;
    5. };
    6. typedef struct date Date;
    ```

    Qual é a instrução if correta que verifica se duas variáveis ​​do tipo **Date (dateA e dateB)** tem exatamente a mesma informação?


    - [ ] 
    ```c
    if (dateA == dateB)
    ```
    - [x] 
    ```c
    if (dateA.day == dateB.day 
        && dateA.month == dateB.month 
        && dateA.year == dateB.year)
    ```
    - [ ] 
    ```c
    if (dateA.day == dateB 
        && dateA.month == dateB 
        && dateA.year == dateB)
    ```
    - [ ] 
    ```c
    if (dateB->day == dateA->day 
        && dateB->month == dateA->day 
        && dateB->year == dateA->year)
    ```
    - [ ] 
    ```c
    if (dateB[day] == dateA[day] 
        && dateB[month] == dateA[day]
        && dateB[year] == dateA[year])
    ```

!!! exercise choice ":star: QE2"

    Considere a **struct**:

    ```c
    1. struct student {
    2. int bornDay;
    3. int bornMonth;
    4. int bornYear;
    5. };
    6. typedef struct student Student;
    ```
    Considere as seguintes instruções de declaração de variável:
    ```c
    Student sA;
    Student sB;
    ```

    Qual é o **if** que verifica corretamente se dois estudantes nasceram no mesmo ano?

    - [ ] 
    ```c
    if (Student sA.bornYear == Student sB.bornYear)
    ```
    - [ ] 
    ```c
    if (sA[bornYear] == sB[bornYear])
    ```
    - [ ] 
    ```c
    if (sA->bornYear == sB->bornYear)
    ```
    - [ ] 
    ```c
    if (sA.bornYear == sB)
    ```
    - [x] 
    ```c
    if (sA.bornYear == sB.bornYear)
    ```

!!! exercise choice ":star: QE3"
    Considere o seguinte código:

    ```c
    1. struct student {
    2. int bornDay;
    3. int bornMonth;
    4. int bornYear;
    5. };
    6. typedef struct student Student;
    7.
    8. struct Date {
    9. int day;
    10. int month;
    11. int year;
    12. };
    13. typedef struct date Date;
    14.
    15. Student sA;
    16. Date d1;
    ```
    Qual é a alternativa que contém o **if** que verifica corretamente se o estudante **sA** nasceu no ano contido na variável **d1**?

    - [ ] 
    ```c
    if (d1[year] == sA [year])
    ```
    - [ ] 
    ```c
    if (d1 == sA)
    ```
    - [ ] 
    ```c
    if (sA.bornYear == d1)
    ```
    - [ ] 
    ```c
    if (Student sA.bornYear == Date d1.year)
    ```
    - [x] 
    ```c
    if (sA.bornYear == d1.year)
    ```

!!! exercise choice ":star: QE4"
    Considere o seguinte código:
    ```c
    1. struct date {
    2. int day;
    3. int month;
    4. int year;
    5. };
    6. typedef struct date Date;
    7.
    8. Date d1;
    ```
    Qual é a alternativa que contém o **if** que verifica corretamente se a variável **d1** é maior que 2000?
      
    - [ ] 
    ```c
    if (d1 > 2000)
    ```
    - [ ] 
    ```c
    if (d1 -> year > 2000)
    ```
    - [ ] 
    ```c
    if (struct d1.year > 2000)
    ```
    - [x] 
    ```c
    if (d1.year > 2000)
    ```

!!! exercise choice ":star: QF1"
    Considere o seguinte programa:
    ```c
    1. int main () {
    2. int a = 25, b = 10, resultado = 0;
    3. int* p;
    4. p = &resultado;
    5. subtrai (a, b, p, resultado);
    6. printf ("25 – 10 = %d", resultado);
    7. }
    ```
    Uma implementação correta da função subtrai, que faria o programa acima exibir **25 – 10 = 15 é**:
    
    - [ ] 
    ```c
    1. void subtrai (int a, int b, int* p, int resultado) {
    2. return a – b;
    3. }
    ```
    - [x] 
    ```c
    1. void subtrai (int a, int b, int* p, int resultado) {
    2. *p = a - b;
    3. }    
    ```
    - [ ] 
    ```c
    1. void subtrai (int a, int b, int* p, int resultado) {
    2. resultado = a - b;
    3. }
    ```
    - [ ] 
    ```c
    1. void subtrai (int a, int b, int* p, int resultado) {
    2. p = a - b;
    3. }
    ```
    - [ ] 
    ```c
    1. void subtrai (int a, int b, int* p, int resultado) {
    2. &p = a - b;
    3. }
    ```

!!! exercise choice ":star: QF2"
    O programa que exibe **a + b = 30** na tela é:
    
    - [ ] 
    ```c
    1. void somaValores (int a, int b) {
    2. return a + b;
    3. }
    4.
    5. int main () {
    6. int a = 10, b = 20, soma = 0;
    7. soma = somaValores (a, b);
    8. printf ("a + b = %d", soma);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaValores (int a, int b, int soma) {
    2. soma = a + b;
    3. }
    4.
    5. int main () {
    6. int a = 10, b = 20, soma = 0;
    7. somaValores (a, b, soma);
    8. printf ("a + b = %d", soma);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaValores (int a, int b, int* soma) {
    2. soma = a + b;
    3. }
    4.
    5. int main () {
    6. int a = 10, b = 20, soma = 0;
    7. somaValores (a, b, &soma);
    8. printf ("a + b = %d", soma);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaValores (int a, int b, int* soma) {
    2. &soma = a + b;
    3. }
    4.
    5. int main () {
    6. int a = 10, b = 20, soma = 0;
    7. somaValores (a, b, &soma);
    8. printf ("a + b = %d", soma);
    9. }
    ```
    - [x] 
    ```c
    1. void somaValores (int a, int b, int* soma) {
    2. *soma = a + b;
    3. }
    4.
    5. int main () {
    6. int a = 10, b = 20, soma = 0;
    7. somaValores (a, b, &soma);
    8. printf ("a + b = %d", soma);
    9. }
    ```


!!! exercise choice ":star: QF3"
    Considere o seguinte programa:
    ```c
    1. int main () {
    2. int a = 10;
    3. int* p;
    4.
    5. // Insira o código aqui
    6.
    7. printf (" a = %d", a);
    8. }
    ```
    O código correto a ser inserido na linha 5, que faça com que o programa exiba na tela a = 20 é:

    - [x] 
    ```c
    p = &a;
    *p = a + 10;
    ```
    - [ ] 
    ```c
    p = &a;
    &p = a + 10;
    ```
    - [ ] 
    ```c
    p = &a + 10; 
    ```
    - [ ] 
    ```c
    p = &a;
    *p = p + 10;
    ```

!!! exercise choice ":star: QF4"
    O programa que exibe **resultado = 110** é:

    - [ ] 
    ```c
    1. void somaDez (int* p) {
    2. *p = p + 10;
    3. }
    4.
    5. int main () {
    6. int a = 100;
    7. somaDez (&a);
    8. printf ("resultado = %d", a);
    9. }
    ```
    - [x] 
    ```c
    1. void somaDez (int* p) {
    2. *p = *p + 10;
    3. }
    4.
    5. int main () {
    6. int a = 100;
    7. somaDez (&a);
    8. printf ("resultado = %d", a);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaDez (int* p) {
    2. p = *p + 10;
    3. }
    4.
    5. int main () {
    6. int a = 100;
    7. somaDez (&a);
    8. printf ("resultado = %d", a);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaDez (int* p) {
    2. return *p + 10;
    3. }
    4.
    5. int main () {
    6. int a = 100;
    7. a = somaDez (&a);
    8. printf ("resultado = %d", a);
    9. }
    ```
    - [ ] 
    ```c
    1. void somaDez (int p) {
    2. p = p + 10;
    3. }
    4.
    5. int main () {
    6. int a = 100;
    7. somaDez (a);
    8. printf ("resultado = %d", a);
    9. }
    ```