/*
Реалізовано можливість приготування Cappuccino:
Розширено клас DrinkProgram, реалізувавши метод prepareCappuccino() з перевірками рівнів молока та води та зіпсованого молока
Реалізовано заготовку класу MilkReservoir як один з необхідних компонентів при приготуванні Cappuccino
Розширено клас CoffeeMachine, додавши можливість доступу до MilkReservoir та відображення помилки про недостатній рівень молока
Розширено DrinkProgramStatus для відображення помилки про зіпсоване молоко
Реалізовано запис дати останнього наповнення молока в файл last_milk_fill_date.txt та методи для отримання поточної дати та дати останнього наповнення молока

Для зручності місця де було змінено код позначено як TODO UPDATED
*/

#include "CoffeeMachine.h"

int main()
{
    CoffeeMachine machine;
    
    machine.initDefaultDrinks();    //available drinks

    while (machine.IsBooted())
    {
        machine.showMenu();
        machine.receiveInput();
        machine.update();
    }

    return 0;
}
