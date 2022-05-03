/*Создайте класс SquareTriangle с координатами 3-х вершин. 
В конструкторе предусмотреть проверку того, что треугольник прямоугольный. 
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

#include <iostream>
#include "squareTriangle.h"
using namespace std;
 
int main() {

    double coordX[3];
    double coordY[3];

    for (int i = 0; i <= 2; i++){
            cout<<"Enter coordinate x" << i << ":";
            cin >> coordX[i];
            cout<<"Enter coordinate y"<< i << ":";
            cin >> coordY[i];
            cout<<endl;
    }

    int check;
    SquareTriangle treug (coordX, coordY);

    check = treug.rightTriangle();
    if (check==1) {
        cout<< "This is a right triangle"<<endl;
    
        treug.printTriangle();
        cout<<endl;

        double n;
        cout<<"Enter scale\n"<<endl;
        cin >> n;
        treug.scaleTriangle(n);
        cout<<"Coordinates after scaling:"<< endl;
        treug.printTriangle();

        cout<<"Coordinates after mirroring: "<< endl;
        treug.mirrorTriangle();
        treug.printTriangle();

        cout<<"Coordinates after turning:"<< endl;
        treug.turnTriangle();
        treug.printTriangle();

    }
    else cout<<"This is not a right triangle"<<endl;
    return 0;
}