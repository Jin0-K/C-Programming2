// Print each number and the sum of two input integers which are larger than 0


#include <stdio.h>

int main(void) {
	unsigned long long int num[2];

	scanf("%llu %llu", &num[0], &num[1]);

	// Print each number
	printf("1st integer %llu\n", num[0]);
	printf("2nd integer %llu\n", num[1]);
	// Print the sum of two numbers
	printf("%llu\n", num[0] + num[1]);

	return 0;
}
