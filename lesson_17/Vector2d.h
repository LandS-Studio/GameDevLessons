#pragma once
/*
Створити Vector2d(аналог математичного двовимірного вектора) з двома полями даних: float x, y зі значення по замовчуванню 0.0; 0.0;
реалізувати 
a. operator=;

b. Vector2d operator+(const Vector2d& secondVector), Vector2d operator-(const Vector2d& secondVector) : відповідні компоненти двох векторів додаються/віднімаються, та повертається новий вектор; 

c. float& operator[](std::size_t idx): для індексу 0 - повертає x, для значення 1 - повертає y;

d. Реалізувати метод для виводу вектора у консоль у форматі {x; y}

Приклад використання: Vector2d testVec{1.2, 5.6}; std::cout << testVec << std::endl; // Output: {1.2; 5.6}

e. Реалізувати підрахунок створених об’єктів(інстенсів) класу Vector2d (ті, що були створені та ще не видалені); Публічний константний метод класу для отримання кількості активних(живих) інстенсів.

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

f. Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector), Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) як дружні функції;

g. void operator*=(float scalar) : операція множення вектора на скаляр (https://ua.onlinemschool.com/math/library/vector/multiply3/)

h. float operator()() : повертає довжину вектора; (https://ua.onlinemschool.com/math/library/vector/)

i. Метод для вводу(інпуту) вектора у форматі x y (координати через пробіл) :

Приклад використання: std::cin >> testVec; 
*/
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2d {
public:
    float x, y;

    Vector2d(float x = 0.0, float y = 0.0);

    Vector2d& operator=(const Vector2d& other);
    
    float& operator[](std::size_t idx);

    void operator*=(float scalar);

    float operator()() const;

    friend std::ostream& operator<<(std::ostream& out, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& in, Vector2d& vector);
    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    static int getInstancesCount();

private:
    static int instancesCount;
};

#endif // VECTOR2D_H
