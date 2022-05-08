/*Создайте класс SquareTriangle с координатами 3-х вершин. 
В конструкторе предусмотреть проверку того, что треугольник прямоугольный. 
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

/*Написать функцию, считающую пощадь треугольника и функцию "склеивания" треугольников в прямоугольник*/

#include <iostream>
#include "dop12.h"
using namespace std;
 
int main() {

    double coordX[3];
    double coordY[3];

    double coordX1[3];
    double coordY1[3];

    do{
        cout<<"Enter coordinates of first triangle:"<<endl;
        for (int i = 0; i <= 2; i++){
                cout<<"Enter coordinate x" << i << ":";
                cin >> coordX[i];
                cout<<"Enter coordinate y"<< i << ":";
                cin >> coordY[i];
                cout<<endl;
        }
    } while (rightTriangle(coordX, coordY)==0);

    cout<<endl;

    do{    
        cout<<"Enter coordinates of second triangle:"<<endl;
        for (int i = 0; i <= 2; i++){
                cout<<"Enter coordinate x" << i << ":";
                cin >> coordX1[i];
                cout<<"Enter coordinate y"<< i << ":";
                cin >> coordY1[i];
                cout<<endl;
        }
   } while (rightTriangle(coordX1, coordY1)==0);

    Rectaingle rec(coordX, coordY, coordX1, coordY1);

    rec.initRectangle();

    return 0;
}