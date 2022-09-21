#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct Node{
    std::vector<size_t> inf;
    bool visited;
};
class Graph{

    private:
        std::map<size_t, Node> graph;
        size_t root;
    public:
            Graph(string& f);
            void dfs(size_t cur);
            size_t getRoot();
            void setRoot(size_t r);

            friend std::ostream& operator<<(std::ostream& os, Graph& g);
};