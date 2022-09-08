#include <iostream>
#include <stdlib.h>

class node_t{
private:
    int val;
    node_t* next;
public:
    node_t(int val);

    node_t* getNext();
    void setNext(node_t* n);
    int getVal();
};

class list_t {
private:
    int size;
    node_t* head;
public:
    list_t();
    ~list_t();
    list_t(list_t& l);

    void push_back(node_t* n);
    void push_back(int val);
    list_t& operator=(list_t& l);

};

list_t& list_t::operator=(list_t& l){
    if(&l==this) return *this;
    this->~list_t();
    size = l.size;
    node_t* cur = l.head;
    node_t* cur2 = NULL;
    if (cur!=NULL){
        cur2 = new node_t(cur->getVal());
        head = cur2;
        cur = cur->getNext();
    }
    while(cur!=NULL){
        node_t* tmp = new node_t(cur->getVal());
        cur2->setNext(tmp);
        cur = cur->getNext();
        cur2 = tmp;
    }
    return *this;
}

node_t::node_t(int v){
    val = v;
    next = NULL;
}

int node_t::getVal(){
    return val;
}

list_t::list_t(list_t& l){
    size = l.size;
    node_t* cur = l.head;
    node_t* cur2 = NULL;
    if (cur!=NULL){
        cur2 = new node_t(cur->getVal());
        head = cur2;
    }
    for (int i =1; i<size; i++){
        cur = cur->getNext();
        node_t* tmp = new node_t(cur->getVal());
        cur2->setNext(tmp);
        cur2 = tmp;
    }
}

node_t* node_t::getNext(){
    return next;
}

void node_t::setNext(node_t* n){
    next = n;
}


list_t::list_t(){
    size = 0;
    head = NULL;
}

list_t::~list_t(){
    node_t* tmp = head;
    while(tmp!=NULL){
        node_t* tmp2 = tmp->getNext();
        delete tmp;
        tmp = tmp2;
    }
    head = NULL;
    size = 0;
}

void list_t::push_back(node_t* n){
    if (head!=NULL){ 
        node_t* cur = head;
        while(cur->getNext()!=NULL){
            cur = cur->getNext();
        }
        cur->setNext(n);
    }
    else head = n;
}

void list_t::push_back(int val){
    node_t* n = new node_t(val);    
    if (head!=NULL){ 
        node_t* cur = head;
        while(cur->getNext()!=NULL){
            cur = cur->getNext();
        }
        cur->setNext(n);
        size++;
    }
    else{
        head = n;
        size++;
    }
}


int main(int argc, char const *argv[]){
    list_t l;
    l.push_back(2);
    l.push_back(5);
    list_t t(l);
    t.push_back(6);
    t = l;


    return 0;
}

