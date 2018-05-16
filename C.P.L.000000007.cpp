#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int random(){
	int r = rand() % 6;
	return r;
}

void generateCode(int code[]){
	srand(time(NULL));
	code[0] = random();
	code[1] = random();
	code[2] = random();
	code[3] = random();
	
	printf("The winning board is: %d %d %d %d\n",code[0],code[1],code[2],code[3]);
}
bool checkDigit(int a){
	if (a < 0 || a > 5)
		return true;
	else return false;
}

int checkValid(int a, int b, int c, int d, char c1, char c2, char c3){
	if (c1 != 32 || c2 != 32 || c3 != 32){
		return 1;
	}
	else if (checkDigit(a))
		return 1;
	else if (checkDigit(b))
		return 1;
	else if (checkDigit(c))
		return 1;
	else if (checkDigit(d))
		return 1;
	else return 0;
}

void guess(int guessCode[]){
	int a1,a2,a3,a4;
	char c1,c2,c3,c4;
	int input;
	int check;
	
	do {
		input = scanf("%d%c%d%c%d%c%d%c", &a1,&c1,&a2,&c2,&a3,&c3,&a4,&c4);
		fflush(stdin);
		check = checkValid(a1,a2,a3,a4,c1,c2,c3);
		if (check == 1 || input != 8 || c4 != '\n')
			printf("Invalid Guess, please Guess again!!\n");
	} while ( check == 1 || input != 8 || c4 != '\n');
	guessCode[0] = a1;
	guessCode[1] = a2;
	guessCode[2] = a3;
	guessCode[3] = a4;

}
void ignore(int code[], int pos, int size){
	for (int i = pos; i < size ;i++){
		code[i] = code[i+1];
	}
}

void clone(int dest[], int src[]){
	for (int i = 0; i < 4; i++){
		dest[i] = src[i];
	}
}

int gameplay(int code[], int guessCode[]){
	int code1[4];
	clone(code1,code);
	int perMatch = 0;
	int imPerMatch = 0;
	int index[4];
	for (int i = 0; i < 4; i++){
		if (code1[i] == guessCode[i]){
			if (i ==4 - perMatch)
				break;
			perMatch++;
			ignore(code1,i,4-perMatch);
			ignore(guessCode,i,4-perMatch);
			i--;
		}
	}
	if (perMatch == 4){
		return 1;
	}
	else{
		for (int j = 0; j < 4 - perMatch; j++){
			for (int k = 0; k < 4 -perMatch; k++){
				if (code1[j] == guessCode[k]){
				
					imPerMatch++;
					
					break;
				}
			}
		}
	}
	printf("You have %d perfect matches and %d imperfect matches\n",perMatch,imPerMatch);
}

int main(){
	clock_t start, end;
	int guessTime;
	int code[4] = {5,1,4,5};
	int guessCode[4];
	int check;
	start = clock();
//	generateCode(code);
	do{
	guess(guessCode);
	check = gameplay(code,guessCode);
	guessTime++;
	printf("guessTime=: %d\n",guessTime);
	} while (check != 1 && guessTime <= 10);
	if (check == 1){
		end = clock();
		int second = (int)(end - start)/CLOCKS_PER_SEC;
		
		printf("You have won the game in %d turn(s) and 0:%d", guessTime,second);
	}
	else if (guessTime > 10){
		printf("Sorry, you have exceeded the maximum number of turns, you lose.");
		printf("Here is the winning board: %d %d %d %d",code[0],code[1],code[2],code[3]);
	} 
	


}
