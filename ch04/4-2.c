#include <stdio.h>
#define MAXLINE 100

int main(void) {
	double sum, atof(char []);
	char line[MAXLINE];
	int mygetline(char line[], int max);

	sum = 0;
	while (mygetline(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += atof(line));
	}
	return 0;
}
