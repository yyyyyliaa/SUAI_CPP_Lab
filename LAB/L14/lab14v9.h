#pragma once

#include <string>
#include <vector>

class Farm{

private:

    std::vector <Animal> animals;

public:

    void addAnimal(Animal* x);

    void paintAnimals();

    void delAnimal();

    void showAnimals();

};

class Animal{

protected:
    int id;
    std::string name;
    size_t age;

public:
    void setId(int id);
    int getId();

    void setName(std::string name);
    std::string getName();

    void setAge(size_t age);
    size_t getAge();

    virtual void show() = 0;

    void baseShow();
};

class Goose: public Animal{

private:

    std::string pawColor;
    std::string wingColor;
    std::string bodyColor;

public:

    void show() override;

};

class Penguin: public Animal{

private:

    std::string bodyColor;

public:

    void show() override;

};

class Ostrich: public Animal{

private:

    std::string pawColor;
    std::string wingColor;

public:

    void show() override;

};