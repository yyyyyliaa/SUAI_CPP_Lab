/*Реализовать дерево, где у узла может быть несколько детей (т.е. может быть недвоичное дерево). 
Использовать map<std::string, Node>, т.е. каждый узел в дереве характеризуется строкой. Node хранит список детей.
    addRoot(const std::string& rootName)
    addNode(const std::string& parent,  const std::string& nodeName)
    operator<< для вывода на экран*/

#include "lab18.h"
#include <string>
#include <iostream> //бля хуй 

using namespace std;

int main(){
    Tree derevo;
    derevo.addRoot("Yulia");
    derevo.addNode("Yulia", "Veronika");
    derevo.addRoot("Anya"); //вЕРОНИКА ПРОПАЛА
    cout<<derevo;

    return 0;
}