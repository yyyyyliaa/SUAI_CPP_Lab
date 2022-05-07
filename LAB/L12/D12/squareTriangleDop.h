#pragma once

class SquareTriangle {

private:
    double p_coordX[3];
    double p_coordY[3];   

public:
    SquareTriangle();
     
    SquareTriangle(double* coordX, double* coordY);

    void setTriangle(double* coordX, double* coordY);

    void definitionCoord(int& indexVert, int& indexHeight, int& indexBase);

    double square();

    int rightTriangle();

    void printTriangle() const; 

};

class Rectaingle{

private:

    double p_coordXRec[4];
    double p_coordYRec[4];

    SquareTriangle treug1;
    SquareTriangle treug2;

public:
    Rectaingle();

    Rectaingle(double* coordXRec, double* coordYRec);

    void setRectaingle(double* coordXRec, double* coordYRec);


    int checkingMerger(double* coordX, double* coordY, double* coordX1, double* coordY1);

    void initRectangle(double* coordX, double* coordY, double* coordX1, double* coordY1, double* coordXRec, double* coordYRec);

    void printRectaingle() const;

};

void definitionCoord(int& indexVert, int& indexHeight, int& indexBase, double* coordX, double* coordY);

int len(int index, double* coordX, double* coordY);

