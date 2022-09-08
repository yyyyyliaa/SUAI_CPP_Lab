#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* arr, int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){ 
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectSort(int* arr, int size){
    for(int j = 0; j<size; j++){
        int min = j;
        for (int i = j; i<size; i++){
            if(arr[i]<arr[min]) min=i;
        }
        swap(&arr[min], &arr[j]);
    }
}

void insertSort(int* arr, int size){
    for(int i = 1; i<size; i++){
        for(int j = i; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int arr[6]={1, 8, 11, 7, 2, 0};
    for (int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // bubbleSort(arr, 6);
    // for (int i = 0; i<6; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // selectSort(arr, 6);
    // for (int i = 0; i<6; i++){
    //     cout<<arr[i]<<" ";
    // }
    // insertSort(arr, 6);
    // for (int i = 0; i<6; i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}
