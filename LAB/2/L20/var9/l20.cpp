#include "lab20.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


void Graph::dfs (size_t cur){
    graph[cur].visited = 1;

    for (size_t i = 0; i<graph[cur].inf.size(); i++){
        size_t tmp = graph[cur].inf[i];
        // if (graph[tmp].visited = 0)
    }
}

