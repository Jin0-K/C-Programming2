// Use q_sort to sort the input strings
// Sort in lexciographic order if there is no option
// Sort in numeric order if '-n' is in the option

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 10000

// Functions
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int numcmp(char *, char*);
void q_sort(char *lineptr[], int left, int right, int (*comp)(void *, void *));

// Main
int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;
	
	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
		numeric = 1;
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort(lineptr, 0, nlines-1,
		(int(*)(void*, void*))(numeric ? numcmp : strcmp));
		
		putchar('\n');
		printf("After Sort.\n");
		writelines(lineptr, nlines);
		
		return 0;
	}

	else {
		printf("error: too big input for sort\n");
		return 1;
	}
	return 0;
}

#define MAXLEN 1000

int mygetline(char *, int);
char *alloc(int);


int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p=alloc(len)) == NULL) {
			return -1;
		}
		else {
         		line[len-1] = '\0';
         		strcpy(p, line);
         		lineptr[nlines++] = p;
      		}
	}
	return nlines;
}


void writelines(char *lineptr[], int nlines) {
	while (nlines --> 0) {
		printf("%s\n", *lineptr++);
	}
}


int mygetline(char *s, int lim){
	int c;
	char *t = s;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		*t++ = c;
	}
	if (c == '\n') {
		*t++ = c;
	}
	*t = '\0';
	
	return t - s;
}

#define ALLOCSIZE 1000000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return 0;
	}
}

void afree(char *p){
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	}
}

void q_sort(char *v[], int left, int right, int (*comp)(void *, void *)) {
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) {
		return;
	}
	
	swap(v, left, (left + right)/2);
	last = left;
	
	for (i=left+1; i<=right; i++) {
		if ((*comp)(v[i], v[left]) < 0) {
			swap(v, ++last, i);
		}
	}
	
	swap(v, left, last);
	q_sort(v, left, last-1, comp);
	q_sort(v, last+1, right, comp);
}


void swap(char *v[], int i, int j) {
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


int numcmp(char *s1, char *s2) {
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	
	if (v1 < v2) {
		return -1;
	}
	else if (v1 > v2) {
		return 1;
	}
	else {
		return 0;
	}
} 
