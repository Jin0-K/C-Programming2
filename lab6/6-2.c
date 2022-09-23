// Pointer to structure

#include <stdio.h>

int main(void) {
	struct node {
		int len;
		char * str;
	};
	struct node a = {10, "test"};
	struct node *p = &a;

	printf("a.len is %d\n", a.len);
	printf("p->len is %d\n", p->len);
	printf("a.str is %s\n", a.str);
	printf("p->str is %s\n", p->str);
	printf("*p->str is %c\n", *p->str);
	printf("p->str++ is %s\n", p->str++);
	printf("a.str is %s\n", a.str);
	
	return 0;
}
