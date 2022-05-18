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

#include "farm.h"
#include <iostream>

using namespace std;

int main(){
    Farm sadFarm(150);

    Goose sadGoose(3, "Sergei");
    // Goose happyGoose(0);
    Penguin sadPenguin(13, "Yulia");
    // Penguin happyPenguin(19, "Nastya");
    Ostrich sadOstrich(5, "Katya");
    // Goose funGoose(4, "Lera");

    
    sadFarm.addAnimal(&sadGoose);
    sadFarm.addAnimal(&sadPenguin);
    sadFarm.addAnimal(&sadOstrich);
    // sadFarm.addAnimal(&happyGoose);
    // sadFarm.addAnimal(&happyPenguin);
    // sadFarm.addAnimal(&funGoose);

    sadFarm.showAnimals();

    cout<<"Food: "<<sadFarm.getFood()<<endl;
    sadFarm.feedAnimals();
    cout<<"Food: "<<sadFarm.getFood()<<endl;

    sadFarm.restockFood(200);
    cout<<"Food: "<<sadFarm.getFood()<<endl;

    sadFarm.feedAnimals();
    cout<<"Food: "<<sadFarm.getFood()<<endl;

    // sadFarm.paintAnimals();
    // sadFarm.showAnimals();

    // sadFarm.delAnimal(0);
    // cout<<"Farm after del 0 animal"<<endl;
    // sadFarm.showAnimals();


}
//добавить "склад" гусь-1 страус-10 функция пополнить и забрать, функция покормить всех животных