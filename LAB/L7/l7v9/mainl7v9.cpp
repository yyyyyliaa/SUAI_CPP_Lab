/*Написать генератор псевдослучайных чисел по алгоритму r = r * 4231 + 12345 mod 100000
Подсчитать частоты попадания в каждый из интервалов длиной 10000 при выборке 500000*/

#include <stdio.h>
#include "l7v9.h"

int main(){

int intervals[11] = {0};

for (int i = 0; i < 50000; i++){
    int num = genRandom();
    interval(intervals, num);
}

for (int i = 1; i < 11; i++) 
    printf("frequency of hitting in %d interval is %d out of 500000 \n", i, intervals[i]);

return 0;
}