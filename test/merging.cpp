#include <iostream>
using namespace std;

int main()
{
    int coordX[3] = {1, 1, 4};  /*TODO: Оформить как функцию и перенести в лабу*/
    int coordY[3] = {1, 3, 1};

    int coordX1[3] = {4, 1, 4};
    int coordY1[3] = {3, 3, 1};

    int coordXRec[4];
    int coordYRec[4];


    int indexVert = 0;
    int indexHeight = 1;
    int indexBase = 2;

    int indexVert1 = 0;
    int indexHeight1 = 2;
    int indexBase1 = 1;

    int lenH = 2;
    int lenB = 3;

    int lenH1 = 2;
    int lenB1 = 3;

    int check;
    if ((lenH == lenH1) && (lenB == lenB1))
        check++;
    else check = 0;

    if (((coordX[indexVert] < coordX[indexBase]) && (coordY[indexVert] < coordY[indexHeight])) && 
            ((coordX1[indexVert1] > coordX1[indexBase1]) && (coordY1[indexVert1] > coordY1[indexHeight1])))
        check++;
    else if (((coordX[indexVert] > coordX[indexBase]) && (coordY[indexVert] > coordY[indexHeight])) && 
            ((coordX1[indexVert1] < coordX1[indexBase1]) && (coordY1[indexVert1] < coordY1[indexHeight1])))
        check++;

    if (check==2){
        for(int i = 0; i<3; i++){
            coordXRec[i] = coordX[i];
            coordYRec[i] = coordY[i];
        }
        coordXRec[3] = coordX[indexBase];
        coordYRec[3] = coordY[indexHeight];
    }

    for(int i = 0; i<4; i++){
        cout << "(" << coordXRec[i] << "; " << coordYRec[i] << ")" << endl;
    }
}
