#pragma once

#define MemSize 5
#define paragraf 16

char *palloc(int n);

void pfree(char *p);

void printBitArray();

void printBitArrayCheck();

void copyBites(int start, int size);