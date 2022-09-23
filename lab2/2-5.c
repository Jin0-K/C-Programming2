// <limits.h> : determines various properties of the various variable types
// conversion specifiers should match the values to print correctly

#include <stdio.h>
#include <limits.h>

int main(void){
	
	printf("%d %d\n", CHAR_MIN, CHAR_MAX);
	printf("%ld %ld\n", LONG_MIN, LONG_MAX);

	return 0;
}
