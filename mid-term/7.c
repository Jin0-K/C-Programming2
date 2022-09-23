// Factorization of input integer


#include <stdio.h>


int isPrime(int num) {
	if (num < 2) {
		return 0;
	}
	for (int i = 2; i < num; i++) {
		if (!(num % i)) { // if k divides num
			return 0;
		}
	}
	return 1;
}

void factorization(int num, int* result) {
	int i = 0;
	int prime = 2;

	while (1) {
		while (!(num % prime)) { // if num is divisible by prime
			result[i] = prime;
			result[++i] = 0;
			num = num / prime;
		}
		if (num == 1) { // if the factorization is done
			break;
		}

		for (; !isPrime(++prime); );
	}
}

int main(void) {
	int n;
	int result[50];
	
	printf("Input Integer: ");
	scanf("%d", &n);

	factorization(n, result);

	for (int i = 0; result[i] != 0; i++) {
		if (i != 0) {
			printf(" * ");
		}
		printf("%d", result[i]);
	}
	printf("\n");

	return 0;
}


