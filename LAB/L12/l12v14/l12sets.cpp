/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/

#include <iostream>
#include "l12sets.h"
#include <math.h>
using namespace std;

IntSet::IntSet(){
    int* set=(int*)malloc(sizeof(int)*size);

    setNumbers(set);
}

void IntSet:: setNumbers(int* set){
    for(int i = 0; i<size; i++){
        p_set[i] = set[i];
    }

}

int IntSet::check(int num){ //проверка на вхождение элемента в множество
    int result = 0;

    for(int i = 0; i<size; i++)
        if (p_set[i]==num) {
            result =  1; 
            break;
        }                      
                                                            
    return result;
}

void IntSet::addNumber(int num){ //добавление элемнта в первое множество
    int ch = check(num);    
    if(ch!=1){
        size++;
        p_set = (int*)realloc(p_set, sizeof(int)*(size));
        p_set[size-1] = num;
    }
}

void IntSet::delNumber(int num){  //удаление элемента из множества
    int ch = check(num);
    if (ch==1){
        for(int i = 0; i<size; i++){
            if(p_set[i]==num){
                for(int j=i; j<size; j++) 
                    p_set[j]=p_set[j+1];
                size--;
                p_set=(int*)realloc(p_set, sizeof(int)*size);

            }
        }
    }
    else cout<<"Number is not in the set"<<endl;
}

void mySort(int* array, int size){   //сортировка
    for (int i = 0; i<size; i++){
        for (int j = size-1; j>i; j--){
            if(array[j-1]>array[j]){
                int tmp= array[j-1];
                array[j-1]=array[j];
                array[j]=tmp;
            }
        }
    }
}

 
// void IntSet::uniteSet(){  //объединение множеств
//     int maxUnitSize= size1+size2;
//     unitSize= size1;
//     int j=size1;
//     for(int i = 0; i<size1; i++)
//         p_unitSet[i]=p_set1[i];
    
//     for(int i = 0; i<size2; i++){
//         int ch=check(p_set2[i]);
//         if(ch==2){
//             unitSize++;
//             p_unitSet=(int*)realloc(p_unitSet, sizeof(int)*unitSize);
//             p_unitSet[j]=p_set2[i];
//             j++;
//         }
//     }
//     //mySort(p_unitSet, unitSize);
// }


// void IntSet::firstSubSecond(){  //вычитание из первого множества второго
//     subSize = size1;                 //из первого множества вычитаются все эелементы, содержащиеся во втором множестве
//     int j = 0;
//     for(int i = 0; i<size1; i++){
//         int ch = check(p_set1[i]);
//         if(ch==1) {
//             p_subSet[j]=p_set1[i];
//             j++;
//         }
//         else subSize--;
//     }
// }

// void IntSet::secondSubFirst(){  //вычитание из второго множества первого
//     subSize = size2;
//     int j = 0;
//     for(int i = 0; i<size2; i++){
//         int ch = check(p_set2[i]);
//         if(ch!=3) {
//             p_subSet[j]=p_set2[i];
//             j++;
//         }
//         else subSize--;
//     }
// }

// void IntSet::printFirstSet(){
//     cout<<"[";
//     for(int i = 0; i<size1; i++)
//         cout<<p_set1[i]<<" ";
//     cout<<"]";
// }

// void IntSet::printSecondSet(){
//     cout<<"[";
//     for(int i = 0; i<size2; i++)
//         cout<<p_set2[i]<<" ";
//     cout<<"]";
// }

// void IntSet::printSubSet(){
//     cout<<"[";
//     for(int i = 0; i<subSize; i++)
//         cout<<p_subSet[i]<<" ";
//     cout<<"]";
// }

// void IntSet::printUnitSet(){
//     cout<<"[";
//     for(int i = 0; i<unitSize; i++)
//         cout<<p_unitSet[i]<<" ";
//     cout<<"]";
// }