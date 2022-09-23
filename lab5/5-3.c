// mystrlen() : return the length of the input string
// Compare the return value of strlen() and mystrlen()

#include <stdio.h>
#include <string.h>

int mystrlen(char *s) {
	int i;
	for (i = 0; *(s+i) != '\0'; i++);
	
	return i;
}

int main(void) {
	char *s[] = {"This is Lab5", "Easy C Programming", "Have fun"};

	printf("with strlen()\n");
	int n = (int)(sizeof(s)/sizeof(char *));

	for (int i = 0; i < n; i++) {
		printf("%s %d\n", *(s+i), (int)(strlen(s[i])));
	}
	putchar('\n');

	// print string s and string length using mystrlen() with for loop
	printf("with mystrlen()\n");
	for (int i = 0; i < 3; i++) {
		int len = mystrlen(s[i]);
		printf("%s %d\n", s[i], len);
	}


	return 0;
}
