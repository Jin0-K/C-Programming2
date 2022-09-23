// 'static' limits the scope of that object to the rest of the source file being compiled
// When it is used in function variable, it makes the variable reamain on the memory even when the function is finished.

#include <stdio.h>

int i = 10;

void f(void) {
	int i = 1;
	printf("i in f() is %d\n", i++); 
	// print internal i
}

void s(void) {
	static int i = 0;
	printf("i in s() is %d\n", i++); 
	// print internal i
}

int main(void){
	for (int j = 0; j < 3; ++j) {
		printf("i in main() is %d\n", i++);
		// print external i
		f();
		// i in function f vanishes as soon as the function finishes
		s();
		// i in function s remains on the memory, unlike i in f
	}
	return 0;
}
