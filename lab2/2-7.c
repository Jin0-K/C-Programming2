// Error occurs when command 'gcc -o 2-7 2-7.c'
// So must use '-lm' at the end of the command to compile
// sqrt(i) : returns square root of i

#include <stdio.h>
#include <math.h>

int main(void){

	double i;
	for (i  = 1.0; i <= 10.0; i++){

		printf("SQRT(%.1f) = %.4f\n", i, sqrt(i));
	}
	
	return 0;
}
