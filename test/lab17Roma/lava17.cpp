// реализовать функцию, которая зеркально переварачивает массив. Если массив имеет нечетную нечетную длинну,
// то функция бросает исключение 


#include <iostream>

#include "lava17.h"

using namespace std;




int main() {
    int size=6;
    float mas[]={1.4, 2.3, 3.2, 4.1, 5.5, 2.7};
    try{
        reflecyion<float>(mas, size);
    }
    catch (MyException& e) {
        std::cout << e.get()<<endl; 
    }
    for(int i=0; i<size; i++)
        cout << mas[i] << " ";
    return 0;
}