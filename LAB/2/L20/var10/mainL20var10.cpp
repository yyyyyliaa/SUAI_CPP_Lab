/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

#include "lab20var10.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Graph g;
    g.loadFromFile("loh.json");
    string tab = "->";
    g.dfs(g.getRoot(),tab);
    

    return 0;
}