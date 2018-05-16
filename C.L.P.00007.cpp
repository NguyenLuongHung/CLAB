#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void clone(int dest[], int src[]){
	for (int i = 0; i < 4; i++){
		dest[i] = src[i];
	}
}
void display(int code[]){
	for (int i = 0; i < 4; i++){
		printf("code[%d] = : %d\n", i, code[i]);
	}
}

void ignore(int code[], int pos, int size){
	for (int i = pos; i < size ;i++){
		code[i] = code[i+1];
	}
}

bool check(int code[],int a, int size){
	for (int i = 0 ; i < size; i++){
		if (a == code[i]){
			return true;
		}
	}
	return false;
}

int gameplay(int code[], int guessCode[]){
	int code1[4];
	clone(code1,code);
	int perMatch = 0;
	int imPerMatch = 0;
	int index[4];
	for (int i = 0; i < 4; i++){
		if (code1[i] == guessCode[i]){
			if (i == 4-perMatch)
				break;
			perMatch++;
			ignore(code1,i,4-perMatch);
			ignore(guessCode,i,4-perMatch);
			i--;
			
			
			printf("x");
			
		}
	}
	display(code1);
	printf("-----\n");
	display(guessCode);
	if (perMatch == 4){
		return 1;
	}
	else{
		for (int j = 0; j < 4 - perMatch; j++){
			
			
			for (int k = 0; k < 4 -perMatch; k++){
				if (j > 0){
					if(check(code1,code1[j],j) == true)
						break;
				}
				
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
	int code[4]      = {5,1,4,5};
	int guessCode[4] = {4,5,1,1};
	gameplay(code,guessCode);
}
