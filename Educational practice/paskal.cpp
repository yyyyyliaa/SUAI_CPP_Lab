#include <stdio.h>
#define N 66
int main(){
    long long arr[N+1][N+1] = {0};
    arr[0][0]=1;
    printf("%llu", arr[0][0]);
    for(int i = 1;i < N+1;i++){
        for(int j = 0; j < N + 1; i++){
            if (j==0) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            if (arr[i][j] != 0) printf("%llu", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}