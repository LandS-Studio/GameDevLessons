/*
Створити std::vector<std::string> stringContainer з набором випадкових рядків;
відсортувати рядки за кількістю букв в рядках з використанням функції
std::sort(stringContainer.begin()
stringContainer.end(), …)
з різним способом передачі порівняльного об’єкта:
проста функція bool compareByLength(...);
функціональний об’єкт class LengthComparator { …. };
лямбда;
Реалізувати функцію unsigned int countDivisibleBy(const std::vector<int>& vec, int number);
яка підраховує, скільки елементів вектора ділиться на number націло з використанням алгоритму
std::count_if() та лямбда функції. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareByLength(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

class LengthComparator {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        return a.size() < b.size();
    }
};

int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int val)
        { return val % number == 0; });
}

int main() {
    std::vector<std::string> stringContainer = {
        "Hello", "world", "from", "C++", "programming", "language"
    };

    // Sort by simple function
    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    std::cout << "Sorted by length:";
    for (const auto& str : stringContainer) {
        std::cout << " " << str;
    }
    std::cout << std::endl;

    // Sort by functor
    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
    std::cout << "Sorted by functor:";
    for (const auto& str : stringContainer) {
        std::cout << " " << str;
    }
    std::cout << std::endl;

    // Sort by lambda
    std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& a, const std::string& b)
        { return a.length() < b.length(); });
    std::cout << "Sorted by lambda:";
    for (const auto& str : stringContainer) {
        std::cout << " " << str;
    }
    std::cout << std::endl;

    std::vector<int> intContainer = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int divisor = 2;

    unsigned int count = countDivisibleBy(intContainer, divisor);
    std::cout << "Count of numbers divisible by " << divisor << " is " << count << std::endl;
    
    return 0;
}
