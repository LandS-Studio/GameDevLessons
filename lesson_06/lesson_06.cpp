/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (3 бали)
1. Зчитати з консолі три числа: перший елемент(a1), крок арифметичної прогресії(d), номер останнього елемента
арифметичної прогресії(n) (арифметична прогресія - це послідовність дійсних чисел, кожен член якої, починаючи з другого,
утворюється додаванням до попереднього члена одного й того ж числа. Загальний вид арифметичної прогресії:

a1, a1 + d, a1 + 2d, …, a1 + (n - 1)d, …,
де a1 - це перший член прогресії, d = an+1 - an

Як результат, надрукувати всі елементи арифметичної прогресії починаючи з першого до останнього.

2. За допомогою циклу надрукувати геометричні фігури; розмір сторін/кількість рядків вводить користувач з консолі;
а)      b)      c)      d)      e)
***     *       ****    ****    1
**      **      ****    ****    01
*       ***             ****    101
                                0101

3. В циклі зчитати символ char. В залежності від природи символу виконати наступні дії: 
буква в нижньому регістрі - привести до верхнього та вивести;
цифра - додати до загальної суми введених цифр, та вивести результат поточної суми;
Інше (розділові знаки, спецсимвол, тд) - вивести повідомлення, що цей символ не обробляється програмою та продовжити цикл;
Завершити програму, якщо введено символ ‘.’;

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)
4. Зчитати з консолі число(n) - номер елемента послідовності Фібоначчі. Надрукувати значення зчитаного елемента послідовності
Фібоначчі(Fn) (послідовність Фібоначчі - числова послідовність, задана таким співвідношенням:
F1 = 1, F2 = 1, Fn+2 = Fn + Fn+1, n = 1, 2, 3, …,
F1 = 1, F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8, F7 = 13, F8 = 21
5. Зчитати ціле додатне число. Вивести факторіал цього числа. (Факторіал натурального числа n - добуток чисел від 1 до
цього числа, позначається як n! Н-д: 5! = 1⋅2⋅3⋅4⋅5 = 120).
*/

#include <iostream>
#include <cctype>

int main()
{
 
    std::cout << "LESSON 6\n";
    //STEP 1
    std::cout << "STEP 1\n";

    double a1, d;
    int n;
    std::cout << "Enter the required data: \n";
    std::cout << "First element (a1): ";
    std::cin >> a1;
    std::cout << "Arithmetic progression step (d): ";
    std::cin >> d;
    std::cout << "Last number arithmetic progression (n): ";
    std::cin >> n;
    
    while (n <= 0) {
        std::cout << "Error: the number of elements must be greater than zero!\n";
        std::cout << "Last number arithmetic progression (n): ";
        std::cin >> n;
    }
    
    double element;
    std::cout << "Elements of arithmetic progression:\n";
    for (int i = 0; i < n; ++i) {
        element = a1 + i * d;
        std::cout << element << " ";
    }

    std::cout << std::endl;

    //STEP 2
    std::cout << "STEP 1\n";

    int WIDTH, HEIGHT;
    int j, k;

    std::cout << "Enter the HEIGHT for the invert triangle: ";
    std::cin >> HEIGHT;

    while (HEIGHT <= 0) {
        std::cout << "Error: the number of lines must be greater than zero!\n";
        std::cout << "Enter the HEIGHT for the invert triangle: ";
        std::cin >> HEIGHT;
    }

    for (j = HEIGHT; j > 0; --j){
        for (k = 0; k < j; ++k){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    HEIGHT = 0;
    std::cout << "Enter the HEIGHT for the triangle: ";
    std::cin >> HEIGHT;

    while (HEIGHT <= 0) {
        std::cout << "Error: the number of lines must be greater than zero!\n";
        std::cout << "Enter the HEIGHT for the triangle: ";
        std::cin >> HEIGHT;
    }

    for (j = 1; j <= HEIGHT; ++j){
        for (k = 0; k < j; ++k){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    HEIGHT = 0;
    std::cout << "Enter the HEIGHT for the square: ";
    std::cin >> HEIGHT;

    while (HEIGHT <= 0) {
        std::cout << "Error: the number of lines must be greater than zero!\n";
        std::cout << "Enter the HEIGHT for the square: ";
        std::cin >> HEIGHT;
    }
    
    for (j = 0; j < HEIGHT; ++j) {
        for (k = 0; k < HEIGHT * 2; ++k) //тут я зробив множення на 2, щоб візуально в консолі це був приблизно квадрат
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    WIDTH = 0;
    HEIGHT = 0;
    std::cout << "Enter the size of the sides of the rectangle: \n";
    std::cout << "WIDTH: ";
    std::cin >> WIDTH;
    std::cout << "HEIGHT: ";
    std::cin >> HEIGHT;

    while (WIDTH <= 0 || HEIGHT <= 0) {
        std::cout << "Error: the number of lines must be greater than zero!\n";
        std::cout << "Enter the size of the sides of the rectangle: \n";
        std::cout << "WIDTH: ";
        std::cin >> WIDTH;
        std::cout << "HEIGHT: ";
        std::cin >> HEIGHT;
    }

    for (j = 0; j < HEIGHT; ++j) {
        for (k = 0; k < WIDTH; ++k){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    HEIGHT = 0;
    std::cout << "Enter the HEIGHT of the checkerboard pattern: ";
    std::cin >> HEIGHT;

    while (HEIGHT <= 0) {
        std::cout << "Error: the number of lines must be greater than zero!\n";
        std::cout << "Enter the HEIGHT of the checkerboard pattern: ";
        std::cin >> HEIGHT;
    }

    for (j = 0; j < HEIGHT; ++j) {
        for (k = 0; k <= j; ++k) {
            std::cout << ((j + k) % 2 == 0 ? "1" : "0");
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    //STEP 3
    std::cout << "STEP 3\n";
    char inputChar;
    int digitSum = 0;

    std::cout << "Enter characters (end program -> '.'): \n";

    while (true) {
        std::cin >> inputChar;
        
        if (inputChar == '.') {
            std::cout << "The program is completed" << std::endl;
            break;
        }

        if (std::islower(inputChar)) {
            char upperChar = std::toupper(inputChar);
            std::cout << "The letter is in upper case: " << upperChar << std::endl;
        } else if (std::isdigit(inputChar)) {
            digitSum += inputChar - '0';
            std::cout << "Current sum of digits: " << digitSum << std::endl;
        } else {
            std::cout << "Symbol '" << inputChar << "' is not processed by the program." << std::endl;
        }
    }

    std::cout << std::endl;

    std::cout << "ADDITIONAL TASKS\n";
    //STEP 4
    std::cout << "STEP 4\n";
    int fElement;

    std::cout << "Enter the number of the Fibonacci sequence element (n): ";
    std::cin >> fElement;

    while (fElement <= 0) {
        std::cout << "The item number must be a positive integer.\n";
        std::cout << "Enter the number of the Fibonacci sequence element (n): ";
        std::cin >> fElement;
    }

    if (fElement == 1 || fElement == 2) {
        std::cout << "F" << fElement << " = 1\n";
    } else {
        int prev = 1, curr = 1, next;
        for (int fib = 3; fib <= fElement; ++fib) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }
        std::cout << "F" << fElement << " = " << curr << std::endl;
    }
    
    std::cout << std::endl;
    
    //STEP 5
    std::cout << "STEP 5\n";
    int factElement = 0;
    int factorial = 1;

    std::cout << "Enter a positive integer: ";
    std::cin >> factElement;

    while (factElement < 0) {
        std::cout << "The number must be positive\n";
        std::cout << "Enter a positive integer: ";
        std::cin >> factElement;
    }

    for (int fact_index = 1; fact_index <= factElement; ++fact_index) {
        factorial *= fact_index;
    }

    std::cout << factElement << "! = " << factorial << std::endl;
    
    std::cout << std::endl;
    
    return 0;
}
