#include <stdio.h>
#include <stdlib.h>

int genRandom() {
    static int r= 1;
    r = (r * 4237 + 12345) % 100000;
    return r;
}

void interval(int* intervals, int x){
    if ((x>=0)&&(x<10000)) intervals[1]++;
    else if ((x>=10000)&&(x<20000)) intervals[2]++;
    else if ((x>=20000)&&(x<30000)) intervals[3]++;
    else if ((x>=30000)&&(x<40000)) intervals[4]++;
    else if ((x>=40000)&&(x<50000)) intervals[5]++;
    else if ((x>=50000)&&(x<60000)) intervals[6]++;
    else if ((x>=60000)&&(x<70000)) intervals[7]++;
    else if ((x>=70000)&&(x<80000)) intervals[8]++;
    else if ((x>=80000)&&(x<90000)) intervals[9]++;
    else if ((x>=90000)&&(x<=99999)) intervals[10]++;
}