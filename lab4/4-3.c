// Print 4 random numbers between 0 to 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 4; i++) {
		printf("%d ", rand()%10);
	}
	printf("\n");
	
	return 0;
}
