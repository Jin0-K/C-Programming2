// p.62
// Print reverse string of input line

#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(void) {
	char line;
	char str[50];
	int i = 0;

	while ((line = getchar()) != EOF) {
		str[i++] = line;
		
		if (line == '\n') {
			str[i] = '\0';
			reverse(str);
			printf("%s\n", str);
			i = 0;
		}
	}

	return 0;
}
