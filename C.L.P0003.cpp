#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int random(){
	
	int r = rand() % 10;
	return r;
}

void display(double money){
	printf("You have $%0.2lf\n", money);
}

void calculateCash(double *money){
	srand(time(NULL));
	int a = random();
	int b = random();
	int c = random();
	printf("The slot machine shows %d%d%d\n", a,b,c);
	if (a == b && a == c){
		printf("You win the big prize, $10.00!\n");
		*money = *money + 9.75;
	}
	else if (a != b && a != c && b != c){
		printf("Sorry you don't win anything\n");
		*money = *money - 0.25;
	}
	else {
		printf("You win 50 cents!\n");
		*money = *money + 0.25;
	}
}

void saveGame(double money){
	FILE *save;
	save = fopen("save.txt","w");
	fprintf(save,"%.02lf",money);
	fclose(save);
}

void options(double *n){
	int tc;
	char m;
	do {
	if (tc != 2)
		display(*n);
	printf("1. Play the slot machine\n");
	printf("2. Save game\n");
	printf("3. Cash out\n");
	printf("Your choice(1-3): ");
	scanf("%d%c", &tc, &m);
	if (tc == 1)
		calculateCash(n);
	else if (tc == 2){
		saveGame(*n);
		printf("Your money had saved!\n");
	
	}
	else if (tc == 3){
		printf("Thank you for playing! You end with $%.02lf", *n);
	}
	else if (tc > 3)
		printf ("Invalid choice, choose again!\n");
	} while (tc != 3);
}

int main(){
	double money = 10.00;
	double *ip;
	ip = &money;
	
	options(&money);
}
