#include "l10v9.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
size_t file_size(FILE *f) {
	fseek(f, 0, SEEK_END);	 
	size_t fsize = ftell(f); 
	fseek(f, 0, SEEK_SET);	
	return fsize;
}

int fSize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET);
    return sz;
}

file_s *read_file(const char *filename) {

	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		printf("Error! opening files\n");
		exit(1);
	}
    printf("%d - %d", fSize(f), file_size(f));
	size_t fsize = fSize(f);
	char *s = (char *)malloc(fsize * sizeof(char));
    int countN = 0;
	for (size_t i = 0; i < fsize; i++)
	{
        s[i] = fgetc(f);
        if(s[i] == '\n')
            countN++;
    }
    for (size_t i = fsize; i >= fsize-countN; i--)
    {
        s[i] = 0;
    }
    
    fsize-=countN;

	file_s *tstur = (file_s *)malloc(sizeof(file_s));
	
	tstur->arr = s;
	tstur->size = fsize;
	fclose(f);
	return tstur;
}

void copyFile(const char *filename, char* mas, size_t size){
    FILE *f = fopen(filename, "w");
	if (f == NULL) {
		printf("Error! opening files\n");
		exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        fputc(mas[i], f);
    }
    fclose(f);
}

