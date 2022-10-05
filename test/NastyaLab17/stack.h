#pragma once
#include<ostream>
#include<iostream>
#include"exe.h"
using namespace std;

// template <class T>
// class node{
//     private:
//         T value;
//         node* prev; 
    
//     public:
//         node(T value, node* prev) : value(value), prev(prev) {} 

// };



// template<class T>
// class stack{
// private:
//     node* top = nullptr;
//     size_t count = 0;

// public:
//     stack();
//     void push(T value);
//     T pop();
//     friend std::ostream& operator<<(std::ostream& out, stack& st);
//     size_t size() // ����������� ���������
//     { 
//         return count; 
//     }  
// };

// stack::stack() {
//     top = nullptr;
//     count = 0;
// }

// void stack::push(T value){ 
//     top = new node(value, top);
//     count++;
// }

// T stack::pop(){  
//     if (count == 0)
//         throw (Exception("Queue is empty\n"));

//     count--;
//     node* tmp = top;
//     T value = tmp->value;
//     top = tmp->prev;
//     delete tmp;

//     return value;
// }

// void stack::clear(){
//     while (top) { 
//         node* tmp = top;
//         top = tmp->prev;
//         delete tmp;
//     }
//     count = 0;
// }

// void stack::clear(){
//     while (top) { 
//         node* tmp = top;
//         top = tmp->prev;
//         delete tmp;
//     }
//     count = 0;
// }

// std::ostream& operator<<(std::ostream& out, stack& st){
//     node* tmp = st.top;
//     while (tmp) {
//         out << tmp->value;
//         tmp = tmp->prev;
//         if (tmp) out << " ";
//     }
//     return out;
// }

// stack::~stack() { 
//     //clear();
//      delete[] top;
// } 

// size_t stack::size(){ 
//     return count; 
// }  
