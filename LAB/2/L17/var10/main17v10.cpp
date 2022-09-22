/*Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    insert(const T& value)
    bool find(const T& value)
    size() возвращает количество элементов в множестве
    set union(const set& s) --- объединение (бросает исключение при объединении с пустым множеством)
    operator<< для вывода*/

//считать множество из файла

#include "l17v10.h"
#include <iostream>

using namespace std;

int main(){
    set<int> set1;
    set1.insert(1);
    set1.insert(6);
    set1.insert(3);
    set1.insert(1);
    set1.insert(2);

    cout<<"set1: ";
    cout<<set1<<endl;

    cout<<"set1 size: ";
    cout<<set1.size()<<endl;

    cout << set1.find(4) << endl;
    cout << set1.find(1) << endl;
    cout << set1.find(2) << endl;

    set<std::string> set2;
    set2.insert("AAA");
    set2.insert("BBBB");
    set2.insert("BB");
    set2.insert("CCCC");
    set2.insert("CCCC");
    set2.insert("C");

    cout<<"set2: ";
    cout<<set2<<endl;

    set<int> set3;
    try{
        set1.unit(set3);
    }
    catch (MyException& e) {
        std::cout << e.get(); 
    }

    cout<<endl;

    set3.insert(5);
    set3.insert(1);
    set3.insert(11);
    set3.insert(6);

    cout<<"set3: ";
    cout<<set3<<endl;

    set1.unit(set3);
    cout<<"set1 after unit with set3: ";
    cout<<set1<<endl;

    return 0;
}