/*Даны координаты двух точек на плоскости. 
Если хотя бы одна из них лежит на какой-нибудь оси, вывести сообщение об этом; 
если они обе находятся в одной четверти, найти расстояние между ними; 
иначе – найти точку, наиболее удаленную от центра координат.*/

#include <stdio.h>
#include <math.h>

double distance(int* dot1, int* dot2){  //функция для нахождения расстояния между точками 
    return sqrt(pow(dot2[0]-dot1[0], 2)+pow(dot2[1]-dot1[1], 2));  // D^2 = (х2-x1)^2 + (y2-y1)^2
}

int main(){
    int dot1[2]; //координаты первой точки (dot1[0] - X, dot1[1] - координата Y)
    int dot2[2]; //координаты второй точки 
    int start[2] = {0}; //координаты центра координат

    printf("Enter coord X of first dot: "); //вводим координаты первой точки
    scanf("%d", &dot1[0]);
    printf("Enter coord Y of first dot: ");
    scanf("%d", &dot1[1]);

    printf("Enter coord X of second dot: "); //вводим координаты второй точки
    scanf("%d", &dot2[0]);
    printf("Enter coord Y of second dot: ");
    scanf("%d", &dot2[1]);

    if (dot1[0]==0) printf("First dot on X");    //проверяем, лежит ли точка на какой-либо оси 
    else if (dot1[1]==0) printf("First dot on Y");     //(если координата Х равна нулю, то лежит. С координатой Y так же)
    else if (dot2[0]==0) printf("Second dot on X");
    else if (dot2[1]==0) printf("Second dot on Y");

    if((dot1[0]>0)&&(dot1[1]>0)&&(dot2[0]>0)&&(dot2[1]>0)) printf("Distance: %f\n", distance(dot1, dot2));    //строки 33-36 проверяют лежат ли точки в одной четверти
    else if ((dot1[0]>0)&&(dot1[1]<0)&&(dot2[0]>0)&&(dot2[1]<0)) printf("Distance: %f\n", distance(dot1, dot2));
    else if ((dot1[0]<0)&&(dot1[1]<0)&&(dot2[0]<0)&&(dot2[1]<0)) printf("Distance: %f\n", distance(dot1, dot2));
    else if ((dot1[0]<0)&&(dot1[1]>0)&&(dot2[0]<0)&&(dot2[1]>0)) printf("Distance: %f\n", distance(dot1, dot2));
    else{   //если не лежат, то находим расстояние от каждой точки до начала координат, выводим большее
        int rasst1 = distance(dot1, start);
        int rasst2 = distance(dot2, start);
        if (rasst1>rasst2) printf("First dot is farther from the origin");
        else if (rasst2>rasst1) printf ("Second dot is farther from the origin");
    }

    return 0;
}