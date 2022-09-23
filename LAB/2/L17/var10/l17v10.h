/*Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    insert(const T& value)
    bool find(const T& value)
    size() возвращает количество элементов в множестве
    set union(const set& s) --- объединение (бросает исключение при объединении с пустым множеством)
    operator<< для вывода*/



#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;
#include "json.hpp"
using json = nlohmann::json;


template <class T> class set{

private:
    T* arr;
    size_t p_size;
public:
    set();
    set(const set& s);
    set& operator=(const set& s);
    void insert(const T& value);
    void unit(const set& s);
    bool find(const T& value);
    size_t size();
    ~set();
    void saveToFile(const std::string& fileName);
    void loadFromFile(const std::string& fileName);

    template<class T1>
    friend std::ostream& operator <<(std::ostream& os, const set<T1>& s);


};


struct point {
    int x;
    int y;
    int z;

    friend ostream& operator<<(ostream& os, const point& p) {
        os << "( " << p.x << " " << p.y << " " << p.z << ")";
        return os;
    }

};

bool operator==(const point& lhs, const point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator>(const point& lhs, const point& rhs) {
    return (lhs.x*lhs.x+lhs.y*lhs.y+lhs.z*lhs.z) == (rhs.x*rhs.x+rhs.y*rhs.y+rhs.z*rhs.z);
}

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(point, x, y, z)

template <class T>
void set<T>::saveToFile(const std::string& fileName){
    std::ofstream file(fileName);
    json o;
    o["count"] = p_size;
    for (size_t i = 0; i < p_size; i++)
        o["content"].push_back(arr[i]);

    file << o;
    file.close();
}

template <class T>
void set<T>::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    json j;
    file >> j;
    p_size = j["count"];
    arr = (T*)malloc(sizeof(T)*p_size);
    for (size_t i = 0; i < p_size; i++)
    {
        arr[i] = j["content"][i];
    }

    file.close();
}

class MyException {
private:
    std::string p_message;
public:
    MyException(const std::string& m);
    std::string get();
};
 
std::string MyException::get(){
    return p_message;
}

MyException::MyException(const std::string& m){
    p_message = m;
}


template <class T> 
set<T>::set() {
    arr = NULL;
    p_size = 0;
}


template <class T> 
set<T>::set(const set& s) {
    p_size = s.p_size;
    arr = (T*)malloc(sizeof(size_t)*p_size);
    for(size_t i = 0; i<p_size; i++){
        arr[i] = s.arr[i];
    }
}

template <class T>
set<T>::~set(){
    free(arr);
    p_size = 0;
}

template <class T>
size_t set<T>::size(){
    return p_size;
}

template <class T>
set<T>& set<T>::operator=(const set& s) {
    if (&s == this) return *this;
    delete[] arr;
    p_size = s.p_size;
    arr = (T*)malloc(sizeof(T)*p_size);
    for (size_t i = 0; i < p_size; i++)
      arr[i] = s.arr;
}

bool operator<(const std::string &s1, const std::string &s2) {
  return s1.compare(s2) < 0;
}

bool operator>(const std::string &s1, const std::string &s2) {
  return s1.compare(s2) > 0;
}

template <class T>
void sort(T* a, size_t size) {
    for (size_t i = 0; i<size; i++){
        for (size_t j = size-1; j>i; j--){
            if(a[j-1]>a[j]){
                T tmp= a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
            }
        }
    }

}

template <class T>
void set<T>::insert(const T& value) {

    if (p_size == 0) {
        arr = (T*)malloc(sizeof(T)*1);
        arr[0] = value;
        p_size++;
    }

    else {
        int flag = 0;  

        for (size_t i = 0; i < this->p_size; i++){
            if(value == this->arr[i]){
                flag = 1; 
                return;
            }
        }
        if (flag!=1){
            T* arr2 = (T*)malloc(sizeof(T)*(p_size+1));
            for (size_t i = 0; i<p_size; i++){
                arr2[i] = arr[i];
            }
            arr2[p_size]=value;
            p_size++;
            sort(arr2, p_size);
            arr = arr2;
        }
    }
}

template <class T>
bool set<T>::find(const T& value){
    for (size_t i = 0; i< p_size; i++){
        if (arr[i]==value){
            return true;
        }
    }
    return false;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const set<T>& s){
    os << "{";
    for (size_t i = 0; i < s.p_size; i++)
        os << s.arr[i] << ", ";
    os << "}";
    return os;
}

template <class T>
void set<T>::unit(const set& s){
    if (s.p_size==0)
        throw MyException("The set is empty!!!");
    
    for (size_t i = 0; i<s.p_size; i++){ 
        if(this->find(s.arr[i])==false)
            this->insert(s.arr[i]);
    }
}

