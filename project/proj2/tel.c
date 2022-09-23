// Make program for management of telephone number


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define MAXSIZE 100



struct iden_info {
	char name[30];
	char phone[20];
	char memo[40];
};


void initZero(struct iden_info *list);
int chooseOpt(WINDOW *window, char **options, int optlen);
void getLine(WINDOW *window, char *word, int wordsize, char *msg);
int countList(struct iden_info *list);
void sortList(struct iden_info *list);
void printLine(WINDOW *window, int idx,int pidx, struct iden_info *list);
int confirmUpd(WINDOW *window, int entries, char *word);
void printList(WINDOW *window, struct iden_info *list);
void updateStructMem(WINDOW *window, struct iden_info *list,int structind, int member);
void updateEntry(WINDOW *window, struct iden_info *list);
void updateFile(struct iden_info *list); 
int searchList(WINDOW *window, struct iden_info *list, char *word);
int confirmAdd(WINDOW *window);
void addEntry(WINDOW *window, struct iden_info *list);
int confirmDel(WINDOW *window, int entries, char *word);
void deleteEntry(WINDOW *window, struct iden_info *list, char *word);
void clearWindow(WINDOW *window);
void closeWindow(WINDOW *window);



int main(void) {

        FILE *pfile;
        char text;
        struct iden_info addlist[MAXSIZE];
	char *options[6] = {"Search", "Add", "Delete", "Update", "List", "Exit"};
        
	WINDOW *my_win;
        initscr();
	noecho();
	cbreak();

	// Get the size of the current window
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

        my_win = newwin(yMax, xMax-10, 1, 1); 
  
	wrefresh(my_win);
	
	// Initialize color pair
	start_color();
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_YELLOW, 1000, 900, 0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_color(COLOR_GREEN, 100, 700, 100);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_color(COLOR_RED, 700, 100, 100);
	init_pair(3, COLOR_RED, COLOR_BLACK);

	while (1) {        
		// Put data of text in addlist
        	initZero(addlist);

	        pfile = fopen("data.txt", "r");
	
        	if (pfile == NULL) {
                	wprintw(my_win, "Error: Unable to open the file\n");
	                closeWindow(my_win);
        	        exit(3);
	        }

        	text = fgetc(pfile);

	        int i = 0;

        	while ((text != EOF) && (i < MAXSIZE)) {

                	for (int j = 0; (text != ':') && (j < 29); j++) {
                        	(addlist+i)->name[j] = text;
                        	(addlist+i)->name[j+1] = '\0';
                       		text = fgetc(pfile);
                	}
	                text = fgetc(pfile);

        	        for (int j = 0; (text != ':') && (j < 19); j++) {
                	        (addlist+i)->phone[j] = text;
                	        (addlist+i)->phone[j+1] = '\0';
                        	text = fgetc(pfile);

	                }
        	        text = fgetc(pfile);

                	for (int j = 0; (text != '\n') && (j < 39); j++) {
                        	(addlist+i)->memo[j] = text;
                        	(addlist+i)->memo[j+1] = '\0';
                        	text = fgetc(pfile);

                	}
                	text = fgetc(pfile);

                	i++;
        	}
	        fclose(pfile);

	        // Sort addlist
        	sortList(addlist);

		// Enable keyboard input
		keypad(my_win, true);

	        // option
		int opt = chooseOpt(my_win, options, 6);



		// Performance for each option
        	switch(opt) {
			// Search
			case 0 :
			{
				char searchword[40];
				getLine(my_win, searchword, 40, "Please enter the keyword of what you want to find");
			
				if (!searchList(my_win, addlist, searchword)) {
					wattron(my_win, A_BOLD);
	        	                wprintw(my_win, "no ");
					wattroff(my_win, A_BOLD);
        	        	}
				wattron(my_win, A_BOLD);
        	        	wprintw(my_win, "match found.\n");
				wattroff(my_win, A_BOLD);
			
				break;
			}

	                // Add 
        	        case 1 :
                	        addEntry(my_win, addlist);
	                        break;

        	        // Delete
	                case 2 :
			{
	                        char delword[40];
				deleteEntry(my_win, addlist, delword);
                        	break;
			}

			// Update
			case 3 :
				updateEntry(my_win, addlist);
				break;

        	        // List
                	case 4 :
                        	printList(my_win, addlist);
                        	break;

	                // Exit
        	        default :
                	        endwin();
				system("clear");
				exit(3);

	        }
		clearWindow(my_win);
	}

        return 0;
}




// Initialize list to Zero
void initZero(struct iden_info *list) {
	for (int i = 0; i < MAXSIZE; i++) {
		*((list + i)->name) = '\0';
		*((list + i)->phone) = '\0';
		*((list + i)->memo) = '\0';
	}
}


// Get an option from user
int chooseOpt(WINDOW *window, char **options, int optlen) {
	int choice;
	int highlight = 0;

	wprintw(window, "Choose an option to perform\n");

	while (1) {
		for (int i = 0; i < optlen; i++) {
			if (i == highlight) {
				wattron(window, A_REVERSE);
			}
			mvwprintw(window, i+2, 1, options[i]);
			wattroff(window, A_REVERSE);
		}
		choice = wgetch(window);

		switch (choice) {
			case KEY_UP :
				highlight--;
				// When the highlight get out of range
				if (highlight < 0) {
					highlight = 0;
				}
				break;

			case KEY_DOWN :
				highlight++;
				// When the highlight get out of range
				if (highlight >= optlen) {
					highlight = optlen - 1;
				}
				break;

			default :
				break;
		}
		if (choice == 10) {
			break;
		}
	}
	wclear(window);

	return highlight;
}


// Get an input word from user
void getLine(WINDOW *window, char *word, int wordsize, char *msg) {
	echo();

	wprintw(window, "%s", msg);
	waddstr(window, ": ");
	wrefresh(window);
	wgetnstr(window, word, wordsize - 1);

	noecho();
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
void printLine(WINDOW *window, int idx,int pidx, struct iden_info *list) {
	wattron(window, COLOR_PAIR(1));
	wprintw(window, "%2d  ", pidx);
	wattroff(window, COLOR_PAIR(1));
	wprintw(window, "%s : %s : %s\n", (list+idx)->name, (list+idx)->phone, (list+idx)->memo);
}


// Print contents of the list
void printList(WINDOW *window, struct iden_info *list) {
	int idx = 0;

        // Print the current contents of the list 
	wattron(window, COLOR_PAIR(1));
	wprintw(window, "_____________________The Address Book_____________________\n\n");
	wattroff(window, COLOR_PAIR(1));

        while (strlen((list+idx)->name)) {
		printLine(window, idx, idx+1, list);
		idx++;
	}

	wattron(window, COLOR_PAIR(1));
        wprintw(window, "__________________________________________________________\n");
	wattroff(window, COLOR_PAIR(1));

	wrefresh(window);
}


// Ask user which one should be deleted
int confirmUpd(WINDOW *window, int entries, char *word) {
        if (entries <= 0) {
                wprintw(window, "There is no such entry contains '%s'\n", word);
                closeWindow(window);
                exit(3);
        }

        char answer[3];

        getLine(window, answer, 3, "Which one do you want to modify?(0 is for cancel)");
    
	int ans = atoi(answer);
	if (!ans) {
		wattron(window, A_BOLD);
                wprintw(window, "\nCanceled\n");
		wattroff(window, A_BOLD);

		return 0;
	}

	else if (ans > entries || ans < 1) {
		wattron(window, COLOR_PAIR(3));
		wattron(window, A_BOLD);
		wprintw(window, "Wrong input number\n");
		wattroff(window, COLOR_PAIR(3));
		wattroff(window, A_BOLD);
        
		return -1;	
        }
        else {
                return ans;
        }
}


// Replace the content of the member of the entry
void updateStructMem(WINDOW *window, struct iden_info *list,int structind, int member) {
	int i = 0;

	switch (member) {
		case 0 :
		{
			do {
				// If the user entered nothing
				if (i++ > 0) {
					wprintw(window, "At least one character should be entered.\n");
				}
				getLine(window, (list+structind)->name, 30, "Enter the new name of the entry");
				
			} while(!strlen((list+structind)->name));
			i = 0;

			break;
		}
		case 1 :
		{
			do {
				// If the user entered nothing
				if (i++ > 0) {
						wprintw(window, "At least one character should be entered.\n");
				}
				getLine(window, (list+structind)->phone, 20, "Enter the new phone number of the entry");
			} while(!strlen((list+structind)->phone));
			i = 0;
				
			break;
		}
		case 2 :
		{
			getLine(window, (list+structind)->memo, 40, "Enter the new memo of the entry");
			break;
		}
		default :
			endwin();
			exit(3);
			break;
	}
}
				


// Update an entry
void updateEntry(WINDOW *window, struct iden_info *list) {
	char word[40];
	getLine(window, word, 40, "Enter the keyword of what you want to modify");

	int listlen = countList(list);
        int found[listlen];
        int entries = 0;

        int wordlen = strlen(word);
        int pidx = 0; // index for print
        int idx = 0;
        int exist;

	wprintw(window, "\n");
	wattron(window, A_BOLD);

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
                        printLine(window, idx++, ++pidx, list);
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
                        printLine(window, idx++, ++pidx, list);
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
                        printLine(window, idx++, ++pidx, list);
                        continue;
                }

                idx++;
        }

	wattroff(window, A_BOLD);
	wprintw(window, "\n");

        // Save value of the index that will be updated to updind
        int updind;
	while (1) {
	        idx = confirmUpd(window, entries, word);
		if (!idx) {
			return;
		}
		else if (idx < 0) {
			continue;
		}
		else {
			break;
		}
	}

        for (int i = 0; idx; i++) {
                if (found[i] == 1) {
                        idx--;
                        updind = i;
                }
        }

	while (1) {
		
		// Ask user which part he wants to modify
		char *mod_options[4] = {"NAME", "PHONE NUMBER", "MEMO", "QUIT"};
	
		wclear(window);
		int mod_opt = chooseOpt(window, mod_options, 4);

		if (mod_opt == 3) {
			return;
		}

		updateStructMem(window, list, updind, mod_opt);

		updateFile(list);

		wattron(window, A_BOLD);
		wattron(window, COLOR_PAIR(2));
		wprintw(window, "\nSuccessfully saved\n");
		wattroff(window, A_BOLD);
		wattroff(window, COLOR_PAIR(2));

		clearWindow(window);
	}
}


// Rewrite the data on the file in sorted order
void updateFile(struct iden_info *list) {
        FILE *pf = fopen("data.txt", "w+");
        
	for (int i = 0; strlen((list+i)->name); i++) {
                fputs((list+i)->name, pf);
                fputs(":", pf);
                fputs((list+i)->phone, pf);
                fputs(":", pf);
                fputs((list+i)->memo, pf);
                fputs("\n", pf);
        }
        fclose(pf);	
}


// search the input word in the list and return the number of the entries found
int searchList(WINDOW *window, struct iden_info *list, char *word) {

	int wordlen = strlen(word);
	int pidx = 1; // index for print
	int idx = 0;
	int exist;

	wprintw(window, "\n");
	wattron(window, A_BOLD);

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
			printLine(window, idx++, pidx++, list);
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
			printLine(window, idx++, pidx++, list);
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
			printLine(window, idx++, pidx++, list);
			continue;
		}

		idx++;
	}

	wprintw(window, "\n");
	wattroff(window, A_BOLD);

	return pidx-1;
}


// Confirm from user
int confirmAdd(WINDOW *window) {
	char answer[2];
	getLine(window, answer, 2, "add? [Y/N]: ");

	if ((*answer == 'y') || (*answer == 'Y')) {
		return 1;
	}
	else {
		return 0;
	}
}

// Add entry to the list
void addEntry(WINDOW *window, struct iden_info *list) {

	int listlen = countList(list);

	if (listlen == MAXSIZE) {
		wprintw(window, "Error: too much data is in the file\n");
		closeWindow(window);
		exit(3);
	}

	char name_ent[30];
	char phone_ent[20];
	char memo_ent[40];
	int i = 0;
	do {
		if (i++ > 0) {
			wprintw(window, "At least one character should be entered\n");
		}
		getLine(window, name_ent, 30, "Enter the name");
	} while(!strlen(name_ent));
	i = 0;
	
	do {
		if (i++ > 0) {
			wprintw(window, "At least one character should be entered\n");
		}
		getLine(window, phone_ent, 20, "Enter the phone number");
	} while(!strlen(phone_ent));
	
	getLine(window, memo_ent, 40, "Enter the memo");

	wattron(window, A_BOLD);
	wprintw(window, "\n%s : %s : %s\n", name_ent, phone_ent, memo_ent);
	wattroff(window, A_BOLD);

	if (!confirmAdd(window)) {
		wattron(window, A_BOLD);
		wprintw(window, "\nNot saved\n");
		wattroff(window, A_BOLD);
		return;
	}

	// Put the entry to data.txt
	FILE *pf = fopen("data.txt", "a+");
	
	fputs(name_ent, pf);
	fputs(":", pf);
	fputs(phone_ent, pf);
	fputs(":", pf);
	fputs(memo_ent, pf);
	fputs("\n", pf);
	fclose(pf);
	
	wattron(window, A_BOLD);
	wattron(window, COLOR_PAIR(2));
	wprintw(window, "\nSuccessfully saved\n");
	wattroff(window, A_BOLD);
	wattroff(window, COLOR_PAIR(2));
	
}

// Ask user which one should be deleted
int confirmDel(WINDOW *window, int entries, char *word) {
	if (entries <= 0) {
		wprintw(window, "There is no such entry contains '%s'\n", word);
		closeWindow(window);
		exit(3);
	}

	char answer[3];

	while(1) {
		getLine(window, answer, 3, "Which one do you want to delete?(0 is for cancel)");
	
		int ans = atoi(answer);
		if (!ans) {
			wattron(window, A_BOLD);
                	wprintw(window, "\nCanceled\n");
			wattroff(window, A_BOLD);

			return 0;
		}
	
		else if (ans > entries || ans < 0) {
			wattron(window, A_BOLD);
			wattron(window, COLOR_PAIR(3));
			wprintw(window, "Wrong input\n");
			wattroff(window, A_BOLD);
			wattroff(window, COLOR_PAIR(3));
		}
		else {
			return ans;
		}
	}
}


// Delete entry from the file
void deleteEntry(WINDOW *window, struct iden_info *list, char *word) {

	int listlen = countList(list);
	int found[listlen];
	int entries = 0;

	getLine(window, word, 40, "Enter a keyword of what you want to delete");

	int wordlen = strlen(word);
        int pidx = 0; // index for print
        int idx = 0;
        int exist;

	wprintw(window, "\n");
	wattron(window, A_BOLD);

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
                        printLine(window, idx++, ++pidx, list);
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
                        printLine(window, idx++, ++pidx, list);
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
                        printLine(window, idx++, ++pidx, list);
                        continue;
                }

                idx++;
        }
	
	wprintw(window, "\n");
	wattroff(window, A_BOLD);

	// Save value of the index that will be deleted to delind
	int delind;
	idx = confirmDel(window, entries, word);

	if (!idx) {
		return;
	}

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

	wattron(window, A_BOLD);
	wattron(window, COLOR_PAIR(2));
	wprintw(window, "\nSuccessfully saved\n");
	wattroff(window, A_BOLD);
	wattroff(window, COLOR_PAIR(2));
}


// Clear window if the user presses any key
void clearWindow(WINDOW *window) {

	wattron(window, A_STANDOUT);
	wprintw(window, "\n\nPress any key to Continue");
	wattroff(window, A_STANDOUT);
		
	wrefresh(window);
	getchar();
	wclear(window);
}


// End window if the user press 'q' key
void closeWindow(WINDOW *window) {
	wprintw(window, "\n\n");
	wattron(window, A_STANDOUT);
	wprintw(window, "Press 'q' to exit");
	wattroff(window, A_STANDOUT);
	wrefresh(window);

	while (getchar() != 'q');
	endwin();
}



