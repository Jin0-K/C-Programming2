// x % 6 == 1, x % 8 == 5, x % 13 == 10
// Find the closest integer x from 1000

#include <stdio.h>

int subtThousand(int num) { // return |1000 - num|
	if (num < 1000) {
		return 1000 - num;
	}
	else {
		return num - 1000;
	}
}

int main(void) {
	int result = 0;
	int x = 1;

	while (1) {
		if (x % 6 == 1) {
			if (x % 8 == 5) {
				if (x % 13 == 10) {
					if (subtThousand(result) > subtThousand(x)) {
						result = x;
					}
					else {
						break;
					}
				}
			}
		}
		x++;
	}
	printf("The answer is %d\n", result);

	return 0;
}
