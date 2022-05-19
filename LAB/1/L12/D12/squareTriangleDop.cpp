/*Создайте класс SquareTriangle с координатами 3-х вершин.
В конструкторе предусмотреть проверку того, что треугольник прямоугольный.
Реализовать элементы-функции для масштабирования, поворота на 90, зеркального отражения от оси ординат.*/

/*Написать функцию, считающую пощадь треугольника и функцию "склеивания" треугольников в прямоугольник*/

#include <iostream>
#include "squareTriangleDop.h"
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
void mySort(int *array, int size){
    for (int i = 0; i < size; i++){
        for (int j = size - 1; j > i; j--){
            if (array[j - 1] > array[j]){
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
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
                len[j-1]==len[j];
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
    for (int i = 0; i < 3; i++){
        cout << "(" << p_coordX[i] << "; " << p_coordY[i] << ")" << endl;
    }
}


Rectaingle::Rectaingle(double* coordX, double* coordY, double* coordX1, double* coordY1): 
        treug(coordX, coordY), treug1(coordX1, coordY1){
}



void Rectaingle::initRectangle(double* coordX, double* coordY, double* coordX1, double* coordY1){
    int indexVert;
    int indexHeight;
    int indexBase;

    definitionCoord(indexVert, indexHeight, indexBase, coordX, coordY);

    if (checkingMerger(coordX, coordY, coordX1, coordY1)==2){
        for(int i = 0; i<3; i++){
            p_coordXRec[i] = coordX[i];
            p_coordYRec[i] = coordY[i];
        }
        p_coordXRec[3] = coordX[indexBase];
        p_coordYRec[3] = coordY[indexHeight];
    }

}
void Rectaingle::printRectaingle() const{
    for (int i = 0; i<4; i++)
            cout << "(" << p_coordXRec[i] << "; " << p_coordYRec[i] << ")" << endl;
}



void Rectaingle::printIndexBase(){
    cout<<treug.indexBase<<endl;
}


// int Rectaingle::checkingMerger(){
//     int indexVert;
//     int indexHeight;
//     int indexBase;

//     int indexVert1;
//     int indexHeight1;
//     int indexBase1;

//     definitionCoord(indexVert, indexHeight, indexBase, treug.p_coordX, treug.p_coordY);
//     definitionCoord(indexVert1, indexHeight1, indexBase1, coordX1, coordY1);

//     int lenH = len(indexHeight, coordX, coordY);
//     int lenB = len(indexBase, coordX, coordY);

//     int lenH1 =len(indexHeight1, coordX1, coordY1);
//     int lenB1 = len(indexBase1, coordX1, coordY1);

//     int check;
//     if ((lenH == lenH1) && (lenB == lenB1))
//         check++;
//     else check = 0;

//     if (((coordX[indexVert] < coordX[indexBase]) && (coordY[indexVert] < coordY[indexHeight])) && 
//             ((coordX1[indexVert1] > coordX1[indexBase1]) && (coordY1[indexVert1] > coordY1[indexHeight1])))
//         check++;
//     else if (((coordX[indexVert] > coordX[indexBase]) && (coordY[indexVert] > coordY[indexHeight])) && 
//             ((coordX1[indexVert1] < coordX1[indexBase1]) && (coordY1[indexVert1] < coordY1[indexHeight1])))
//         check++;

//     return check;

// }


//void Rectaingle::setRectaingle(double* coordXRec, double* coordYRec){
//     for (int i = 0; i<4; i++){
//         p_coordXRec[i] = coordXRec[i];
//         p_coordYRec[i] = coordYRec[i];
//     }
// }


// int len(int index, int* coordX, int* coordY){
//     return sqrt(pow(coordX[index] - coordX[index], 2) + pow(coordY[index] - coordY[index], 2));
// }

// void definitionCoord(int& indexVert, int& indexHeight, int& indexBase, int* coordX, int* coordY){
//     if ((coordX[0]==coordX[1])&&(coordY[0]==coordY[2])){
//         indexVert = 0;
//         indexHeight = 1;
//         indexBase = 2;
//     }
//     else if ((coordX[0]==coordX[2])&&(coordY[0]==coordY[1])){
//         indexVert = 0;
//         indexHeight = 2;
//         indexBase = 1;
//     }
//     else if ((coordX[1]==coordX[0])&&(coordY[1]==coordY[2])){ 
//         indexVert = 1;
//         indexHeight = 0;
//         indexBase = 2;
//     }
//     else if ((coordX[1]==coordX[2])&&(coordY[1]==coordY[0])){
//         indexVert = 1;
//         indexHeight = 2;
//         indexBase = 0;
//     }
//     else if ((coordX[2]==coordX[1])&&(coordY[2]==coordY[0])){ 
//         indexVert = 2;
//         indexHeight = 1;
//         indexBase = 0;
//     }
//     else if ((coordX[2]==coordX[0])&&(coordY[2]==coordY[1])){
//         indexVert = 2;
//         indexHeight = 0;
//         indexBase = 1;
//     }
// }