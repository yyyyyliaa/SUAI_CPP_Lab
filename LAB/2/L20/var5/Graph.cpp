#include "Graph.hpp"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

int charToInt(char c){
    return c-'0';
}

Graph::Graph(string matrixFile, string listFile){
    this->matrixFile = matrixFile;
    this->listFile = listFile;
}

void Graph::loadMatrixFromFile(string path){

    fstream file;
	file.open(path);
	if (!file.is_open()) {
		cout << "ERROR";
	}

    string s;
    int strNumber = 0;
    int strCount = 0;

    // while(getline(file, s)){
    //     strCount++;
    // }
    // matrix.resize(strCount);
    
    while(getline(file, s)){
        strCount++;
        matrix.resize(strCount);
        for (int i = 0; i<s.length(); i++){
            if(s[i] != ' '){
                int tmp = charToInt(s[i]);
                matrix[strNumber].push_back(tmp);
            }
        }
        strNumber++;
    }
    this->size = strNumber;
}

void Graph::saveListToFile(){
    ofstream out;
    out.open(listFile);
    if (out.is_open()){
        for(int i = 0; i<list.size(); i++){
            for(int j = 0; j<list[i].size(); j++){
                out<<list[i][j]<<", ";
            }
            out<<endl;
        }
    }
}

void Graph::fromMatrixToList(){
    
    loadMatrixFromFile(matrixFile);

    list.resize(size);

    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[i].size(); j++){
            int tmp = matrix[i][j];
            if(tmp!=0) list[i].push_back(j+1);
        }
    }

    saveListToFile();
}




