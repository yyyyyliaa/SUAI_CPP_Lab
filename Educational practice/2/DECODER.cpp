#include <stdio.h>
//        m      a      b        m^
//источник->кодер->канал->декодер->

int kniga[] = {0x00, 0x0D, 0x16, 0x1B};

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

void bin(long unsigned int k, long unsigned int size)
{
    long unsigned int i;
 
 
    for(i=0; i<8*size; i++) {
        int c = (k&1);
        printf("%d", c);
        k = (k>>1);
    }
}

void printBin(unsigned int n, int bit){
    for (int i = bit-1; i>-1; i--){
        printf("%d", (n>>i)&1);
    }
}

int decoder(int a){
    int array[4] = {0};
    for (int i = 0; i < 4; i++) 
        array[i] = kniga[i] ^ a;

    int min = array[0];
    int minIndex = 0;
    for (int i = 0; i < 4; i++) {
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int m = 1; //вход кодера
    int a = koder(m); // выход кодера
    int e = 0x0;
    int b = kanal(a, e); // выход канала
    int m_out = decoder(b); // выход декодера
    
    printf("m = %d\n", m);
    printf("a = %d\n", a);
    printf("e = %d\n", e);
    printf("b = %d\n", b);
    printf("m_out = %d\n", m_out);


    return 0;

}
