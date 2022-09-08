/*Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    insert(const T& value)
    erase(const T& value) (бросает исключение на пустом множестве)
    bool find(const T& value)
    size
    clear
    operator<< для вывода*/


#include "lab17.h"
#include <iostream>

using namespace std;

int main(){
    set<int> set1;
    set1.insert(1);
    set1.insert(6);
    set1.insert(3);
    set1.insert(1);
    set1.insert(2);

    cout<<set1<<endl;

    // set1.erase(1);

    cout<<set1<<endl;

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

    cout<<set2<<endl;

    // set<int> set3;
    // try{
    //     set3.erase(1);
    // }
    // catch (MyException& e) {
    //     std::cout << e.get(); 
    // }

    return 0;
}

