#include "farm.h"
#include "colors.h"
#include <iostream>

using namespace std;



void Farm::addAnimal(Animal* x){
    animals.push_back(x);
}

void Farm::showAnimals(){
    for (int i = 0; i< animals.size(); i++){
        animals[i]->show();
        cout<<endl;
    }
}

void Farm::paintAnimals(){
    for (int i = 0; i< animals.size(); i++){
        animals[i]->paint();
    }
}

int Animal::getId(){
    return this->id;
}


void Farm::delAnimal(int x){
    for (int i = 0; i< animals.size(); i++){
        if (animals[i]->getId()==x) animals.erase(animals.begin()+i);
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

void Penguin::show(){
    baseShow();
    cout<< "body color: "<< bodyColor<<endl;
}

void Ostrich::show(){
    baseShow();
    cout<< "paw color: "<< pawColor<< endl;
    cout<< "wing color: "<< wingColor<< endl;

}

void Goose::paint(){
    pawColor = COLORS[rand()%COLORS.size()];
    wingColor = COLORS[rand()%COLORS.size()];
    bodyColor = COLORS[rand()%COLORS.size()];
}

void Penguin::paint(){
    bodyColor = "Black";
}

void Ostrich::paint(){
    pawColor = wingColor;
}

void Animal::genId(){
    static int globalId = 0;
    id = globalId;
    globalId++;
}

Ostrich::Ostrich(size_t age, std::string name, std::string pawColor, std::string wingColor, int id){
    if (id==-1) genId();
    else this->id = id;
    this->age = age;
    this->name = name;
    if (pawColor=="null") this->pawColor = COLORS[rand()%COLORS.size()];
    else this->pawColor = pawColor;
    if (wingColor=="null") this->wingColor = COLORS[rand()%COLORS.size()];
    else this->wingColor = wingColor;
}

Goose::Goose(size_t age, std::string name, std::string pawColor, std::string wingColor, std::string bodyColor, int id){
    if (id==-1) genId();
    else this->id = id;
    this->age = age;
    this->name = name;
    if (pawColor=="null") this->pawColor = COLORS[rand()%COLORS.size()];
    else this->pawColor = pawColor;

    if (wingColor=="null") this->wingColor = COLORS[rand()%COLORS.size()];
    else this->wingColor = wingColor;

    if (bodyColor=="null") this->bodyColor = COLORS[rand()%COLORS.size()];
    else this->bodyColor = bodyColor;
}

Penguin::Penguin(size_t age, std::string name, std::string bodyColor, int id){
    if (id==-1) genId();
    else this->id = id;
    this->age = age;
    this->name = name;

    if (bodyColor=="null") this->bodyColor = COLORS[rand()%COLORS.size()];
    else this->bodyColor = bodyColor;
}