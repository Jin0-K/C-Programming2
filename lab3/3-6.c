// Print all prime numbers under 200

#include <stdio.h>

// If the num is prime, return 1. If not, return 0
int isPrime(int num) {
	for (int i = 2; i < num/2; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	
	printf("Prime numbers under 200: ");
	
	for (int i = 2; i <= 200; i++) {
		if (isPrime(i)) {
			printf("%d ", i);
		}
	}
	puts("");

	return 0;
}
