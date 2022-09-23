/*
 0 < a <= b <= 10^9
 Print every fi which is a <= fi <= b
*/

#include <stdio.h>


void printFib(unsigned int n1, unsigned int n2) {
	unsigned int fi[2] = {1, 2};
	int i = 0;
	int count = 0;

	// Let the sequence go on until it reaches n1
	while ((fi[0] < n1) || (fi[1] < n1)) {
		fi[i%2] = fi[0] + fi[1];
		i++;
	}
	// Print the value until it gets larger than n2
	while ((fi[0] <= n2) || (fi[1] <= n2)) {
		printf("%u ", fi[i%2]);
		fi[i%2] = fi[0] + fi[1];
		i++;
		count++;
	}
	// print the number of printed value
	printf("\n%d\n", count);
}


int main(void) {
	unsigned int num[2];

	scanf("%u %u", &num[0], &num[1]);
	
	if (num[0] < num[1]) {
		printFib(num[0], num[1]);
	}
	else {
		printFib(num[1], num[0]);
	}

	return 0;
}
