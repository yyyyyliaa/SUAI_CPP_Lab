/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

#pragma once

#include <iostream>
#include <fstream>
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
    std::vector <std::vector<int> > paths;
    Graph();
    void dfs(int cur, std::string& tab);
    void dfsPaint(int cur, std::string& tab, std::vector<int> history);
    void loadFromFile(const std::string& fileName);
    int getRoot();
    void saveToDot(std::string file);

};