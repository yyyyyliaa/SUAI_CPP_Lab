#include <iostream>

int main()
{
    int coordX[3] = {1, 1, 4};
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
        for(int i = 0; i<4; i++){
            
        }

    }
}
