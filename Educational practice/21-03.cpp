#include <stdio.h>

long int factorial(int a, int b){

    long int result = 1;
    
    for (int i =b+1; i<=a; i++) 
        result*=i;

    return result;
}

long int binominalCoeff(int n, int k){
    long int result;
    
    if (n>k) result = factorial(n, k)/factorial(n-k, 1);
    else if (k==0||n==k) result = 1;
    else if (n==0) result = 0;

    return result;
}

// int func(int n) {
// 	int count = 0;
// 	while (n != 0) {
// 		n = n >> 1;
// 		count++;
// 	}
// 	return count - 1;
// }

int main(){

    unsigned int n = 29;

    // printf("Enter coefficient n (n >= 0): ");
    // scanf_s("%ud", &n);

    // while (n < 0){
    //     printf("Coefficient n does not match the condition\n");
    //     printf("Enter coefficient n: ");
    //     scanf_s("%d", &n);
    // }


    //int count = func(n);
    //printf("%d", count);


    for (int i = 0; i <= n; i++){
        printf("%d - %ld\n", i, binominalCoeff(n,i));
    }
    

    return 0;

}