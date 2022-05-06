/*По символьному файлу с программой на языке С создать новый символьный файл, 
не содержащий комментариев ( /.../ и //). */


#include <stdio.h>
#include <iostream>
#include "l10v9.h"
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;


int main() {
    file_s* s1 = read_file("1.c");

    system("chcp 1251");
    system("cls");

    char* editedFile = (char*)calloc(s1->size, sizeof(char));

    int flag = 0; 
    //1 - /*...*/ 
    //2 - //
    
    size_t j = 0;

    for (size_t i = 0; i < s1->size-1; i++) {
        if(s1->arr[i] == '/' && s1->arr[i+1] == '*'){
            if (flag == 0) {
                flag = 1;
                i++;
                continue;
            }
        }
        else if(s1->arr[i] == '*' && s1->arr[i+1] == '/'){
            if (flag == 1) {
                flag = 0;
                i++;
                continue;
            }
        }
        else if (s1->arr[i] == '/' && s1->arr[i+1] =='/'){
            if (flag == 0) {
                flag = 2;
                i++;
                continue;
            }
        }
        else if(s1->arr[i]=='\n'){
            if (flag == 2) {
                flag = 0;
            }
        }

        if (flag == 0) {
            editedFile[j] = s1->arr[i];
            j++;
        }

    }
    if (flag == 0) {
        editedFile[j] = s1->arr[s1->size-1];
        j++;
    }

    copyFile("2.c", editedFile, j);

}