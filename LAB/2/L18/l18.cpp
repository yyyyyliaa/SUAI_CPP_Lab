#include "lab18.h"

using namespace std;

void Tree::addNode(const std::string& parent,  const std::string& nodeName){
    if (nodes.find(parent)!=nodes.end()) {
        std::cout<<"loh"<<std::endl; //Вероника нашлась
        return;
    }
    nodes[parent].childs.push_back(nodeName); 
}

void Tree::addRoot(const std::string& rootName){
    if(root!= "")nodes[rootName].childs.push_back(root);
    root = rootName;
}

ostream& operator<<(ostream& os, Tree& t){
    //ура победа победа
    cout<<"Root: "<<t.root<<endl;
    map<std::string, Node> :: iterator it = t.nodes.begin();
    for (int i = 0; it != t.nodes.end(); it++, i++) { 
        cout << "Parent: " << it->first<<endl;
        cout<<"Childs: ";
        for (int j = 0; j<t.nodes[it->first].childs.size(); j++){
            cout<< t.nodes[it->first].childs[j]<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    return os;
}