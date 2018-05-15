#include <stdio.h>
#include <string.h>
int dayOfYear(int d, int m, int y){
	int s[12];
	if (y % 4 == 0)
		s[1] = 29;
	else
		s[1] = 28;
	s[0] = s[2] = s[4] = s[6] = s[7] = s[9] = s[11] = 31;
	
	s[3] = s[5] = s[8] = s[10]  = 30;
	int day = 0;
	for (int i = 0; i < m-1; i++){
		day += s[i];
	}
	day += d;
	return day;	
}
void dateAndWeek(int d, int m, int y){
	char a[7][20];
	strcpy(a[0], "Monday");
	strcpy(a[1], "Tuesday");
	strcpy(a[2], "Wednesday");
	strcpy(a[3], "Thursday");
	strcpy(a[4], "Friday");
	strcpy(a[5], "Saturday");
	strcpy(a[6], "Sunday");
	int day = dayOfYear(d,m,y);
	int date;
	int week;
	date = day % 7;
	week = day / 7;
	printf("Day of year: %d\n", day);
	if (date == 0)
		printf("Day of week: %s\n", a[6]);
	else
		printf("Day of week: %s\n", a[date-1]);
	printf("Week of year: %d\n", week);	
}
int checkValid(int d, int m, int y, char a, char b){
	int s[12];
	if (y % 4 == 0)
		s[1] = 29;
	else
		s[1] = 28;
	s[0] = s[2] = s[4] = s[6] = s[7] = s[9] = s[11] = 31;
	
	s[3] = s[5] = s[8] = s[10]  = 30;
	if (m > 12 || m <= 0){
		printf("Invalid date, please try again\n");
		fflush(stdin);
		return 1;
	}
	else if (y < 0){
		return 1;
	}
	else if (d > s[m-1] || d < 0){
		return 1;
	}
	else if (a != 47 || b != 47)
		return 1;
	else 
		return 0;
}
int main(){
	int d;
	int m;
	int y;
	char a[2];
	int check;
	int input;
	do {
	printf("please enter a date (dd/mm/yyyy): ");
	input = scanf("%d%c%d%c%d%c",&d,&a[0],&m,&a[1],&y,&a[2]);
	fflush(stdin);
	check = checkValid (d,m,y, a[0], a[1]);
	if (check == 1 || input != 6 || a[2] != '\n')
		printf("Invalid date, please enter again!\n");		
	} while (check == 1 || input != 6 || a[2] != '\n');
	dayOfYear(d, m ,y);
	dateAndWeek(d,m,y);
}
