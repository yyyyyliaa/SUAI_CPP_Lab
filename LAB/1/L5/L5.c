//Ввести строку и два слова. Вывести строку, в которой все вхождения первого слова заменены на второе слово.

#include<stdio.h>
#include<stdlib.h>

#define S 100
#define W 10

int compare(char* str, char* word, int start, int lenStr, int lenWord) {
    if (lenStr - start < lenWord) return 0;
    for (int i = 0; i < lenWord; i++) {
        if (str[start + i] != word[i]) return 0;
    }
    return 1;
}

int main() {

    printf("Enter first word: ");
    char firstWord[W] = { 0 };
    fgets(firstWord, W, stdin);

    int lenW1 = 0;
    while (firstWord[lenW1 + 1] != 0) lenW1++;

    printf("\n");

    printf("Enter second word: ");
    char secondWord[W] = { 0 };
    fgets(secondWord, W, stdin);

    int lenW2 = 0;
    while (secondWord[lenW2 + 1] != 0) lenW2++;

    printf("\n");

    printf("Enter string: ");
    char str[S] = { 0 };
    fgets(str, S, stdin);

    int lenStr = 0;
    while (str[lenStr + 1] != 0) lenStr++;

    printf("\n");
    int tmp = lenStr;
    char* words = (char*)malloc(sizeof(char) * tmp);
    int shift = 0;

    int i = 0;

    for (int i = 0; i < lenStr; i++) {
        if ((str[i - 1] == ' ') || (i == 0)) {
            if (compare(str, firstWord, i, lenStr, lenW1) == 1) {
                tmp = tmp + (lenW2 - lenW1);
                words = (char*)realloc(words, tmp * sizeof(char));

                for (int k = 0; k < lenW2; k++) {
                    words[i + k] = secondWord[k];
                }
                shift += lenW2 - lenW1;
                i += lenW1-1;
            }
            else words[shift + i] = str[i];
             
        }
        else words[shift + i] = str[i];
    }

    for (int i = 0; i < tmp; i++) {
        printf("%c", words[i]);
    }
    free(words);
    return 0;
}