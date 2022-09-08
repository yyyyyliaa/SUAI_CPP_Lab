#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class vector_t{
private:
    size_t size;
    int* data;
public:
    vector_t();

    vector_t(vector_t& v);
    ~vector_t();

    void push_back(int val);
    vector_t& operator=(const vector_t& v);
    friend ostream& operator<<(ostream& os, vector_t& v);
};

vector_t::vector_t(){
    size = 0;
    data = NULL;
}

vector_t::~vector_t(){
    free(data);
}

vector_t::vector_t(vector_t& v){
    size = v.size;
    data =(int*)malloc(sizeof(int)*size);
    for (int i = 0; i< size; i++){
        data[i]=v.data[i];
    }
}

vector_t& vector_t::operator=(const vector_t& v){
    if(&v==this) return *this;
    size = v.size;
    free(data);
    data = (int*)malloc(sizeof(int)*size);
    for (int i = 0; i<size; i++){
        data[i]=v.data[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, vector_t& v){
    for(int i = 0; i<v.size; i++){
        os<<v.data[i]<<" ";
    }
    return os;
}

void vector_t::push_back(int val){
    size++;
    data = (int*)realloc(data, size);
    data[size-1]=val;
}

int main(int argc, char const *argv[]){
    vector_t v;
    v.push_back(2);
    v.push_back(5);
    cout<<v;

    return 0;
}
