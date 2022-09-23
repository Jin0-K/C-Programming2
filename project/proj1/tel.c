// Make program for management of telephone number


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100



struct iden_info {
	char name[30];
	char phone[20];
	char memo[40];
};


// Initialize list to Zero
void initZero(struct iden_info *list) {
	for (int i = 0; i < MAXSIZE; i++) {
		*((list + i)->name) = '\0';
		*((list + i)->phone) = '\0';
		*((list + i)->memo) = '\0';
	}
}

// Print manual of the program
void printManual(void) {
	printf("How to use\n");
	printf("1. ./tel <word>\n");
	printf("\tSearch for the word in the list\n");
	printf("2. ./tel <option> <contents>\n");
	printf("   Options:\n");
	printf("\t-a : Add data on the list. Need to enter name, phone, and memo.\n");
	printf("\t-d : Delete one of the list\n");
	printf("\t-l : List the contnts of the list. Doesn't need to enter <contents>\n");
}

// Count length of the list
int countList(struct iden_info *list) {
	int len;
	for (len = 0; strlen((list+len)->name); len++);
	
	return len;
}

// Sort the list
void sortList(struct iden_info *list) {
	int idx = 0;
	int listlen = countList(list);
	
	for (int i = 0; i < listlen; i++) {
                for (int j = i + 1; j < listlen; j++) {
                        
			if (strcmp((list+i)->name, (list+j)->name) > 0) {
                                struct iden_info temp;

				// Swap name part
				for (int k = 0; *((list+i)->name + k) != '\0'; k++) {
                                	temp.name[k] = *((list+i)->name + k);
                                        temp.name[k+1] = '\0';
                                }

                                for (int k = 0; *((list+j)->name + k) != '\0'; k++) {
                                        *((list+i)->name + k) = *((list+j)->name + k);
                                        *((list+i)->name + k+1) = '\0';
                                }

                                for (int k = 0; (temp.name[k]) != '\0'; k++) {
                                        *((list+j)->name + k) = temp.name[k];
                                        *((list+j)->name + k+1) = '\0';
				}

				// Swap phone part
				for (int k = 0; *((list+i)->phone + k) != '\0'; k++) {
                                        temp.phone[k] = *((list+i)->phone + k);
                                        temp.phone[k+1] = '\0';
                                }

                                for (int k = 0; *((list+j)->phone + k) != '\0'; k++) {
                                        *((list+i)->phone + k) = *((list+j)->phone + k);
                                        *((list+i)->phone + k+1) = '\0';
                                }

                                for (int k = 0; (temp.phone[k]) != '\0'; k++) {
                                        *((list+j)->phone + k) = temp.phone[k];
                                        *((list+j)->phone + k+1) = '\0';
                                }

				// Swap memo part
				temp.memo[0] = '\0';
				for (int k = 0; *((list+i)->memo + k) != '\0'; k++) {
                                        temp.memo[k] = *((list+i)->memo + k);
                                        temp.memo[k+1] = '\0';
                                }

				*((list+i)->memo) = '\0';
                                for (int k = 0; *((list+j)->memo + k) != '\0'; k++) {
                                        *((list+i)->memo + k) = *((list+j)->memo + k);
                                        *((list+i)->memo + k+1) = '\0';
                                }

				*((list+j)->memo) = '\0';
                                for (int k = 0; (temp.memo[k]) != '\0'; k++) {
                                        *((list+j)->memo + k) = temp.memo[k];
                                        *((list+j)->memo + k+1) = '\0';
                                }
	
                        }
                }
        }

}


// print the certain index of the list
void printLine(int idx,int pidx, struct iden_info *list) {
	printf("%d %s %s %s\n", pidx, (list+idx)->name, (list+idx)->phone, (list+idx)->memo);
}


// Print contents of the list
void printList(struct iden_info *list) {
	int idx = 0;

        // Print the current contents of the list 
        printf("----------------The Address Book---------------\n");

        while (strlen((list+idx)->name)) {
		printLine(idx, idx+1, list);
		idx++;
	}

        printf("------------------------------------------------\n");
}


// clear data in input buffer
void clearLine(void) {
	while (getchar() != '\n');
}


// search the input word in the list and return the number of the entries found
int searchList(struct iden_info *list, char *word) {

	int wordlen = strlen(word);
	int pidx = 1; // index for print
	int idx = 0;
	int exist;

	while (strlen((list + idx)->name)) {
		exist = 0;

		for (int i = 0; i < 30-wordlen+1; i++) {
			if (*((list + idx)->name + i) == '\0') {
				break;
			}

			if (*((list + idx)->name + i) == word[0]) {
				exist = 1;
				for (int j = i+1; (j < 30-wordlen) && (j-i < wordlen); j++) {
					if (*((list + idx)->name + j) != word[j-i]) {
						exist = 0;
						break;
					}
				}
				if (exist) {
					break;
				}
			}
		}
		if (exist) {
			printLine(idx++, pidx++, list);
			continue;
		}

		for (int i = 0; i < 20-wordlen+1; i++) {
			if (*((list + idx)->phone + i) == '\0') {
				break;
			}

			if (*((list + idx)->phone + i) == word[0]) {
				exist = 1;
				for (int j = i+1; (j < 20-wordlen) && (j-i < wordlen); j++) {
					if (*((list + idx)->phone + j) != word[j-i]) {
						exist = 0;
						break;
					}
				}
				if (exist) {
					break;
				}
			}
		}
		if (exist) {
			printLine(idx++, pidx++, list);
			continue;
		}

		for (int i = 0; i < 40-wordlen+1; i++) {
			if (*((list + idx)->memo + i) == '\0') {
				break;
			}

			if (*((list + idx)->memo + i) == word[0]) {
				exist = 1;
				for (int j = i+1; (j < 40-wordlen) && (j-i < wordlen); j++) {
					if (*((list + idx)->memo + j) != word[j-i]) {
						exist = 0;
						break;
					}
				}
				if (exist) {
					break;
				}
			}
		}
		if (exist) {
			printLine(idx++, pidx++, list);
			continue;
		}

		idx++;
	}
	return pidx-1;
}

// Confirm from user
int confirmAdd(void) {
	printf("add? [Y/N]: ");
	char answer = getchar();
	clearLine();
	if ((answer == 'y') || (answer == 'Y')) {
		return 1;
	}
	else {
		return 0;
	}
}

// Add entry to the list
void addEntry(struct iden_info *list, char **entry) {

	int listlen = countList(list);

	if (listlen == MAXSIZE) {
		printf("Error: too much data is in the file\n");
		exit(3);
	}

	printf("%s %s %s\n", entry[0], entry[1], entry[2]);
	if (!confirmAdd()) {
		printf("Not saved\n");
		exit(3);
	}

	// Check if the length of the entry is valid
	for (int i = 0; entry[0][i] != '\0'; i++) {
		if (i >= 30) {
			printf("Error: too long name is input\n");
			exit(3);
		}
		*((list+listlen)->name + i) = entry[0][i];
		*((list+listlen)->name + i+1) = '\0';
	}
	for (int i = 0; entry[1][i] != '\0'; i++) {
		if (i >= 20) {
			printf("Error: too long phone number is input\n");
			exit(3);
		}
		*((list+listlen)->phone + i) = entry[1][i];
		*((list+listlen)->phone + i+1) = '\0';
	}
	if (entry[2] != NULL) {
		for (int i = 0; entry[2][i] != '\0'; i++) {
			if (i >= 40) {
				printf("Error: too long memo is input\n");
				exit(3);
			}
			*((list+listlen)->memo + i) = entry[2][i];
			*((list+listlen)->memo + i+1) = '\0';
		}
	}
	
	FILE *pf = fopen("data.txt", "a+");
	
	fputs((list+listlen)->name, pf);
	fputs(":", pf);
	fputs((list+listlen)->phone, pf);
	fputs(":", pf);
	fputs((list+listlen)->memo, pf);
	fputs("\n", pf);
	fclose(pf);
}

// Ask user which one should be deleted
int confirmDel(int entries, char *word) {
	if (entries <= 0) {
		printf("There is no such entry contains '%s'\n", word);
		exit(3);
	}

	char answer;
	
	printf("which one? ");
	answer = getchar();
	clearLine();
	
	if ((answer - '0') > entries || (answer - '0') < 0) {
		printf("not deleted\n");
		exit(3);
	}
	else {
		answer -= '0';
		return (int)answer;
	}
}


// Delete entry from the file
void deleteEntry(struct iden_info *list, char *word) {

	int listlen = countList(list);
	int found[listlen];
	int entries = 0;

	int wordlen = strlen(word);
        int pidx = 0; // index for print
        int idx = 0;
        int exist;

	// Search for the word from the list
	while (strlen((list + idx)->name)) {
                exist = 0;

                for (int i = 0; i < 30-wordlen+1; i++) {
			if (*((list + idx)->name + i) == '\0') {
				break;
			}

                        if (*((list + idx)->name + i) == word[0]) {
                                exist = 1;
                                for (int j = i+1; (j < 30-wordlen) && (j-i < wordlen); j++) {
                                        if (*((list + idx)->name + j) != word[j-i]) {
                                                exist = 0;
                                                break;
                                        }
                                }
                                if (exist) {
                                        break;
                                }
                        }
                }
                if (exist) {
			found[idx] = 1;
			entries++;
                        printLine(idx++, ++pidx, list);
                        continue;
                }

		for (int i = 0; i < 20-wordlen+1; i++) {
			if (*((list + idx)->phone + i) == '\0') {
				break;
			}

                        if (*((list + idx)->phone + i) == word[0]) {
                                exist = 1;
                                for (int j = i+1; (j < 20-wordlen) && (j-i < wordlen); j++) {
                                        if (*((list + idx)->phone + j) != word[j-i]) {
                                                exist = 0;
                                                break;
                                        }
                                }
                                if (exist) {
                                        break;
                                }
                        }
                }
                if (exist) {
			found[idx] = 1;
			entries++;
                        printLine(idx++, ++pidx, list);
                        continue;
                }

                for (int i = 0; i < 40-wordlen+1; i++) {
			if (*((list + idx)->memo + i) == '\0') {
				break;
			}

                        if (*((list + idx)->memo + i) == word[0]) {
                                exist = 1;
                                for (int j = i+1; (j < 40-wordlen) && (j-i < wordlen); j++) {
                                        if (*((list + idx)->memo + j) != word[j-i]) {
                                                exist = 0;
                                                break;
                                        }
                                }
                                if (exist) {
                                        break;
                                }
                        }
                }
                if (exist) {
			found[idx] = 1;
			entries++;
                        printLine(idx++, ++pidx, list);
                        continue;
                }

                idx++;
        }

	// Save value of the index that will be deleted to delind
	int delind;
	idx = confirmDel(entries, word);

	for (int i = 0; idx; i++) {
		if (found[i] == 1) {
			idx--;
			delind = i;
		}
	}

	// Rewrite the data on the file in sorted order
	FILE *pf = fopen("data.txt", "w+");
	for (int i = 0; i < listlen; i++) {
		// Skip the delete index
		if (i == delind) {
			continue;
		}
		fputs((list+i)->name, pf);
		fputs(":", pf);
		fputs((list+i)->phone, pf);
		fputs(":", pf);
		fputs((list+i)->memo, pf);
		fputs("\n", pf);
	}
	fclose(pf);

}
	


int main(int argc, char *argv[4]) {

	FILE *pfile;
	char text;
	struct iden_info addlist[MAXSIZE];

	initZero(addlist);

	// When execute program without input
	if (argc <= 1) {
		printManual();
		exit(3);
	}

	// Put data of text in addlist
	pfile = fopen("data.txt", "r");

	if (pfile == NULL) {
		printf("Error: Unable to open the file\n");
		exit(3);
	}

	text = fgetc(pfile);

	int i = 0;

	while ((text != EOF) && (i < MAXSIZE)) {

		for (int j = 0; (text != ':') && (j < 30); j++) {
			(addlist+i)->name[j] = text;
			text = fgetc(pfile);
		}
		text = fgetc(pfile);
			
		for (int j = 0; (text != ':') && (j < 20); j++) {
			(addlist+i)->phone[j] = text;
			text = fgetc(pfile);

		}
		text = fgetc(pfile);
			
		for (int j = 0; (text != '\n') && (j < 40); j++) {
			(addlist+i)->memo[j] = text;
			text = fgetc(pfile);

		}
		text = fgetc(pfile);
			
		i++;
	}
	fclose(pfile);

	// Sort addlist
	sortList(addlist);

	// Search
	if (*argv[1] != '-') {
		
		if (!searchList(addlist, argv[1])) {
			printf("no ");
		}
		printf("match found.\n");
		exit(3);
	}
	

	// option
	char opt = argv[1][1];

	// Performance for each option
	switch(opt) {
		// Add 
		case 'a' :
			addEntry(addlist, argv+2);
			printf("Successfully saved\n");
			break;

		
		// Delete
		case 'd' :
			deleteEntry(addlist, *(argv+2));
			printf("Successfully saved\n");
			break;


		// List
		case 'l' :
			printList(addlist);
			break;


		// Wrong option input
		default : 
				
			printf("Error: wrong option input!\n");

	}


	return 0;
}
