/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (5 балів)

1. Функція приймає число — кількість чисел для вводу юзеру.
Порахувати кількість введених юзером додатних чисел, від’ємних та 0. Вивести у консоль ці лічильники;
Example input: 5  1 2 -2 0 0
Output: Positive: 2, negative: 1, zeroes: 2

2. Функція int factorial(int count) приймає число - count! Написати функції, які обраховують значення факторіала:
- за допомогою цикла;
- з використанням рекурсії;
- від найменшого до найбільшого за допомогою рекурсії;

3. Функції обрахунку площі та довжини кола: float getArea(float radius), float getCircumference(float radius);

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

4. Функція для друкування перших N натуральних чисел: void printNaturalNumbers(int count);
- від найбільшого до найменшого за допомогою цикла;
- від найменшого до найбільшого за допомогою цикла;
- від найбільшого до найменшого за допомогою рекурсії;

5. Винести декларації та дефінішини циклічних функцій в окрему пару header/cpp файл,
а також рекурсивні функції в окрему пару header/cpp файл.

*/
#include "LoopFunctions.h"
#include "RecursiveFunctions.h"
#include <iostream>

const double M_PI = 3.14159265358979323846;

// For STEP 3
// Function for calculating the area of a circle
float getArea(float radius) {
    return M_PI * radius * radius; //π * r^2
}

// Function for calculating the length of a circle
float getCircumference(float radius) {
    return 2 * M_PI * radius; //2 * π * r
}

int main() {
    int num = 0;
    
    //STEP 1
    num = 0;

    while (num <= 0){
        std::cout << "How many numbers to enter?" << std::endl;
        std::cin >> num;
        if (num < 0){
            std::cout << "Please enter a positive number" << std::endl;
        }
    }
    countNumbers(num);
    std::cout << std::endl;

    //STEP 2
    num = 0;
    
    while (num <= 0){
        std::cout << "Enter a number to calculate the factorial: ";
        std::cin >> num;
        if (num < 0){
            std::cout << "Please enter a positive number" << std::endl;
        }
    }
    std::cout << "Factoring with a loop: " << factorialIterative(num) << std::endl;
    std::cout << "Factorial using recursion: " << factorialRecursive(num) << std::endl;
    std::cout << std::endl;
 
    //STEP 3
    double radius = -1;

    while (radius < 0){
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;
        if (radius < 0){
            std::cout << "The radius cannot be negative" << std::endl;
        }
    }
    std::cout << "Circle area: " << getArea(radius) << std::endl;
    std::cout << "Circle lengh: " << getCircumference(radius) << std::endl;
    
    std::cout << std::endl;

    //ADDITIONAL
    //STEP 4
    int N = 0;

    while (N <= 0){
        std::cout << "Enter the number of numbers to print: ";
        std::cin >> N;
        if (N < 1){
            std::cout << "Please enter positive number" << std::endl;
        }
    }
    std::cout << "From largest to smallest (loop): ";
    printNumbersLargeToSmallLoop(N);

    std::cout << "From smallest to largest (loop): ";
    printNumbersSmallToLargeLoop(N);

    std::cout << "From largest to smallest (recursion): ";
    printNaturalNumbersLargeToSmallRecursion(N);
    std::cout << std::endl;

    return 0;
}

