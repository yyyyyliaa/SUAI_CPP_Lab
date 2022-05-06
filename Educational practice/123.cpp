#include <stdio.h>

int func(int x){
    int w = 0;
    while (x>0){
        w+=x&1;
        x>>=1;
    }
    return w;
}

int main(){

    int x = 2147483647;

    printf("x = %d\n", x);
    printf("w = %d", func(x));

    return 0;

}