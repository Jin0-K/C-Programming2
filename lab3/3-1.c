// Subtraction of two input nums

#include <stdio.h>

int main(void) {
	int i, j;

	printf("Enter 1st integer: ");
	scanf("%d", &i);
	printf("Enter 2nd integer: ");
	scanf("%d", &j);
	
	if (i > j) {
		printf("%d - %d = %d\n", i, j, i-j);
	}
	else {
		printf("%d - %d = %d\n", j, i, j-i);
	}

	return 0;
}


