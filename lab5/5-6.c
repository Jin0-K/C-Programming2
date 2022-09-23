// echo -r option
// If -r is input, print reverse of the input words
// If not, just print

#include <stdio.h>


int main(int argc, char *argv[]) {
	int i;

	if ((*argv[1] == '-') && (*(argv[1] + 1) == 'r')) {
		for (i = argc - 1; i > 1; i--) {
			printf("%s%s", argv[i], (i-1 > 1) ? " " : "");
		}
	}
	else {
		for (i = 1; i < argc; i++) {
			printf("%s%s", argv[i], (i < argc-1) ? " " : "");
		}
	}
	printf("\n");

	return 0;
}
