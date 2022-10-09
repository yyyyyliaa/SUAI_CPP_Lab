#include <stdio.h>
#include <math.h>
#define EPS 0.00001
#define PI 3.1415926535

int factorial(int x){  //функция для подсчета факториала числа
    int res = 1;
    if (x==0) return 1;
    else{
    for (int i = 1; i<=x; i++)
        res*=i;
    return res;
    }
}

int main() {
    double a , S = 0, shx, x;

    printf("Enter x: ");
    scanf("%lf",&x);

    a = x;

    int n = 0;

    while(1){   
        if(n%2==1){  //проверка на нечетность
            a = pow(x,n)/factorial(n);
            if(fabs(a) > EPS) S+=a; //если a удовлетворяет условию, то добавляем к сумме, иначе выходим из цикла
            else break;
        }
        n++;
    }

    printf("Sum = %lf\n",S);
    
   

    printf("Test\n");
    shx = (exp(x)-exp(-x))/2;
    printf("shx(x)=%lf\n",shx);   //подсчитываем значение проверочной функции
    printf("S=%lf\n",S);

    return 0;
}
