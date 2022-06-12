#include <iostream>
#include "L12.h"
using namespace std;

int main(){
    
    int size;
    cout<<"Enter size of set1: ";
    cin>>size;

    int* set = (int*)malloc(sizeof(int)*size);
    
    cout<<"Enter the elements of set1: "<< endl;
    for (int i =0; i<size; i++){
        cin>>set[i];
    }

    IntSet set1(set, size);

    // cout<<"Enter size of set2: ";
    // cin>>size;

    // set = (int*)realloc(set ,sizeof(int)*size);
    
    // cout<<"Enter the elements of set2: "<< endl;
    // for (int i =0; i<size; i++){
    //     cin>>set[i];
    // }

    // IntSet set2(set, size);

    // int n;

    // set1.unitSets(set2);
    // cout<<"After unite:"<<endl;   
    // set1.printSet();
    // cout<<endl;

    // cout<<"Enter number for del: ";
    // cin>>n;
    // cout<<"After delete:"<<endl;
    // set1.delNumber(n);
    // set1.printSet();
    // cout<<endl;

    // cout<<"Enter number for add: ";
    // cin>>n;
    // cout<<"After add:"<<endl;
    // set1.addNumber(n);
    // set1.printSet();
    // cout<<endl;

    // cout<<"After sub:"<<endl;
    // set1.subSets(set2);
    // set1.printSet();

    int sizemas;
    cout<<"Enter size of mas: ";
    cin>>sizemas;
    
    IntSet* mas=(IntSet*)malloc(sizeof(IntSet)*sizemas);

    for (int j=0; j<sizemas; j++){
        cout<<"Enter size of set: ";
        cin>>size;

        int* set = (int*)malloc(sizeof(int)*size);

        set = (int*)realloc(set ,sizeof(int)*size);
    
        cout<<"Enter the elements of set:"<< endl;
        for (int i =0; i<size; i++){
            cin>>set[i];
        }

        IntSet settmp(set, size);

        mas[j]=settmp;
    }


    cout<<"After unit set and mas"<<endl;
    set1.unitmas(mas, sizemas);
    set1.printSet();

    free(set);
    
    return 0;
}

