#include <stdio.h>

unsigned char a[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

unsigned char count1 (unsigned long long n){
    unsigned char w = 0;
    while (n>0) {
        w+=a[n&15];
        n = n>>4;
    }
    return w;
}
int main(){
    int n;
    unsigned long long pow2 = 1;
    scanf_s("%d", &n);
    int arr[n + 1] = {0};
    for (int i = 0; i<n; i++) pow2*=2;
    for (unsigned long long i = 0; i<pow2; i++) arr[count1(i)]++;
    for (int i = 0; i < n; i++) printf("a[%d] = %d\n", i, a[i]);
}