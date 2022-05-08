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

    int checkingMerger(SquareTriangle treug, SquareTriangle treug1);

    void initRectangle();

    void printRectaingle() const;

};

int rightTriangle(double* p_coordX, double* p_coordY);