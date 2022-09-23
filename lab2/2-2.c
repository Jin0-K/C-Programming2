// Print a word once at a line from the ch(string input)
// Print nothing if the 'space'(or '\t', '\n') is input more than twice in a row

#include <stdio.h>

#define SPACE 0
#define CHAR 1

int main(void){
	char ch;
	int state = CHAR;

	printf("Input some characters, then press Ctrl + d\n\n");

	while ((ch = getchar()) != EOF) {
		if (state == CHAR) {

			if (ch == ' ' || ch == '\t' || ch == '\n') {
				state = SPACE;
				putchar('\n');
			}
			else {
				putchar(ch);
			}
		}
		else {
			if (ch != ' ' && ch != '\t' && ch != '\n') {
				state = CHAR;
				putchar(ch);
			}
		}
	}

	return 0;
}

