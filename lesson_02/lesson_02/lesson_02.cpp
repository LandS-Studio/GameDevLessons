/*
1. Зчитати з клавіатури 2 числа; Поміняти місцями значення змінних; надрукувати нові значення в консоль. Наприклад:
    Input: “Enter integer 1:” 12 
    “Enter integer 2:” 5
    Output: “Integer 1: 5”
    “Integer 2: 12”
2. Створити та ініціалізувати змінну типу double, вивести значення змінної в консолі;
    Вивести значення змінної приведене до типу int (без символів після коми);
    Вивести число в рядок шириною 20 символів, вирівняти по правому краю, пусте місце заповнити символом ‘$’ (дивись I/O manipulators)
3. Створити double змінну і вивести її в різних форматах: з різною точністю (2, 5, 10 знаків після коми), в різних нотаціях(standard, e-notation);
4. Створити енам WeekDay, де кожному дню тижня відповідає порядковий номер (1-7).
    Синтаксис за посиланням в додаткових матеріалах, як змінити формування номерів від 0..N-1.
    Вивести числове значення кожного дня тижня у консоль (за допомогою приведення типу з enum class в int)
5. Зчитати число з консолі. Привести число до типу bool, вивести значення bool у текстовому форматі(“true”, “false”) за допомогою відповідного I/O manipulator)
*/

#include <iomanip>
#include <iostream>

enum class WeekDay {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    //STEP 1
    int a, b;

    std::cout << "STEP 1" << std::endl;
    std::cout << "INPUT:" << std::endl;
    std::cout << "Enter integer 1: ";
    std::cin >> a;

    std::cout << "Enter integer 2: ";
    std::cin >> b;

    int temp = a;
    a = b;
    b = temp;

    std::cout << "OUTPUT:" << std::endl;
    std::cout << "Enter integer 1: " << a << std::endl;
    std::cout << "Enter integer 2: " << b << std::endl;
    std::cout << std::endl;

    //STEP 2
    std::cout << "STEP 2" << std::endl;
    
    double myFirstDouble = 1996.0128356741;
    std::cout << "Variable value (double): " << myFirstDouble << std::endl;

    int myDoubleToInteger = myFirstDouble; //static_cast<int>?
    std::cout << "Variable value (int): " << myDoubleToInteger << std::endl;

    std::cout << "Format double: " << std::setw(20) << std::setfill('$') << myFirstDouble << std::endl;
    std::cout << std::endl;

    //STEP 3
    std::cout << "STEP 3" << std::endl;
    
    double mySecondDouble = 2024.7574839564;
    
    std::cout << "Default format: " << mySecondDouble << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Fixed format (2): " << mySecondDouble << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Fixed format (5): " << mySecondDouble << std::endl;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Fixed format (10): " << mySecondDouble << std::endl;

    std::cout << std::scientific << std::setprecision(2);
    std::cout << "Exp format (2): " << mySecondDouble << std::endl;

    std::cout << std::scientific << std::setprecision(5);
    std::cout << "Exp format (5): " << mySecondDouble << std::endl;

    std::cout << std::scientific << std::setprecision(10);
    std::cout << "Exp format (10): " << mySecondDouble << std::endl;
    std::cout << std::endl;

    //STEP 4
    std::cout << "STEP 4" << std::endl;

    std::cout << static_cast<int>(WeekDay::Monday) << ".Monday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Tuesday) << ".Tuesday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Wednesday) << ".Wednesday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Thursday) << ".Thursday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Friday) << ".Friday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Saturday) << ".Saturday" << std::endl;
    std::cout << static_cast<int>(WeekDay::Sunday) << ".Sunday" << std::endl;
    std::cout << std::endl;
    
    //STEP 5
    std::cout << "STEP 5" << std::endl;

    int myNumToBool;

    std::cout << "Input number: ";
    std::cin >> myNumToBool;

    bool myBoolValue = static_cast<bool>(myNumToBool);

    std::cout << std::boolalpha;
    std::cout << "Bool value: " << myBoolValue << std::endl;
}
