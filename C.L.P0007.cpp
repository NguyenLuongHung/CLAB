#include <stdio.h>
#include <string.h>
int pow(int x, int y){
	int p = 1;
	for (int i = 0; i < y; i++){
		p *= x;
	}
	return p;
}
bool checkBi(char s[]){
	for (int i = 0; i< strlen(s); i++){
		if (s[i] < 48 || s[i] > 49){
			return false;
		}
	}
	return true;		
}
bool checkHex(char s[]){
	for (int i = 0; i < strlen(s); i++){
		if (s[i] < 48 )
			return false;
		else if (s[i] > 57 && s[i] < 65)
			return false;
		else if (s[i] > 70 && s[i] < 97)
			return false;
		else if (s[i] > 102)
			return false;
	}
	return true;
}
bool checkOct(char s[]){
	for (int i = 0; i < strlen(s); i++){
		if (s[i] < 48 || s[i] > 55)
			return false;
	}
	return true;
}
int binary(char s){
	if (s == 48)
		return 0;

	else if (s == 49)
		return 1;
}
int octal(char s){
	for (int i = 48; i < 56; i++){
		if (s == i)
			return i - 48;
	}
}
int hexa(char s){
	if (s >= 48 && s <= 57) {
		for (int i = 48; i < 58; i++){
			if (s == i)
				return i - 48;
		}
	}
	else if (s >= 65 && s <= 70){
		for (int i = 65 ; i < 71; i++){
			if (s == i)
				return i - 55;
		}
	}
	else if (s >= 97 && s <= 102){
		for (int i = 97 ; i < 103; i++){
			if (s == i)
				return i - 87;
		}
	}
}
void octalConvert(){
	char oct[100];
	int decimal = 0;
	int a;
	int check;
	do {
		printf("Enter octal number: ");
		scanf("%s", &oct);
		check = checkOct(oct);
		if (check == false)
			printf("Invalid octal, please re-enter!\n");
	} while (check == false);
	for (int i = 0; i < strlen(oct);i++){
		a = octal(oct[i]);
		decimal += a * pow(8,strlen(oct) - i - 1);
	}
	printf("Decimal is: %d\n", decimal);
}
void hexaConvert(){
	char hex[100];
	int decimal = 0;
	int a;
	int check;
	do {
	printf("Enter hexa number: ");
	scanf("%s", &hex);
	check = checkHex(hex);
	if (check == false)
		printf("Invalid hexa, please re-enter!\n");
	} while (check == false);
	for (int i = 0; i < strlen(hex);i++){
		a = hexa(hex[i]);
		decimal += a * pow(16,strlen(hex) - i - 1);
	}
	printf("Decimal is: %d\n", decimal);
}
void binaryConvert(){
	char bi[100];
	int decimal = 0;
	int a;
	bool check;
	do {
	printf("Enter binary number: ");
	scanf("%s", &bi);
	check = checkBi(bi);
	if (check == false)
		printf("Invalid binary, please re-enter!\n");
	} while (check == false);
	for (int i = 0; i < strlen(bi); i++){
		a = binary(bi[i]);
		decimal += a * pow(2,strlen(bi) - i - 1);
	}
	printf("Decimal is: %d\n", decimal);
}
void options(){
	int a;
	char n;
	do {
	printf("1. Convert binary number to decimal number.\n");
	printf("2. Convert octal number to decimal number.\n");
	printf("3. Convert hexadecimal number to decimal number.\n");
	printf("4. Exit\n");
	printf("Please choose number (1-4): \n");
	scanf("%d%c",&a,&n);
	if (a == 1)
		binaryConvert();
	else if (a == 2)
		octalConvert();
	else if (a == 3)
		hexaConvert();
	} while (a != 4);
}
int main(){
	options();
}
