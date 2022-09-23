// Calculate input string formula

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
	char line;
	char str[50];
	int i = 0, j = 0, fp = 0;
	char strn1[20], strn2[20], op;

	while ((line = getchar()) != EOF) {
		str[i++] = line; // Put input line to str
		if (line == '\n') {
			// When the character is num
			for (i = 0, j = 0; isdigit(str[i]) || str[i] == '.';) { 
			   	strn1[j++] = str[i++];
				if (str[i] == '.') {
					fp = 1;
				}
			}
			strn1[j] = '\0';

			for (; str[i] == ' '; i++); // Skip the blank
			
			op = str[i++];
			
			for (; str[i] == ' '; i++); // Skip the blank
			
			for (j = 0; isdigit(str[i]) || str[i] == '.'; ) {
				strn2[j++] = str[i++];

				if (str[i] == '.') {
					fp = 1;
				}
			}

			strn2[j] = '\0';

			printf("Result: ");
			switch (op) {
				case ('+') :
					if (fp) {
						printf("%f\n", strtod(strn1, NULL) + atof(strn2));
						break;
					}
					else {
						printf("%ld\n", strtol(strn1, NULL, 10) + atoi(strn2));
						break;
					}
				case ('-') :
					if (fp) {
						printf("%f\n", strtod(strn1, NULL) - atof(strn2));
						break;
					}
					else {
						printf("%ld\n", strtol(strn1, NULL, 10) - atoi(strn2));
						break;
					}
				case ('*') :
					if (fp) {
						printf("%f\n", strtod(strn1, NULL) * atof(strn2));
						break;
					}
					else {
						printf("%ld\n", strtol(strn1, NULL, 10) * atoi(strn2));
						break;
					}
				case ('/') :
					if (fp) {
						printf("%f\n", strtod(strn1, NULL) / atof(strn2));
						break;
					}
					else {
						printf("%ld\n", strtol(strn1, NULL, 10) / atoi(strn2));
						break;
					}
				case ('%') :
					printf("%ld\n", strtol(strn1, NULL, 10) % atoi(strn2));
					break;
					
			}

			i = 0; fp = 0;

		}
	}
	return 0;
}
