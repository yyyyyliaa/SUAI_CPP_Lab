#include <stdio.h>
//        m      a      b        m^
//источник->кодер->канал->декодер->

int kniga[4] = {0x00, 0x0D, 0x16, 0x1B};

int koder(int m){
    return kniga[m];
}

int kanal(int a, int e){
    int b = a^e;
    return b;
}
/* 0000->0x00
01101->0xD
10110->0x16
11011->0x1B*/


int w(int b){
    int w = 0;
    while (b>0){
        w+=b&1;
        b>>=1;
    }
    return w;
}

int main(){
    int e = 0xB;
    int m = 2;
    int a = koder(m);
    printf("Vector a: %d\n", a);
    printf("Vector e: %d\n", e);
    int b = kanal(a, e);
    printf("Vector b: %d\n", b);

    int min = 5;
    int result;
    int tmp;

    for (int i = 0; i<4; i++){
        int r = b^kniga[i];
        result = w(r);
        if (result<min){
          min =result;  
          tmp = i;
        } 
    }
    printf("d = %d\n", min);
    printf("Result: %d", kniga[tmp]);

    return 0;

}
