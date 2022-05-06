#pragma once
#define STR_SIZE 3

typedef struct file_s
{
	char *arr;
	int size;
} file_s;


file_s *read_file(const char *filename);

void copyFile(const char *filename, char* mas, size_t size);