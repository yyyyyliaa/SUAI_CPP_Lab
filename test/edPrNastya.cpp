#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define N 9
#define D 3 //расстояние хемминга(ошибка),

unsigned char count_ones(unsigned char n)
{ //количетво единиц
    unsigned char w = 0;
    while (n > 0)
    {
        w += n & 1;
        n = n>> 1;
    }
    return w;
}

bool SearchZero(int *mark, int size) //подсчет кодовых слов
{
    int i = 0;
    for (i = 0; i < size; i++)
    {

        if (mark[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int M = 0;
    const int size = pow(2, N);
    srand(time(NULL));
    int *mark = (int *)calloc(size + 4, sizeof(int));
    int *CodeBook = (int *)calloc(size + 4, sizeof(int));

    while (SearchZero(mark, size))
    {
        int zero = 0;

        for (zero = 0; mark[zero] != 0; zero++)
            
        while (mark[zero] == 0)
        {
            zero = rand() % size;
            CodeBook[M] = zero;
            // Отметим взятое слово в массиве пометок.

            mark[zero] = 2;
            M++;

            for (int i = 0; i < size; i++)
            {
                if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
                {
                    mark[i] = 1;
                }
                printf("%d ", mark[i]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < 38; i++)
    {
        printf("%d ", CodeBook[i]);
    }

    return 0;
}