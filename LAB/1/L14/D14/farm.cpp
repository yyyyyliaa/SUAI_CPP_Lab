#include "farm.h"
#include "colors.h"
#include <iostream>

using namespace std;

//ANIMAL
int Animal::getId(){
    return this->id;
}

void Animal::baseShow(){
    cout<<"consumption: "<<consumption<<endl;
    cout<< "id: "<< id<<endl;
    cout<< "name: "<<name<<endl;
    cout<< "age: "<< age<< endl;
}

void Animal::genId(){
    static int globalId = 0;
    id = globalId;
    globalId++;
}

//FARM
Farm::Farm(int food){
    this->food = food;
}

void Farm::feedAnimals(){
    for (int i = 0; i< animals.size(); i++){
        int tmp = animals[i]->feed(this->food);
        this->takeFood(tmp);
    }
}

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

void Farm::delAnimal(int x){
    for (int i = 0; i< animals.size(); i++){
        if (animals[i]->getId()==x) animals.erase(animals.begin()+i);
    }
}

void Farm::setFood(int food){
    this->food = food;
}

int Farm::getFood(){
    return this->food;
}

void Farm::restockFood(int x){
    this->food+=x;
}

void Farm::takeFood(int x){
    if (this->food>x) this->food-=x;
    else cout<<"Not enough food"<<endl;
}
//GOOSE
Goose::Goose(size_t age, std::string name, int consumption, std::string pawColor, std::string wingColor, std::string bodyColor, int id){
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

    if (consumption==0) this->consumption = 10;
    else if (consumption<0) this->consumption = consumption*(-1);
    else this->consumption = consumption;
}

void Goose::show(){
    cout<<"type: Goose"<<endl;
    baseShow();
    cout<< "paw color: "<< pawColor<< endl;
    cout<< "wing color: "<< wingColor<< endl;
    cout<< "body color: "<< bodyColor<<endl;

}

void Goose::paint(){
    pawColor = COLORS[rand()%COLORS.size()];
    wingColor = COLORS[rand()%COLORS.size()];
    bodyColor = COLORS[rand()%COLORS.size()];
}

//PENGUIN
Penguin::Penguin(size_t age, std::string name, int consumption, std::string bodyColor, int id){
    if (id==-1) genId();
    else this->id = id;
    this->age = age;
    this->name = name;

    if (bodyColor=="null") this->bodyColor = COLORS[rand()%COLORS.size()];
    else this->bodyColor = bodyColor;

    if (consumption==0) this->consumption = 50;
    else if (consumption<0) this->consumption = consumption*(-1);
    else this->consumption = consumption;
}

void Penguin::show(){
    cout<<"type: Penguin"<<endl;
    baseShow();
    cout<< "body color: "<< bodyColor<<endl;
}

void Penguin::paint(){
    bodyColor = "Black";
}

//OSTRICH
Ostrich::Ostrich(size_t age, std::string name, int consumption, std::string pawColor, std::string wingColor, int id){
    if (id==-1) genId();
    else this->id = id;

    this->age = age;
    this->name = name;

    if (pawColor=="null") this->pawColor = COLORS[rand()%COLORS.size()];
    else this->pawColor = pawColor;

    if (wingColor=="null") this->wingColor = COLORS[rand()%COLORS.size()];
    else this->wingColor = wingColor;

    if (consumption==0) this->consumption = 100;
    else if (consumption<0) this->consumption = consumption*(-1);
    else this->consumption = consumption;
}

void Ostrich::show(){
    cout<<"type: Ostrich"<<endl;
    baseShow();
    cout<< "paw color: "<< pawColor<< endl;
    cout<< "wing color: "<< wingColor<< endl;

}

void Ostrich::paint(){
    pawColor = wingColor;
}



int Goose::feed(int food){
    if ((food-=this->consumption)>0)
       return this->consumption;

    else {
        cout<<"Not enough food for an animal with ID "<<this->id<<endl;
        return 0;
    }
}

int Penguin::feed(int food){
    if ((food-=this->consumption)>0)
       return this->consumption;

    else {
        cout<<"Not enough food for an animal with ID "<<this->id<<endl;
        return 0;
    }
}

int Ostrich::feed(int food){
    if ((food-=this->consumption)>0)
       return this->consumption;

    else {
        cout<<"Not enough food for an animal with ID "<<this->id<<endl;
        return 0;
    }
}














