#include <iostream>
#include <string>

using namespace std;

class MyException {
private:
    std::string p_message;

public :
    MyException(const std::string& m);
    std::string get();
};

std::string MyException::get(){
    return p_message;
}

MyException::MyException(const std::string& m){
    p_message = m;
}

template <typename T>
void reflecyion(T *arr, int size){
    if (size%2==1){
        throw MyException ( "odd number of elements" );
    }
    T t;
    for (int i=0; i<(size/2); i++ ){
        t=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=t;
    }
}