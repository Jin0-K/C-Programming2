/*
 * Get an array of words in command-line argument
 * Print in Lexicographical order if no option is input
 * If an option "-r" is input, print in reverse of lexiographical order
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// The compare function for qsort
static int cmpstringp(const void *p1, const void *p2)
       {
           /* The actual arguments to this function are "pointers to
              pointers to char", but strcmp(3) arguments are "pointers
              to char", hence the following cast plus dereference */

           return strcmp(* (char * const *) p1, * (char * const *) p2);
       }

int main(int argc, char *argv[]) {
	int j;

	// When the argument hasn't been input
        if (argc < 2) {
        	fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
        	exit(EXIT_FAILURE);
        }
	
	// When the "-r" option hasn't been input
	if (strcmp(argv[1], "-r")) {
		qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);

	        for (j = 1; j < argc; j++) {
        		printf("%s ", argv[j]);
		}
	}

	// When the "-r" option has input
	else {
		qsort(&argv[2], argc - 2, sizeof(char *), cmpstringp);

	        for (j = 1; j < argc-1; j++) {
        		printf("%s ", argv[argc-j]);
		}
	}

	puts("");
	
	exit(EXIT_SUCCESS);
}

