/*Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    insert(const T& value)
    bool find(const T& value)
    size() возвращает количество элементов в множестве
    set union(const set& s) --- объединение (бросает исключение при объединении с пустым множеством)
    operator<< для вывода*/

//считать множество из файла

#include "l17v10.h"
// #include <iostream>

using namespace std;

void doWriteInt(){
    set<int> set1;
    set1.insert(1);
    set1.insert(6);
    set1.insert(3);
    set1.insert(1);
    set1.insert(2);

    set1.saveToFile("f.json");
}

void doReadInt(){
    set<int> set1;
    set1.loadFromFile("f.json");
    cout<<set1;
}

void doWriteString(){
    set<std::string> set2;
    set2.insert("AAA");
    set2.insert("BBBB");
    set2.insert("BB");
    set2.insert("CCCC");
    set2.insert("CCCC");
    set2.insert("C");

    set2.saveToFile("f.json");
}

void doReadString(){
    set<std::string> set2;
    set2.loadFromFile("f.json");
    cout<<set2;
}

void doWritePoint(){
    set<point> set3;
    set3.insert({1, 2, 3});
    set3.insert({1, 5, 3});
    set3.insert({9, 2, 7});
    set3.insert({8, 2, 8});

    set3.saveToFile("f.json");
}

void doReadPoint(){
    set<point> set3;
    set3.loadFromFile("f.json");
    cout<<set3;
}

int main(){
    // doWriteInt();
    // doReadInt();

    // doWriteString();
    // doReadString();

    // doWritePoint();
    // doReadPoint();



    return 0;
}