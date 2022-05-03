#pragma once

class SquareTriangle {

private:
    int p_coordX[3];
    int p_coordY[3];    /* TODO: добавить переменные для индексов вершины, высоты и основания*/

public:
    SquareTriangle();
     
    SquareTriangle(double* coordX, double* coordY);

    void setTriangle(double* coordX, double* coordY);

    void definitionCoord(int& indexVert, int& indexHeight, int& indexBase);

    double square();

    int function();

    int rightTriangle();

    void printTriangle(); //const;

};

// class Rectangle{

// private:
//     int p_coordX[4];
//     int p_coordY[4];

// public:
//     Rectangle();

//     Rectangle(int* coordX, int* coordY);

//     void setRectangle(int* coordX, int* coordY);

//     void printRectangle(); //const;

// };