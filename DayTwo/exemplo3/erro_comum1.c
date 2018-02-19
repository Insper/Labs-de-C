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
