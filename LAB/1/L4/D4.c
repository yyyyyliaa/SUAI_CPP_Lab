#include<stdio.h>
#define S 100
#define W 10

void delSymbol(char* str, char* word) {

	int lenStr = 0;
	int lenWord = 0;
	 
	while (*(str+lenStr + 1) != 0) lenStr++;
	while (*(word+lenWord + 1) != 0) lenWord++;

	for (int i = 0; i < lenWord; i++) {
		for (int j = 0; j < lenStr; j++) {
			if (*(str+j) == *(word+i)) *(str+j) = '0';
		}
	}
}

int main() {

	printf("Enter word: ");
	char word[W] = { 0 };
	fgets(word, W, stdin);

	printf("\n");

	printf("Enter string: ");
	char str[S] = { 0 };
	fgets(str, S, stdin);

	printf("\n");

	delSymbol(str, word);

	for (int i = 0; i < S; i++) {
		if (*(str+i) != '0') printf("%c", str[i]);
	}

	return 0;
}