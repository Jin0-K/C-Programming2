// Print ASCII code

#include <stdio.h>

int main(void) {
	for (int i = 33; i < 127; i++) {
		printf("%3d%3X%3c", i, i, i);
		if ((i-2) % 6 == 0) {
			puts("");
		}
	}
	puts("");

	return 0;
}
