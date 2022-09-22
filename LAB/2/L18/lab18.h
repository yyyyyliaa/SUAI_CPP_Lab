#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <map>


typedef struct Node {
     std::vector<std::string> childs;
} Node;

class Tree{
    private:
        std::map<std::string, Node> nodes;
        std::string root;

    public:
       void addRoot(const std::string& rootName);
       void addNode(const std::string& parent,  const std::string& nodeName);
       size_t getSize();
       size_t deepTree();
       void print(std::string cur, std::string prefix);
       friend std::ostream& operator<<(std::ostream& os, Tree& t); 
};

