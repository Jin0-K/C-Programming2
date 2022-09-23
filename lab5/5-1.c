// Array, pointer access
// Print array with using index and pointer

#include <stdio.h>

int main(void) {
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;
	int i;

	printf("Index print: [");
	for (i = 0; i < 5; i++) {
		printf(" %d ", a[i]);
	}
	printf("]\n");

	i = 0;

	printf("Pointer print: [");
	while (i < 5) {
		printf(" %d ", *(p + i));
		i++;
	}
	printf("]\n");

	return 0;
}
