#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class Graph{

private:

    std::string matrixFile;
    std::string listFile;

    std::vector <std::vector<int> > matrix;
    std::vector <std::vector<int> > list;
    int size;

public:
    Graph(std::string matrixFile, std::string listFile);


    void loadMatrixFromFile(std::string path);
    void saveListToFile();
    void fromMatrixToList();

};