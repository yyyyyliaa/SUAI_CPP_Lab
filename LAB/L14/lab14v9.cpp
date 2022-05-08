#include "lab14v9.h"
#include <iostream>

using namespace std;



void Farm::addAnimal(Animal* x){
    animals.push_back(*x);
}

void Farm::showAnimals(){
    for (int i = 0; i< animals.size(); i++){
        animals[i].show();
    }
}

void Animal::baseShow(){
    cout<< "id: "<< id<<endl;
    cout<< "name: "<<name<<endl;
    cout<< "age: "<< age<< endl;
}

void Goose::show(){
    baseShow();
    cout<< "paw color: "<< pawColor<< endl;
    cout<< "wing color: "<< wingColor<< endl;
    cout<< "body color: "<< bodyColor<<endl;
}


// id:
// name:
// age:
// paw color:
// wing color:
// body color: