// Print which day of the year it is


#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


// set day of year from month & day
int day_of_year(int year, int month, int day) {
	int i, leap;
	
	// leap is 0 if the statement is false
	leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
	
	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}
	return day;
}

// set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
	
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
		*pmonth += 1;
		*pday = yearday;
	}
}


int main(void) {
	int date[3][3] = {{2021, 4, 30}, 
		          {2014, 4, 16},
	                  {2021, 0, 200}};
	
	for (int i = 0; i < 2; i++) {
		int days = day_of_year(date[i][0], date[i][1], date[i][2]);
		printf("%d.%d.%d is the %dth day of the year\n", 
				date[i][0], date[i][1], date[i][2], days);
	}
	
	month_day(date[2][0], date[2][2], *(date+2)+1, *(date+2) + 2);
	
	printf("The 200th day of 2021 is %d.%d.%d\n", 
			date[2][0], date[2][1], date[2][2]);

	return 0;
}
