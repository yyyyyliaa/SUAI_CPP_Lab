#include <stdio.h>

int kniga[4] = {0x00, 0x0D, 0x16, 0x1B};

int koder(int m){
    return kniga[m];
}
int kanal(int a, int e){
    int b = a^e;
    return b;
}

int main(){
    int e = 0xB;
    int m = 3;
    int a = koder(m);
    printf("%d\n", a);
    printf("%d\n", e);
    int b = kanal(a, e);
    printf("%d", b);
    return 0;

}



