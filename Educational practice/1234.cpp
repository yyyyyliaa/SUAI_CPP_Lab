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

    int arr[16]={0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    

    int x = 2147483647;

    printf("x = %d\n", x);
    printf("w = %d", func(x));

    return 0;

}