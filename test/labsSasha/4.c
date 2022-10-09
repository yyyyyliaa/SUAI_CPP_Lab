#include <stdio.h>

int main(){
    int a, n;

    printf("Enter a: ");  //вводим с клавиатуры a
    scanf("%d", &a);

    printf("Enter n (n>0): ");
    scanf("%d", &n);  //вводим с клавиатуры n
    if (n<=0){
        printf("Enter n (n>0): ");  //проверка условия n > 0 (n должно быть натуральным)
        scanf("%d", &n);
    }

    int x = 1;  //сюда будет записываться результат
    for(int i = 0; i<=n*n; i+=n)  //a(a-n)(a-2n)...(a-n^2)
        x*=(a-i);
    
    printf("Result: %d\n", x);  //выводим результат 

    return 0;
}
