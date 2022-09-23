// Get three integers and put them into function 'max' and 'min'
// Print the value returned from those two functions

#include <stdio.h>

int max(int i, int j, int k) {
	if (i > j) {
		if (i > k) {
			return i;
		}
		else {
			return k;
		}
	}
	else {
		if (j > k) {
			return j;
		}
		else {
			return k;
		}
	}
}

int min(int i, int j, int k) {
	if (i < j) {
		if (i < k) {
			return i;
		}
		else {
			return k;
		}
	}
	else {
		if (j < k) {
			return j;
		}
		else {
			return k;
		}
	}
}

int main(void) {
	int i = 10;
	int j = 20;
	int k = -30;

	printf("Min value is %d\n", min(i, j, k));
	printf("Max value is %d\n", max(i, j, k));

	return 0;
}
