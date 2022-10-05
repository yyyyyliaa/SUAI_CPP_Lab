/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

#include "lab20var10.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

using namespace std;


void Graph::dfs (int cur, string& tab) {
    visited[cur] = 1;
    cout<<tab<<"->"<<cur+1<<endl;
    for (int i = 0; i < size ; i ++) {
        if ( matrix[cur][i] == 1 && visited[i] == 0){
            string newTab = tab + "->" + to_string(cur+1);
            dfs(i, newTab);
        }
    }
}


Graph::Graph(int ver){
    root = ver;
}

Graph::Graph(){
    root = 0;
}

void Graph::loadFromFile(const std::string& fileName){
    ifstream file(fileName);
    json j;
    file >> j;
    root = j["root"];
    root--;
    size = j["size"];
    matrix.resize(size);
    visited.resize(size, 0);
    for (int i = 0; i<j["size"]; i++){
        for (int k = 0; k<j["size"]; k++){
            matrix[i].push_back(j["data"][i][k]);
        }
    }




    file.close();
}

int Graph::getRoot(){
    return root;
}