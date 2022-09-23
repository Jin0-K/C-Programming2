#include <string.h>

#include <stdlib.h>

#include <ncurses.h>

#define MAX 100



int D(int win_x,int win_y);

void S(int win_x,int win_y);

void A(int win_x,int win_y);

void L(int win_x,int win_y);

void U(int win_x,int win_y);

void H(int win_x,int win_y);

void download_data();

void upload_data();



typedef struct telbook {

    char name[30];

    char phone[20];

    char memo[40];

}telbook;



telbook list[MAX];

int data_cnt=0;



int main()

{

   int win_x;

   int win_y;

   int c_x;

   int c_y;

   int op = 1;

   int gijun = strlen("1. Search");

   char *op1 = "1. Search";

   char *op2 = "2. Add";

   char *op3 = "3. Delete";

   char *op4 = "4. Updata";

   char *op5 = "5. List";

   char *op6 = "6. Help";

   char *op7 = "7. Exit";

  

   initscr();

   cbreak();

   noecho();

   keypad(stdscr,TRUE);

   curs_set(FALSE);

   start_color();

   init_pair(1, COLOR_BLACK,COLOR_WHITE);

   init_pair(2, COLOR_WHITE,COLOR_BLACK);  

   download_data();

   while(1)

   {

      getmaxyx(stdscr, win_y,win_x);

      c_x = win_x/2;

      c_y = win_y/2;

      clear();

      border(0,0,0,0,'+','+','+','+');

      attron(A_BOLD | COLOR_PAIR(2));

      move(3,(win_x-strlen("Select Menu."))/2);

      printw("Select Menu.%d",op);

      attroff(A_BOLD);

      move(8,((win_x-gijun)/2));

      if (op == 1)

      {

         attron(COLOR_PAIR(1));

         printw(op1);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op1);

      move(10,((win_x-gijun)/2));  

      if (op == 2)

      {

         attron(COLOR_PAIR(1));

         printw(op2);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op2);

      move(12,((win_x-gijun)/2));

      if (op == 3)

      {

         attron(COLOR_PAIR(1));

         printw(op3);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op3);

      move(14,((win_x-gijun)/2));

      if (op == 4)

      {

         attron(COLOR_PAIR(1));

         printw(op4);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op4);

      move(16,((win_x-gijun)/2));

      if (op == 5)

      {

         attron(COLOR_PAIR(1));

         printw(op5);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op5);

      move(18,((win_x-gijun)/2));

      if (op == 6)

      {

         attron(COLOR_PAIR(1));

         printw(op6);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op6);

      move(20,((win_x-gijun)/2));  

      if (op == 7)

      {

         attron(COLOR_PAIR(1));

         printw(op7);

         attroff(COLOR_PAIR(1));

      }

      else

         printw(op7);

      switch(getch())

      {

         case KEY_UP:

            if (op == 1)

               op = 7;

            else

               op -= 1;

            break;

         case KEY_DOWN:

            if (op == 7)

               op = 1;

            else

               op += 1;

            break;

         case 10:

            if (op == 1)

            {

               S(win_x,win_y);

            }

            if (op == 2)

            {

               A(win_x,win_y);

            }

            if (op == 3)

            {

               D(win_x,win_y);

           

            }

            if (op == 4)

            {

               U(win_x,win_y);

            }

            if (op == 5)

            {

               L(win_x,win_y);

              

            }

            if (op == 6)

            {

               H(win_x,win_y);

            }

            if (op == 7)

            {

               endwin();

               curs_set(TRUE);
	       system("clear");
               return 0;

            }

            break;



  

      }

      refresh();

   }



   endwin();

   return 0;

}

void download_data()

{

   FILE* fp = fopen("data.txt", "rt");

   char buf[MAX];

   int j = 0;

   data_cnt = 0;

   if (fp != NULL)//파일을 구조체 배열에 저장하는 문장

   {

           while (fgets(buf, MAX, fp) != NULL)

           {

                  char* part = strtok(buf, ":"); //data.txt를 1줄씩 구분자 단위로 자른다

                  int i = 0;

                  while (part != NULL)

                  {

                      switch (i) {//각각을 switch문을 이용하여 구조체 배열에 저장한다

                      case 0:

                             strcpy(list[j].name, part);

                             break;

                      case 1:

                             strcpy(list[j].phone, part);

                             break;

                      case 2:

                             strcpy(list[j].memo, part);

                             break;

                      }  

                      part = strtok(NULL, ":\n");

                      i++;

                  }

              data_cnt++;

              j++;

           }

           rewind(fp);

   }

       fclose(fp);

}

void upload_data()

{

      FILE* fp = fopen("data.txt", "wt");

       for (int i = 0; i < data_cnt; i++)

    {

            fprintf(fp, "%s:%s:%s", list[i].name, list[i].phone, list[i].memo);

            fputc('\n', fp);

         }

   fclose(fp);

}

void A(int win_x,int win_y)

{

   char bufname[20];

       char bufphone[30];

    char bufmemo[40];

   char ch;

   int y,x;

   FILE* fp = fopen("data.txt", "a");

       WINDOW*win_A = newwin(win_y,win_x,0,0);  

   echo();

   cbreak();

   wattron(win_A, COLOR_PAIR(2));

   refresh();

   mvwprintw(win_A,win_y/2-20,(win_x-strlen("input data:"))/2-10,"Input data:");

   wrefresh(win_A);

   getyx(win_A,y,x);

       keypad(win_A, true);

   bufmemo[0] = '\0';

   wscanw(win_A,"%s %s %s", bufname, bufphone, bufmemo);

   mvwprintw(win_A,y+2,(win_x-strlen("input data:"))/2-10,"add[Y/N]");

   wrefresh(win_A);

   wscanw(win_A,"%c",&ch);

       if (ch == 'Y' ||ch == 'y')

       {

           data_cnt++;

           if (bufmemo[0] == '\0')

                  fprintf(fp, "%s:%s:", bufname, bufphone);

           else

                  fprintf(fp, "%s:%s:%s", bufname, bufphone, bufmemo);

        fputc('\n',fp);

    }

    wrefresh(win_A);

    fclose(fp);

    download_data();

}

int D(int win_x,int win_y)

{

       char buf[MAX];

       char get[MAX];

       int line = 0;

       int match[MAX];

       int x,y,a;

       FILE* fp = fopen("data.txt", "rt");

       WINDOW*win_D = newwin(win_y,win_x,0,0);  

   raw();

   echo();

   wattron(win_D, COLOR_PAIR(2));

   refresh();

   mvwprintw(win_D,win_y/2-20,(win_x-strlen("Seach data:"))/2-10,"Seach data:");

   wrefresh(win_D);

   getyx(win_D,y,x);

      

  

       wscanw(win_D,"%s", buf);

       for (int i = 0; i < data_cnt; i++)

       {

           fgets(get, MAX, fp);

           if (strstr(get, buf) != NULL)//해당하는 모든 줄 출력

           {

                  line++;

                  mvwprintw(win_D,y+line*2,(win_x-strlen("Search data:"))/2-10,"%d ", line);

                  mvwprintw(win_D,y+line*2,(win_x-strlen("Search data:"))/2-8,"%s %s %s\n", list[i].name, list[i].phone, list[i].memo);

                  match[line] = i;

           }

       }

       fclose(fp);

       mvwprintw(win_D,y+line*2+2,(win_x-strlen("Search data:"))/2-6,"which one? ");//삭제할 줄을 선택

       wscanw(win_D,"%d", &a);



       if (a <= 0 || a > line)//삭제할 줄이 출력된 줄 내에 없는 경우

           return -1;

       else//그외(입력이 잘된경우) 그 줄을 찾아서 삭제

       {

           for (int i = match[a]; i < data_cnt; i++)

                  list[i] = list[i + 1];

           data_cnt--;

           upload_data();

           return 1;

       }   

}

void S(int win_x,int win_y)

{

       char buf[MAX];

       char get[MAX];

       int line = 0;

   int y,x;

       FILE* fp = fopen("data.txt", "rt");

       WINDOW*win_S = newwin(win_y,win_x,0,0);  

   raw();

   echo();

   wattron(win_S, COLOR_PAIR(2));

   refresh();

   mvwprintw(win_S,win_y/2-20,(win_x-strlen("Search data:"))/2-10,"Search data:");

   wrefresh(win_S);

   getyx(win_S,y,x);

  

   wscanw(win_S,"%s", buf);

       for (int i = 0; i < data_cnt; i++)

       {

           fgets(get, MAX, fp);

           if (strstr(get, buf) != NULL)//해당하는 모든 줄 출력

           {

                  line++;



                  mvwprintw(win_S,y+line*2,(win_x-strlen("Search data:"))/2-10,"%d ", line);

                  mvwprintw(win_S,y+line*2,(win_x-strlen("Search data:"))/2-8,"%s %s %s\n", list[i].name, list[i].phone, list[i].memo);

           }

       }

       if (line == 0)

       {

           mvwprintw(win_S,y+line*2+2,(win_x-strlen("Search data:"))/2-10,"no match found.\n");

       }

       else

       {

           mvwprintw(win_S,y+line*2+2,(win_x-strlen("Search data:"))/2-10,"match found.\n");

       }

   wrefresh(win_S);

   getch();

     fclose(fp);

}

void L(int win_x,int win_y)

{

       char temp[MAX];

       int x,y;

   telbook tmp;

       WINDOW*win_L = newwin(win_y,win_x,0,0);  

   echo();

   wattron(win_L, COLOR_PAIR(2));

   refresh();

   mvwprintw(win_L,win_y/2-20,(win_x-strlen("List data:"))/2-10,"List data");

   wrefresh(win_L);

   getyx(win_L,y,x);

      



       for (int k = data_cnt - 1; k > 0; k--)//버블 정렬을 이용하여 배열을 알파벳 순으로 정렬

       {

           for (int i = 0; i < k; i++)

           {

                  if (strcmp(list[i].name, list[i + 1].name) > 0)

                  {

                      tmp = list[i];

                      list[i] = list[i + 1];

                      list[i + 1] = tmp;

                  }

           }

       }

       for (int lp = 0; lp < data_cnt; lp++)//정렬된 배열을 출력

       {

           mvwprintw(win_L,y+lp*2+2,(win_x-strlen("List data:"))/2-10,"%d %s:%s:%s\n", lp + 1, list[lp].name, list[lp].phone, list[lp].memo);

       }

   wrefresh(win_L);

       download_data();

   getch();

}

void U(int win_x,int win_y)

{

   if (D(win_x,win_y) == 1)

       {

           A(win_x,win_y);

           upload_data();

       }

}

void H(int win_x,int win_y)

{

       int x,y;

   WINDOW*win_H = newwin(win_y,win_x,0,0);  

   echo();

   wattron(win_H, COLOR_PAIR(2));

   refresh();

   mvwprintw(win_H,win_y/2-20,(win_x-strlen("Help"))/2-10,"Help");

   wrefresh(win_H);

   getyx(win_H,y,x);

      

   mvwprintw(win_H,win_y/2-17,(win_x-strlen("This program implements the phone number management program as ncurses."))/2-10,"This program implements the phone number management program as ncurses.");

   mvwprintw(win_H,win_y/2-14,(win_x-strlen("Press the rudder key up and down to change the menu and run with the enter key."))/2-10,"Press the rudder key up and down to change the menu and run with the enter key.");

   mvwprintw(win_H,win_y/2-11,(win_x-strlen("Search is a program that retrieves a string after receiving it."))/2-10,"Search is a program that retrieves a string after receiving it.");

   mvwprintw(win_H,win_y/2-8,(win_x-strlen("Add stores the characters entered according to the data format."))/2-10,"Add stores the characters entered according to the data format.");

   mvwprintw(win_H,win_y/2-5,(win_x-strlen("Delete can delete a string by searching for it and selecting it."))/2-10,"Delete can delete a string by searching for it and selecting it.");

   mvwprintw(win_H,win_y/2-2,(win_x-strlen("Update searches, deletes, and enters one new data."))/2-10,"Update searches, deletes, and enters one new data.");

   mvwprintw(win_H,win_y/2+1,(win_x-strlen("The list displays the data sorted."))/2-10,"The list displays the data sorted.");

   mvwprintw(win_H,win_y/2+2,(win_x-strlen("The sort order is sorted in order of uppercase and then lowercase."))/2-10,"The sort order is sorted in order of uppercase and then lowercase.");

   wrefresh(win_H);

   getch();

}
