#include "CoffeeMachine.h"

int main()
{
    CoffeeMachine machine;
    
    machine.initDefaultDrinks();    //available drinks
    machine.powerOn();

    while (machine.IsBooted()){
        machine.showMenu();
        machine.receiveInput();
        machine.update();
    }

    return 0;
}
