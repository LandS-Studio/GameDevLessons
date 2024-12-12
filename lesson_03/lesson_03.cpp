/*
1. Зчитати з клавіатури число: скільки секунд гравець провів в грі. Підрахувати і надрукувати скільки це годин, хвилин, секунд.
Н-д: на вхід отримали 3870 секунд, програма має вивести: 1 hour, 4 minutes, 30 seconds.
2. Зчитати з консолі три числа. Надрукувати їх суму, добуток, середнє арифметичне;
3. Зчитати з клавіатури два числа. Створити змінні типу бул lessThan, equal, moreThan, lessOrEqual;
присвоїти їм значення порівняння першого та другого числа у форматі бул;
Вивести бул змінні в консоль; Вивести бул змінні в рядковому форматі “true/false” замість числового “1/0”
4. Зчитати два числа: width, height прямокутника. Порахувати та вивести площу, периметр.
5. Зчитати радіус кола. Порахувати площу та довжину кола.
*/


#include <iostream>

constexpr double pi = 3.14159265358979323846;

int main()
{
    std::cout << "STEP 1" << std::endl;

    int totalSeconds;
    std::cout << "Enter total seconds: ";
    std::cin >> totalSeconds;

    const unsigned int secondsInMinute = 60;
    const unsigned int minutesInHour = 60;
    const unsigned int secondsInHour = secondsInMinute * minutesInHour;

    int hours = totalSeconds / secondsInHour;
    int minutes = (totalSeconds % secondsInHour) / minutesInHour;
    int seconds = (totalSeconds % secondsInHour) % secondsInMinute;

    std::cout << hours << " hour, " << minutes << " minutes, " << seconds << " seconds" << '\n';
    std::cout << '\n';

    std::cout << "STEP 2" << '\n';

    double num1, num2, num3;
    std::cout << "Enter 3 numbers:\n";
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;

    std::cout << "Sum: " << num1 + num2 + num3 << '\n';
    std::cout << "Multiply: " << num1 * num2 * num3 << '\n';
    std::cout << "Average: " << (num1 + num2 + num3) / 3 << '\n';
    std::cout << '\n';

    std::cout << "STEP 3" << '\n';
    num1 = 0;
    num2 = 0;
    std::cout << "Enter 2 numbers:\n";
    std::cin >> num1;
    std::cin >> num2;

    bool lessThan = num1 < num2;
    bool equal = num1 == num2;
    bool moreThan = num1 > num2;
    bool lessOrEqual = num1 <= num2;

    std::cout << "Bool (numeric):\n";
    std::cout << "lessThan: " << lessThan << "\n";
    std::cout << "equal: " << equal << "\n";
    std::cout << "moreThan: " << moreThan << "\n";
    std::cout << "lessOrEqual: " << lessOrEqual << "\n";
    std::cout << '\n';

    std::cout << "Bool (text):\n";
    std::cout << std::boolalpha;
    std::cout << "lessThan: " << lessThan << "\n";
    std::cout << "equal: " << equal << "\n";
    std::cout << "moreThan: " << moreThan << "\n";
    std::cout << "lessOrEqual: " << lessOrEqual << "\n";
    std::cout << '\n';

    std::cout << "STEP 4" << '\n';
    double width, height;

    std::cout << "Enter width and height:\n";
    std::cin >> width;
    std::cin >> height;

    std::cout << "Areas: " << width * height << "\n";
    std::cout << "Perimeter: " << 2 * (width + height) << "\n";
    std::cout << '\n';

    std::cout << "STEP 5" << '\n';
    double radius;
        
    std::cout << "Enter circle radius: ";
    std::cin >> radius;

    std::cout << "Circle area: " << pi * radius * radius << '\n';
    std::cout << "Circle lenght: " << 2 * pi * radius << '\n';
}
