#include <stdio.h>
#include <stdlib.h>

int main(void) {
	for (int i = 0; i < 4; i++) {
		printf("%3d", rand() % 10);
	}
	printf("\n");

	return 0;
}
