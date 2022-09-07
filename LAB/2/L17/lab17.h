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
    void insert(const T& value);
    void erase(const T& value);
    bool find(const T& value);
    size_t size();
    void clear();
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
void set<T>::clear(){
    free(arr);
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

bool operator<(const std::string& s1, const std::string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size<0;
    return s1.compare(s2)<0;
}

bool operator>(const std::string& s1, const std::string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size>0;
    return s1.compare(s2)>0;
}

bool operator<=(const std::string& s1, const std::string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size<0;
    return s1.compare(s2)<=0;
}

bool operator>=(const std::string& s1, const std::string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size>0;
    return s1.compare(s2)>=0;
}

template <class T>
void set<T>::insert(const T& value) {

    if (p_size == 0) {
        this->arr = (T*)malloc(sizeof(T)*1);
        arr[0] = value;
        p_size++;
    }

    else {
        int flag = 0;

        for (size_t i = 0; i < this->p_size; i++){
            if(value == this->arr[i]){
                flag = 1; 
                break;
            }
        }
        if (flag!=1){

            T* arr2 = (T*)malloc(sizeof(T)*(p_size+1));
            int tmp = 0;
            for (size_t i = 0; i < p_size; i++){
                if (arr[i]<value && arr[i+1]>value){
                    tmp = i;
                }
            }
            
            for (size_t i = 0; i<=tmp; i++){
                arr2[i]=arr[i];
            }
            tmp++;
            arr2[tmp] = value;

            for (size_t i = tmp+1; i<p_size+1; i++){
                arr2[i]=arr[i-1];
            }

            arr=arr2;
            p_size++;
        }
    }
}

template <class T>
void set<T>::erase(const T& value) {
    if (p_size==0){
        throw MyException("The set is empty");
    }
    else{
        size_t index = 0;
        T* arr2 = (T*)malloc(sizeof(T)*(p_size-1));
        for(size_t i = 0; i<p_size; i++){
            if(arr[i]==value){
                index = i;
                break;
            }
            else{
                arr2[i] = arr[i];
            }
        }
        for (size_t i = index; i<p_size; i++){
            arr2[i]=arr[i+1];
        }
        arr=arr2;
        p_size--;
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
