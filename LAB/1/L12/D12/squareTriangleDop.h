#pragma once

class SquareTriangle {

private:
    double p_coordX[3];
    double p_coordY[3];   

    int indexVert;
    int indexHeight;
    int indexBase;

public:
    SquareTriangle();
     
    SquareTriangle(double* coordX, double* coordY);

    void setTriangle(double* coordX, double* coordY);

    void definitionCoord();

    double square();

    int rightTriangle();

    void printTriangle() const; 

    friend class Rectaingle;

};

class Rectaingle{

private:

    double p_coordXRec[4];
    double p_coordYRec[4];

    SquareTriangle treug;
    SquareTriangle treug1;

public:


    Rectaingle();

    Rectaingle(double* coordX, double* coordY, double* coordX1, double* coordY1);

    // void setRectaingle(double* coordXRec, double* coordYRec);

    int checkingMerger(double* coordX, double* coordY, double* coordX1, double* coordY1);

    void initRectangle(double* coordX, double* coordY, double* coordX1, double* coordY1);

    void printRectaingle() const;

    void printIndexBase();

    friend class SquareTriangle;

};

void definitionCoord(int& indexVert, int& indexHeight, int& indexBase, double* coordX, double* coordY);

int len(int index, double* coordX, double* coordY);

