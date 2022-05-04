#pragma once

class SquareTriangle {

private:
    int p_coordX[3];
    int p_coordY[3];   

public:
    SquareTriangle();
     
    SquareTriangle(int* coordX, int* coordY);

    void setTriangle(int* coordX, int* coordY);

    void definitionCoord(int& indexVert, int& indexHeight, int& indexBase);

    double square();

    int rightTriangle();

    void printTriangle() const; 

};

void definitionCoord(int& indexVert, int& indexHeight, int& indexBase, int* coordX, int* coordY);

int len(int index, int* coordX, int* coordY);

int checkingMerger(int* coordX, int* coordY, int* coordX1, int* coordY1);

void initRectangle(int* coordX, int* coordY, int* coordX1, int* coordY1, int* coordXRec, int* coordYRec);

