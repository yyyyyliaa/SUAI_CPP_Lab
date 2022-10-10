/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

//покрасить разными цветами путь

#include "lab20var10.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Graph g;
    g.loadFromFile("loh2.json");
    string tab = "->";
    g.dfsPaint(g.getRoot(),tab, {});
    g.saveToDot("loh.dot");
    

    return 0;
}