/*Неориентированный граф задан матрицей смежности. Сохранить его в формате списка смежности.*/

#include<fstream>
#include<iostream>

#include "Graph.hpp"

using namespace std;

int main(){
    string graphMatrixPath = "graphMatrix.txt";
    string graphListPath = "graphList.txt";

    Graph test(graphMatrixPath, graphListPath);
    
    test.fromMatrixToList();

    return 0;
}