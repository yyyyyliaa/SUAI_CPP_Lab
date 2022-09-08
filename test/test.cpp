#include <string.h>
#include <iostream>
using namespace std;

class vector_t{
private:
    int size;
    int* data;
public:
    vector_t();
    ~vector_t();
    vector_t(int s);
};

vector_t::vector_t(){
    size = 0;
    data = NULL;
}
vector_t::vector_t(int s){
    size = s;
    data = new int[size];
}
vector_t::~vector_t(){
    delete[] data;
    size = 0;
    data = NULL;
}

typedef struct date_s{
    int day;
    int month;
    int year;
};

void sort(int* arr, int size){

}

int main(int argc, char const *argv[]){
    //vector_t v(3);

    // int a[] ={2, 8, 0, 8};
    // int b[]={2, 8, 0};
    // int c = memcmp(a, b, sizeof(int)*2);
    // cout<<c<<endl;
    

    // char d[]="lohh";
    // char g[]="looohhh";
    // cout<<strncmp(d, g, sizeof(char)*3)<<endl;


    return 0;
}
