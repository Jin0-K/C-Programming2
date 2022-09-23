// Find the common divisors of two input integers

#include <stdio.h>

int main(void) {
	int n1, n2;
	int dn1[50], dn2[50], result[50];
	int num = 0;

	printf("Enter two integers: ");
	scanf("%d %d", &n1, &n2);

	// find divisors of n1 and n2
	for (int i = 1; i <= n1; i++) {
		if (n1 % i == 0) {
			dn1[num++] = i;
			dn1[num] = -1;
		}
	}
	num = 0;

	for (int i = 1; i <= n2; i++) {
		if (n2 % i == 0) {
			dn2[num++] = i;
			dn2[num] = -1;
		}
	}
	num = 0;

	// Put the common element of dn1 and dn2 to result
	for (int i = 0; dn1[i] > 0; i++) {
		for (int j = 0; dn2[j] > 0; j++) {
			if (dn1[i] == dn2[j]) {
				result[num++] = dn1[i];
				result[num] = -1;
				break;
			}
		}
	}

	// Print result
	printf("Common divisors: ");
	for (int i = 0; result[i] > 0; i++) {
		printf("%d ", result[i]);
	}
	puts(" ");
	
	return 0;
}
