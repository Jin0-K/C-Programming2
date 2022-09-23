// Convert the hexadecimal string to the decimal integer

#include <stdio.h>

int htoi(char s[]){
	int i = 0, n = 0;

	while (s[i] != '\0'){
		if ((s[i] >= '0') && (s[i] <= '9')){
			n = 16 * n + (s[i] - '0');
		}
		if ((s[i] >= 'A')  && (s[i] <= 'F')){
			n = 16 * n + (s[i] - 'A' + 10);
		}
		else if ((s[i] >= 'a') && (s[i] <= 'f')){
			n = 16 * n + (s[i] - 'a' + 10);
		}
		i++;
	}
	return n;
}

int main(void){
	char h[] = "12AF";
	
	printf("%s\n", h);
	printf("%x\n", htoi(h));
	printf("%d\n", htoi(h));

	return 0;
}
	
