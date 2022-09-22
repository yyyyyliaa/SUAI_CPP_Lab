/*Реализовать дерево, где у узла может быть несколько детей (т.е. может быть недвоичное дерево). 
Использовать map<std::string, Node>, т.е. каждый узел в дереве характеризуется строкой. Node хранит список детей.
    addRoot(const std::string& rootName)
    addNode(const std::string& parent,  const std::string& nodeName)
    operator<< для вывода на экран*/

//

#include "lab18.h"
#include <string>
#include <iostream> 

using namespace std;

int main(){
    Tree derevo;
    // derevo.addRoot("Yulia");
    // derevo.addNode("Yulia", "Veronika");
    // derevo.addNode("Yulia", "Katya");
    // derevo.addNode("Yulia", "Nastya");
    // derevo.addNode("Yulia", "Nastya");
    // derevo.addNode("Veronika", "Masha");
    // derevo.addRoot("Anya");
    // derevo.addNode("Anya", "Lera");

    derevo.addRoot("a");
    derevo.addNode("a", "b");
    derevo.addNode("b", "t");
    derevo.addNode("t", "s");
    derevo.addNode("s", "m");
    derevo.addNode("m", "v");
    // derevo.addNode("a", "y");
    // derevo.addNode("a", "k");
    // derevo.addNode("a", "o");
    
    cout<<derevo;
    // derevo.print("a", "    ");


    return 0;
}