#include <stdio.h>
#include <math.h>
#define EPS 0.0001


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
    double S = 0, x, a = 1;
    printf("Enter x (0.1<=x<=1): ");
    scanf("%lf", &x);

    if((x<=1)&&(x>=0.1)){  //проверяем x на условие 
        int n = 0;
        while(1){   
            a = ((2*n+1)*pow(x, 2*n))/factorial(n);
            if(fabs(a) > EPS){ //если a удовлетворяет условию, то добавляем к сумме, иначе выходим из цикла
                S+=a; 
                n++;
            }
            else break;
        }
        printf("Sum=%lf\n",S);
    }
    else {   //если условие не соблюдается, то вводим х снова
        printf("Enter x (0.1<=x<=1): ");
        scanf("%lf", &x);
    }

    double y = (1+(2*pow(x, 2)))*exp(pow(x, 2));

    printf("y(x)=%lf\n",y);   //подсчитываем значение проверочной функции
    printf("S=%lf\n",S);


    return 0;
}