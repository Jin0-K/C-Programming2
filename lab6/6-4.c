// binary tree
// Compose binary tree using struct tnode and print words and count in alphabet sequence


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCH 120
#define BUFSIZE 120

int buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;




// tree node
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};



// make a tnode
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

// add a node with w, at or below p
struct tnode *addtree(struct tnode *p, char *w) {
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w); // make a duplicate of w
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
	}
	else if (cond < 0) {
		p->left = addtree(p->left, w);
	}
	else {
		p->right = addtree(p->right, w);
	}

	return p;
}

// in-order print of tree p
void treeprint(struct tnode *p) {
	
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

// push character back on input
void ungetch(char *c) {

        if (bufp >= BUFSIZE) {
                printf("ungetch: too many characters\n");
        }
        else {
                for (int i = 0; *(c+i) != '\0'; i++) {
                        buf[bufp++] = *(c+i);
                }
        }
}

// get next word or character from input
int getword(char *word, int lim) {
        int c;
        char *w = word;

        while (isspace(c = getchar()));

        if (c != EOF) {
                *w++ = c;
        }
        if (!isalpha(c)) {
                *w = '\0';
                return c;
        }

        for (; --lim > 0; w++) {
                if (!isalnum(*w = getchar())) {
                        ungetch(w);
                        break;
                }
        }
        *w = '\0';

        return word[0];
}


int main(void) {
	struct tnode *root;
	char str[MAXCH];

	root = NULL;

	while (getword(str, MAXCH) != EOF) {
		
		if (isalpha(str[0])) {
			root = addtree(root, str);
		}
	}
	treeprint(root);

	return 0;
}

