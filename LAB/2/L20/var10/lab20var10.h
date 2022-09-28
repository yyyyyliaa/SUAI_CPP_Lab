/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

class Graph{

private:
    int root;
    int size;
    std::vector <std::vector<int> > matrix;
    std::vector<int> visited;

public:
    Graph();
    Graph(int v);
    void dfs(int cur, std::string& tab);
    void loadFromFile(const std::string& fileName);
    int getRoot();

};