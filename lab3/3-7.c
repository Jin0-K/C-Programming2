#include <stdio.h>

unsigned long int factorial(int num) {
	unsigned long int result = 1;
	while (num > 1) {
		result *= num--;
	}
	return result;
}

int main(void) {
	printf("20!: ");
	printf("%lu\n", factorial(20));

	return 0;
}
