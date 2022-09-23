/*
 * Read the file which is given in command-line argument
 * Print the number of lines, words and characters, and the name of the file
 */

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	FILE *pfile;

	pfile = fopen(argv[1], "r");

	if (pfile == NULL) {
		printf("ERROR: Unable to open the file\n");
		exit(3);
	}
	
	char text = fgetc(pfile);
	int line = 0; // the number of lines
	int word = 0; // the number of words
	int character = 0; // the number of characters

	while (text != EOF) {
		printf("%c", text);

		if (text == ' ') {
			word++;
		}
		else if (text == '\n') {
			line++;
			word++;
		}
		character++;
		text = fgetc(pfile);
	}
	fclose(pfile);

	// Print the value of each variable and the name of the file
	printf("%d %d %d %s\n", line, word, character, argv[1]);

	return 0;
}



