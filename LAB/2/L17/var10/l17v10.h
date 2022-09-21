/*Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
    insert(const T& value)
    bool find(const T& value)
    size() возвращает количество элементов в множестве
    set union(const set& s) --- объединение (бросает исключение при объединении с пустым множеством)
    operator<< для вывода*/

#pragma once

#include <string>
#include <iostream>

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

    template<class T1>
    friend std::ostream& operator <<(std::ostream& os, const set<T1>& s);


};


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
    if (s.p_size==0){
        throw MyException("The set is empty!!!");
    }
    for (size_t i = 0; i<s.p_size; i++){ 
        if(this->find(s.arr[i])==false)
            this->insert(s.arr[i]);
    }
    
}