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

    void printTriangle(); //const;

};