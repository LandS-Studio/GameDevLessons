/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (4 бали)
1) Користувач зчитує з клавіатури масив, розмір 10. Написати функцію, яка додатні елементи масиву множить на 2,
від’ємні робить 0. void translateArray(int numbers[], int size); Вивести масив у консоль.

2) Зчитати рядок з консолі. Функція, яка перетворює усі символи латиниці у верхній регістр (без використання std функцій);
void toUppercase(char str[]);

Input: aBBcce%.-ab
Output: ABBCCE%.-AB

3) Функція, яка перевіряє чи введений рядок паліндром (Паліндром - слово, число, набір символів, що однаково читається
в обох напрямках: зліва направо та справа наліво)

bool isPalindrom(const char str[]);
aba -> true ; tenet -> true ; cbbc -> true ; teneT -> false ; abcd -> false ; abca -> false

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

4) Функція, яка підраховує кількість голосних та приголосних у рядку:

5) void parseStringLetters(const char[] str, int& vowelsCount, int& constonantsCount); 
Функція для порівняння двох рядків без використання вбудованих бібліотек:
bool isEqual(const char str1[], const char str2[]);
*/

#include <iostream>
#include <cctype>

const int difUpperLower = 32; // 'a' - 'A' = 32
const char vowels[] = "aeiouAEIOU"; // Vowels array

// FOR STEP 1
// Function for converting an array
void translateArray(int numbers[], const int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > 0) {
            numbers[i] *= 2; 
        } else if (numbers[i] < 0) {
            numbers[i] = 0; 
        }
    }
}

// Function for printing an array
void printArray(int numbers[], const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

// FOR STEP 2
// Function to convert chars to uppercase
void toUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') { // 'a' = 97 && 'z' = 122
            str[i] = static_cast<char>(str[i] - difUpperLower); 
        }
    }
}

// FOR STEP 3
// Function to check if a string is a palindrome
bool isPalindrom(const char str[]) {
    int start = 0;
    int end = 0;

    // length string
    while (str[end] != '\0') {
        ++end;
    }
    --end; // `end` point to last char

    // Check characters 
    while (start < end) {
        if (str[start] != str[end]) {
            return false; 
        }
        ++start;
        --end;
    }

    return true; 
}

// FOR STEP 4
// Function for counting vowels and consonants
void countVowelsAndConsonants(const char str[], int &vowel_count, int &consonant_count) {
    vowel_count = 0;
    consonant_count = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        const char element = tolower(str[i]); // Convert a character to lower for check

        // Check if char is letter
        if (isalpha(element)) {
            // Check if char is vowel
            bool is_vowel = false;
            for (int j = 0; vowels[j] != '\0'; ++j) {
                if (element == vowels[j]) {
                    is_vowel = true;
                    break;
                }
            }
            if (is_vowel) {
                ++vowel_count; 
            } else {
                ++consonant_count;
            }
        }
    }
}

// FOR STEP 5
// Function for check two strings
bool isEqual(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }
    
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    
    const int max_size = 100;
    
    //STEP 1
    std::cout << "=STEP 1=" << std::endl;
    const int size = 10;
    int numbers_array[size];

    std::cout << "Enter 10 elements of the array:" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cin >> numbers_array[i];
    }

    std::cout << "Array before converted: ";
    printArray(numbers_array, size);

    translateArray(numbers_array, size);
    
    std::cout << "Array after converted: ";
    
    printArray(numbers_array, size);
    
    std::cout << std::endl;

    //STEP 2
    std::cout << "=STEP 2=" << std::endl;
    char latin_array[max_size];

    std::cout << "Input: ";
    std::cin >> latin_array; 

    toUppercase(latin_array);
    
    std::cout << "Output: " << latin_array << std::endl;
    std::cout << std::endl;

    //STEP 3
    std::cout << "=STEP 3=" << std::endl;
    char palindrom_string[max_size];

    std::cout << "Enter string: ";
    std::cin >> palindrom_string;

    std::cout << std::boolalpha;
    std::cout << palindrom_string << " -> " <<  isPalindrom(palindrom_string) << std::endl;

    std::cout << std::endl;

    //STEP 4
    std::cout << "=STEP 4=" << std::endl;
    char letter_array[max_size];

    std::cout << "Input string: ";
    std::cin >> letter_array;

    int vowels = 0, consonants = 0;
    countVowelsAndConsonants(letter_array, vowels, consonants);

    std::cout << "Vowels count: " << vowels << std::endl;
    std::cout << "Consonants count: " << consonants << std::endl;

    std::cout << std::endl;

    // STEP 5
    std::cout << "=STEP 5=" << std::endl;
    char first_string[max_size], second_string[max_size];
    std::cout << "Enter first string: ";
    std::cin >> first_string;
    std::cout << "Enter second string: ";
    std::cin >> second_string;

    if (isEqual(first_string, second_string)) {
        std::cout << "Strings are the same." << std::endl;
    } else {
        std::cout << "Strings are different." << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}

