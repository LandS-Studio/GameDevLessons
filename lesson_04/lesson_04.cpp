/*
Домашнє завдання
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (3 бали)

1. Зчитати три числа, надрукувати максимальне з цих трьох чисел.
2. Програма, що перевіряє, чи ділиться введене число націло на 5 та 11 одночасно;
3. Зчитати 3 числа - можливі значення кутів трикутника. Перевірити, чи дані кути формують трикутник;
4. Зчитати з консолі число від 1 до 12. Це номер місяця (1 — січень, 2 — лютий тощо). Вивести на екран пору року,
    якій відповідає цей місяць. Наприклад, користувач ввів 5. Потрібно вивести Spring.

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

1. Зчитати два числа, знайти мінімум з двох чисел, використовуючи тернарний оператор;
2. Створити enum class Month для всіх місяців; зчитати з консолі число, привести його до відповідного значення з енама місяців;
    використовуючи switch та значення з enum class Month, надрукувати назву місяця в консоль.
    У разі, якщо число введено неправильно(н.д. 13 - не може бути коректно приведено до enum class Month), повідомити користувача про помилку.
*/

#include <iostream>

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    //MAIN HOMEWORK
    std::cout << "MAIN\n";

    //STEP 1
    std::cout << "STEP 1\n";
    float a, b, c;
    
        
    std::cout << "Ender three numbers:\n";
    std::cin >> a >> b >> c;

    float maxNumber = a;
    maxNumber = maxNumber > b ? maxNumber : b;
    maxNumber = maxNumber > c ? maxNumber : c;
    
    std::cout << "Max number = " << maxNumber << "\n";
    std::cout << std::endl;

    //STEP 2
    std::cout << "STEP 2\n";
    int checkNumber;
    std::cout << "Ender number:\n";
    std::cin >> checkNumber;

    if (checkNumber % 5 == 0 && checkNumber % 11 == 0)
    {
        std::cout << "The number " << checkNumber << " IS divisible by 5 and 11\n";
    } else
    {
        std::cout << "The number " << checkNumber << " NOT divisible by 5 and 11\n";
    }
    std::cout << std::endl;

    //STEP 3
    std::cout << "STEP 3\n";
    int angle_a, angle_b, angle_c;
    
    std::cout << "Enter three possible angles of the triangle:\n";
    std::cin >> angle_a >> angle_b >> angle_c;

    if (angle_a > 0 && angle_b > 0 && angle_c > 0 && (angle_a + angle_b + angle_c == 180)) {
        std::cout << "These angles form a triangle\n";
    } else {
        std::cout << "These angles do NOT form a triangle\n";
    }
    std::cout << std::endl;

    //STEP 4
    std::cout << "STEP 4\n";
    int month;
    bool bCompleteCheckMonth = false;
    
    while (bCompleteCheckMonth == false)
    {
        std::cout << "Enter the month number (1-12):\n";
        std::cin >> month;

        if (month >= 1 && month <= 12)
        {
            bCompleteCheckMonth = true;
            if (month == 12 || month == 1 || month == 2) {
                std::cout << "Winter\n";
            } else if (month >= 3 && month <= 5) {
                std::cout << "Spring\n";
            } else if (month >= 6 && month <= 8) {
                std::cout << "Summer\n";
            } else if (month >= 9 && month <= 11) {
                std::cout << "Autumn\n";
            }
        } else {
            std::cout << "Incorrect month number! Enter a number from 1 to 12\n";
        }
    }
    std::cout << std::endl;
    
    //ADDITIONAL HOMEWORK
    std::cout << "ADDITIONAL\n";

    //ADDITIONAL 1
    std::cout << "ADDITIONAL 1\n";
    int num_a, num_b;

    std::cout << "Enter two numbers:\n";
    std::cin >> num_a >> num_b;

    int minimum = (num_a < num_b) ? num_a : num_b;

    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << std::endl;

    //ADDITIONAL 2
    std::cout << "ADDITIONAL 2\n";
    bCompleteCheckMonth = false;
    int inputMonth;

    while (bCompleteCheckMonth == false)
    {
        std::cout << "Enter the month number (1-12):\n";
        std::cin >> inputMonth;

        if (inputMonth >= 1 && inputMonth <= 12) {
            bCompleteCheckMonth = true;
            Month enum_month = static_cast<Month>(inputMonth);

            switch (enum_month) {
            case Month::January:
                std::cout << "January\n";
                break;
            case Month::February:
                std::cout << "February\n";
                break;
            case Month::March:
                std::cout << "March\n";
                break;
            case Month::April:
                std::cout << "April\n";
                break;
            case Month::May:
                std::cout << "May\n";
                break;
            case Month::June:
                std::cout << "June\n";
                break;
            case Month::July:
                std::cout << "July\n";
                break;
            case Month::August:
                std::cout << "August\n";
                break;
            case Month::September:
                std::cout << "September\n";
                break;
            case Month::October:
                std::cout << "October\n";
                break;
            case Month::November:
                std::cout << "November\n";
                break;
            case Month::December:
                std::cout << "December\n";
                break;
            }
        } else {
            std::cout << "Error: Invalid month number entered!\n";
        }
    }
    
    return 0;
}
