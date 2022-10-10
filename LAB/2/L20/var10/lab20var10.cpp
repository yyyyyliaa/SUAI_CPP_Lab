/*Ориентированный граф задан и хранится матрицей смежности. 
В файле задается вершина (корень), с которой начинается обход. 
Выписать пути до каждой вершины от корня, используя алгоритм dfs.*/

#include "lab20var10.h"
#include <fstream>
#include "json.hpp"
#include <ctime>
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

void Graph::dfsPaint(int cur, std::string& tab, std::vector<int> history){
    visited[cur] = 1;
    cout<<tab<<"->"<<cur+1<<endl;
    history.push_back(cur+1);
    if(history.size()>1) paths.push_back(history);
    for (int i = 0; i < size ; i ++) {
        if ( matrix[cur][i] == 1 && visited[i] == 0){
            string newTab = tab + "->" + to_string(cur+1);
            dfsPaint(i, newTab, history);
        }
    }

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

void Graph::saveToDot(std::string file){
    srand(time(0));
    std::ofstream f(file);
    f << "digraph G {\n\n";
    vector<std::string> colors = {"red", "blue", "green", "yellow", "black", "orange", "purple", "pink", "coral", "#00bce3"};
    for (int i = 0; i < paths.size(); i++){
        for (int j = 0; j < paths[i].size(); j++){
            f << paths[i][j];
            if (j != paths[i].size()-1)
                f << " -> ";
        }
        size_t indexColor = rand()%colors.size();
        f << " [color = \"" << colors[indexColor] << "\"];\n";
        colors.erase(colors.begin()+indexColor);
    }
    f << "\n}";
}
