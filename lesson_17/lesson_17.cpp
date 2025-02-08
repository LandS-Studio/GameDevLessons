/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (4 бали)
Створити Vector2d(аналог математичного двовимірного вектора) з двома полями даних: float x, y зі значення по замовчуванню 0.0; 0.0; реалізувати 
a. operator=;
b. Vector2d operator+(const Vector2d& secondVector), Vector2d operator-(const Vector2d& secondVector) : відповідні компоненти двох векторів додаються/віднімаються, та повертається новий вектор; 
c. float& operator[](std::size_t idx): для індексу 0 - повертає x, для значення 1 - повертає y;
d. Реалізувати метод для виводу вектора у консоль у форматі {x; y}
e. Реалізувати підрахунок створених об’єктів(інстенсів) класу Vector2d (ті, що були створені та ще не видалені); Публічний константний метод класу для отримання кількості активних(живих) інстенсів.

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)
f. Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector), Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) як дружні функції;
g. void operator*=(float scalar) : операція множення вектора на скаляр (https://ua.onlinemschool.com/math/library/vector/multiply3/)
h. float operator()() : повертає довжину вектора; (https://ua.onlinemschool.com/math/library/vector/)
i. Метод для вводу(інпуту) вектора у форматі x y (координати через пробіл) :

Приклад використання: std::cin >> testVec; 
*/
#include <iostream>
#include "Vector2d.h"

int main() {
    // Create two vectors
    Vector2d testVec1;
    Vector2d testVec2;

    // i)
    std::cin >> testVec1;
    std::cin >> testVec2;
    std::cout << std::endl;

    // d)
    // Output two vectors to the console
    std::cout << testVec1 << std::endl; // Output: {1.2; 5.6}
    std::cout << testVec2 << std::endl; // Output: {3.4; 7.8}
    std::cout << std::endl;

    // e)
    // Calculate the number of created objects
    std::cout << "Instances count: " << Vector2d::getInstancesCount() << std::endl; // Output: 2
    std::cout << std::endl;

    // b) f)
    // Add two vectors
    Vector2d sumVec = testVec1 + testVec2;
    std::cout << sumVec << std::endl; // Output: {4.6; 13.4}
    std::cout << std::endl;

    // b) f)
    // Subtract two vectors
    Vector2d subVec = testVec1 - testVec2;
    std::cout << subVec << std::endl; // Output: {-2.2; -2.2}
    std::cout << std::endl;

    // Calculate the number of created objects
    std::cout << "Instances count: " << Vector2d::getInstancesCount() << std::endl; // Output: 4
    std::cout << std::endl;

    // c)
    // Check the operation of the operator [] on all vectors
    std::cout << testVec1[0] << std::endl; // Output: 1.2
    std::cout << testVec1[1] << std::endl; // Output: 5.6
    std::cout << testVec2[0] << std::endl; // Output: 3.4
    std::cout << testVec2[1] << std::endl; // Output: 7.8
    std::cout << sumVec[0] << std::endl; // Output: 4.6
    std::cout << sumVec[1] << std::endl; // Output: 13.4
    std::cout << subVec[0] << std::endl; // Output: -2.2
    std::cout << subVec[1] << std::endl; // Output: -2.2
    std::cout << std::endl;

    // g)
    // Check the operation of the operator *=
    testVec1 *= 2;
    std::cout << testVec1 << std::endl; // Output: {2.4; 11.2}
    std::cout << std::endl;

    // h)
    // Check the operation of the operator () on all vectors
    std::cout << testVec1() << std::endl; // Output: 11.6619
    std::cout << testVec2() << std::endl; // Output: 8.60233
    std::cout << sumVec() << std::endl; // Output: 14.2829
    std::cout << subVec() << std::endl; // Output: 3.12136
    std::cout << std::endl;

    // a)
    // operator= test
    testVec1 = testVec2;
    std::cout << testVec1 << std::endl; // Output: {3.4; 7.8}
    std::cout << testVec2 << std::endl; // Output: {3.4; 7.8}
    
        
    return 0;
}
