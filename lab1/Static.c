#include <stdio.h>

static int i = 100;

void ex(void){
	static int i = 0;
}

int main(void){
	
	int i = 10;
	
	printf("%d\n", i);

	i = i + 1;
	
	printf("%d\n", i);

	return 0;
}

