#include <iostream>
using namespace std;

void swapp(void* pa, void* pb, size_t n){
    char* a = (char*)pa;
    char* b = (char*)pb;
    for (size_t i = 0; i<n; i++){
        char tmp = *(a+i);
        *(a+i)=*(b+i);
        *(b+i) = tmp;
    }
}

int comp(const void* a, const void* b){
    int* pa = (int*)a;
    int* pb = (int*)b;
    return (*pa-*pb);
}

void sortt(void* ar, size_t size, size_t sizeElem, int (*comp)(const void*, const void*)){
    char* arr = (char*)ar;
    for(int i = 0; i< size; i++){
        for(int j = 0; j<size-i-1; j++){
            if (comp(arr+j*sizeElem, arr+(j+1)*sizeElem)>0){ 
                swapp(arr+j*sizeElem, arr+(j+1)*sizeElem, sizeof(int));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    unsigned long long int n = 1;
    int arr[] = {2, 4,1, 9};
    for (int i = 0; i<4; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //char* ar = (char*)arr;
    // swapp(arr+1*sizeof(int), arr+2*sizeof(int), sizeof(int));
    sortt(arr, 4, sizeof(int), comp);
    for (int i = 0; i<4; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
