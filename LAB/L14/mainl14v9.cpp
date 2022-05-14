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

#include "lab14v9.h"
#include <iostream>

using namespace std;

int main(){
    Farm sadFarm;
    Goose sadGoose(3, "Sergei");
    Penguin sadPenguin(13, "Yulia");
    Ostrich sadOstrich(0, "Denis");
    Ostrich sadPediator(176, "Anna");
    sadFarm.addAnimal(&sadGoose);
    sadFarm.addAnimal(&sadPenguin);
    sadFarm.addAnimal(&sadOstrich);
    sadFarm.addAnimal(&sadPediator);


    sadFarm.showAnimals();
    // sadFarm.paintAnimals();
    // sadFarm.showAnimals();

    sadFarm.delAnimal(1);
    cout<<endl;
    sadFarm.showAnimals();


}