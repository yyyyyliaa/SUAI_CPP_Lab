/*Сущности: 		
                    Гусь
данные: номер, кличка, возраст, цвет лап, цвет крыльев, цвет туловища.
действия: покрасить (покрасить все части тела	разными цветами).
                   Пингвин
данные: номер, кличка, возраст, цвет туловища.		
действия: покрасить (покрасить все части тела черным).
                    Страус			
данные: номер, кличка, возраст, цвет лап, цвет крыльев.	
действия: покрасить (покрасить лапы в цвет крыльев).	

Класс Farm: добавить животное, покрасить всех животных, удалить животное, показать всех животных.*/

#pragma once

#include <string>
#include <vector>

class Animal{

protected:
    void genId();
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

    virtual void paint() = 0;
};

class Farm{

private:

    std::vector <Animal*> animals;

public:

    void addAnimal(Animal* x);

    void paintAnimals();

    void delAnimal(int x);

    void showAnimals();

};
class Goose: public Animal{

private:

    std::string pawColor;
    std::string wingColor;
    std::string bodyColor;

public:

    Goose(size_t age = 0, std::string name = "", std::string pawColor = "null", std::string wingColor = "null", std::string bodyColor = "null", int id = -1);

    void show() override;

    void paint() override;

};

class Penguin: public Animal{

private:

    std::string bodyColor;

public:

    Penguin(size_t age = 0, std::string name = "", std::string bodyColor = "null", int id = -1);

    void show() override;

    void paint() override;

};

class Ostrich: public Animal{

private:

    std::string pawColor;
    std::string wingColor;

public:

    Ostrich(size_t age = 0, std::string name = "", std::string pawColor = "null", std::string wingColor = "null", int id = -1);

    void show() override;

    void paint() override;

};


