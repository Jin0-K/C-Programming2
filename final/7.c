/*
 * Print decimal number in binary form
*/

#include <stdio.h>

#define MAX_STACK_SIZE 100

// Stack
int stack[MAX_STACK_SIZE];
int top=-1;
 
int isEmpty(void){
	if(top < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(){
	if(top >= MAX_STACK_SIZE-1) {
		return 1;
	}
	else {
		return 0;
	}
}
 
void push(int value){
	if(isFull()) {
		printf("Error: Stack is full\n");
	}
	else {
		stack[++top]=value;
	}
}
 
int pop(void){
	if(isEmpty()) {
		printf("Error: Stack is empty\n");
	}
	else {
		return stack[top--];
	}
}


// Print the decimanl number into binary form
void DECtoBIN(int dec) {
	while ((int)(dec) > 1) {
		push(dec % 2);
		dec = (int)(dec / 2);
	}
	push((int)(dec));

	printf("Binary number is: ");
	while (!isEmpty()) {
		printf("%d", pop());
	}
	puts("");
}


int main(void) {
	int decnum;

	// Get the decimal number
	printf("Enter decimal number: ");
	scanf("%d", &decnum);

	DECtoBIN(decnum);

	return 0;
}


