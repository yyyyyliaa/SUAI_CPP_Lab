/*Создайте класс SquareTriangle с координатами 3-х вершин.
В конструкторе предусмотреть проверку того, что треугольник прямоугольный.
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

/*Написать функцию, считающую пощадь треугольника и функцию "склеивания" треугольников в прямоугольник*/

#include <iostream>
#include "dop12.h"
#include <math.h>
using namespace std;


SquareTriangle::SquareTriangle(double* coordX, double* coordY){
    setTriangle(coordX, coordY);
    definitionCoord();
}

void SquareTriangle::setTriangle(double* coordX, double* coordY){
    for (int i = 0; i < 3; i++){
        p_coordX[i] = coordX[i];
        p_coordY[i] = coordY[i];
    }
}
void SquareTriangle::definitionCoord(){
    if ((this->p_coordX[0]==this->p_coordX[1])&&(this->p_coordY[0]==this->p_coordY[2])){
        indexVert = 0;
        indexHeight = 1;
        indexBase = 2;
    }
    else if ((this->p_coordX[0]==this->p_coordX[2])&&(this->p_coordY[0]==this->p_coordY[1])){
        indexVert = 0;
        indexHeight = 2;
        indexBase = 1;
    }
    else if ((this->p_coordX[1]==this->p_coordX[0])&&(this->p_coordY[1]==this->p_coordY[2])){ 
        indexVert = 1;
        indexHeight = 0;
        indexBase = 2;
    }
    else if ((this->p_coordX[1]==this->p_coordX[2])&&(this->p_coordY[1]==this->p_coordY[0])){
        indexVert = 1;
        indexHeight = 2;
        indexBase = 0;
    }
    else if ((this->p_coordX[2]==this->p_coordX[1])&&(this->p_coordY[2]==this->p_coordY[0])){ 
        indexVert = 2;
        indexHeight = 1;
        indexBase = 0;
    }
    else if ((this->p_coordX[2]==this->p_coordX[0])&&(this->p_coordY[2]==this->p_coordY[1])){
        indexVert = 2;
        indexHeight = 0;
        indexBase = 1;
    }
}
int SquareTriangle::rightTriangle(){
    int len[3];
    len[0] = pow(p_coordX[0] - p_coordX[1], 2) + pow(p_coordY[0] - p_coordY[1], 2);
    len[1] = pow(p_coordX[1] - p_coordX[2], 2) + pow(p_coordY[1] - p_coordY[2], 2);
    len[2] = pow(p_coordX[2] - p_coordX[0], 2) + pow(p_coordY[2] - p_coordY[0], 2);

    for (int i = 0; i<3; i++){
        for (int j = 2; j>i; j--){
            if (len[j-1]>len[j]){
                int tmp = len[j-1];
                len[j-1]=len[j];
                len[j] = tmp;
            }
        }
    }

    if ((len[0] + len[1]) == len[2])
        return 1;
    return 0;
}
double SquareTriangle::square(){

    int lenHeight = sqrt(pow(p_coordX[indexVert] - p_coordX[indexHeight], 2) + pow(p_coordY[indexVert] - p_coordY[indexHeight], 2));
    int lenBase = sqrt(pow(p_coordX[indexVert] - p_coordX[indexBase], 2) + pow(p_coordY[indexVert] - p_coordY[indexBase], 2));

    return lenHeight*lenBase*0.5;
}
void SquareTriangle::printTriangle() const{
    for (int i = 0; i < 3; i++)
        cout << "(" << p_coordX[i] << "; " << p_coordY[i] << ")" << endl;
}



Rectaingle::Rectaingle(double* coordX, double* coordY, double* coordX1, double* coordY1): treug(coordX, coordY), treug1(coordX1, coordY1) {};

int Rectaingle::checkingMerger(SquareTriangle treug, SquareTriangle treug1){
    int check = 0;

    int lenH = sqrt(pow(treug.p_coordX[treug.indexVert] - treug.p_coordX[treug.indexHeight], 2) + pow(treug.p_coordY[treug.indexVert] - treug.p_coordY[treug.indexHeight], 2));
    int lenB = sqrt(pow(treug.p_coordX[treug.indexVert] - treug.p_coordX[treug.indexBase], 2) + pow(treug.p_coordY[treug.indexVert] - treug.p_coordY[treug.indexBase], 2));

    int lenH1 =sqrt(pow(treug1.p_coordX[treug1.indexVert] - treug1.p_coordX[treug1.indexHeight], 2) + pow(treug1.p_coordY[treug1.indexVert] - treug1.p_coordY[treug1.indexHeight], 2));
    int lenB1 = sqrt(pow(treug1.p_coordX[treug1.indexVert] - treug1.p_coordX[treug1.indexBase], 2) + pow(treug1.p_coordY[treug1.indexVert] - treug1.p_coordY[treug1.indexBase], 2));

    if ((lenH == lenH1) && (lenB == lenB1))
        check++;
    else check = 0;

    if (((treug.p_coordX[treug.indexVert] < treug.p_coordX[treug.indexBase]) && (treug.p_coordY[treug.indexVert] < treug.p_coordY[treug.indexHeight])) && 
            ((treug1.p_coordX[treug1.indexVert] > treug1.p_coordX[treug1.indexBase]) && (treug1.p_coordY[treug1.indexVert] > treug1.p_coordY[treug1.indexHeight])))
        check++;
    else if (((treug.p_coordX[treug.indexVert] > treug.p_coordX[treug.indexBase]) && (treug.p_coordY[treug.indexVert] > treug.p_coordY[treug.indexHeight])) && 
            ((treug1.p_coordX[treug1.indexVert] < treug1.p_coordX[treug1.indexBase]) && (treug1.p_coordY[treug1.indexVert] < treug1.p_coordY[treug1.indexHeight]))) 
            check++;


    return check;
}
void Rectaingle::initRectangle(){
    if (checkingMerger(treug, treug1)==2){
        for(int i = 0; i<3; i++){
            p_coordXRec[i] = treug.p_coordX[i];
            p_coordYRec[i] = treug.p_coordY[i];
        }
        p_coordXRec[3] = treug.p_coordX[treug.indexBase];
        p_coordYRec[3] = treug.p_coordY[treug.indexHeight];
        cout<<"Coordinates rectaingle:"<<endl;
        printRectaingle();
    }
    else cout<< "Mergering is not possible"<<endl;
}
void Rectaingle::printRectaingle() const{

    for (int i = 0; i<4; i++)
            cout << "(" << p_coordXRec[i] << "; " << p_coordYRec[i] << ")" << endl;
}
void Rectaingle:: squareTriangles(){
    int lenH = sqrt(pow(treug.p_coordX[treug.indexVert] - treug.p_coordX[treug.indexHeight], 2) + pow(treug.p_coordY[treug.indexVert] - treug.p_coordY[treug.indexHeight], 2));
    int lenB = sqrt(pow(treug.p_coordX[treug.indexVert] - treug.p_coordX[treug.indexBase], 2) + pow(treug.p_coordY[treug.indexVert] - treug.p_coordY[treug.indexBase], 2));

    int lenH1 =sqrt(pow(treug1.p_coordX[treug1.indexVert] - treug1.p_coordX[treug1.indexHeight], 2) + pow(treug1.p_coordY[treug1.indexVert] - treug1.p_coordY[treug1.indexHeight], 2));
    int lenB1 = sqrt(pow(treug1.p_coordX[treug1.indexVert] - treug1.p_coordX[treug1.indexBase], 2) + pow(treug1.p_coordY[treug1.indexVert] - treug1.p_coordY[treug1.indexBase], 2));

    double s1 = 0.5*lenH*lenB;
    cout<<"Square of treug: "<<s1<<endl;

    double s2 = 0.5*lenH1*lenB1;
    cout<<"Square of treug1: "<<s2<<endl;
}


int rightTriangle(double* p_coordX, double* p_coordY){
    int len[3];
    len[0] = pow(p_coordX[0] - p_coordX[1], 2) + pow(p_coordY[0] - p_coordY[1], 2);
    len[1] = pow(p_coordX[1] - p_coordX[2], 2) + pow(p_coordY[1] - p_coordY[2], 2);
    len[2] = pow(p_coordX[2] - p_coordX[0], 2) + pow(p_coordY[2] - p_coordY[0], 2);

    for (int i = 0; i<3; i++){
        for (int j = 2; j>i; j--){
            if (len[j-1]>len[j]){
                int tmp = len[j-1];
                len[j-1]=len[j];
                len[j] = tmp;
            }
        }
    }

    if ((len[0] + len[1]) == len[2])
        return 1;
    return 0;
}


