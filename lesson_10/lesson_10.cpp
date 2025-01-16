/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (5 бали)
1) Реалізувати функції void swap(int& a, int& b); void swap(int* a, int* b);
які приймають як вхідні параметри дві int змінні та змінюють їх місцями двома способами:
з використанням вказівників та посилань.

2) Реалізувати функцію bool find(const int* arr, int size, int elem), яка повертає true, якщо число знайдено у масиві.
Зробити задачу з використанням арифметики над вказівниками (без використання оператора доступу до елементів масиву []).

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)
3) Створити функцію bool calculateSum(const double* arr, int arrSize, double& sum); яка записує у змінну sum суму
всіх елементів довільного масиву, повертає true, якщо розмір масиву > 0.
*/

#include <iostream>

// FOR STEP 1
// Swap using references
void swapByRef(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Swap using pointers
void swapByPoint(int* a, int* b){
    if(a != nullptr && b != nullptr){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// FOR STEP 2
// Function to find an element in an array using pointer arithmetic
bool findElementInArray(const int* array, const int size, int element){
    const int* end = array + size; //Pointer to the element after the last one
    while (array != end){
        if (*array == element){
            return true;
        }
        ++array;
    }
    return false;
}

// FOR STEP 3
// Function for calculating the sum of array elements
bool calculateSum(const int* array, const int size, int& sum) {
    if (size <= 0) {
        return false;
    }
    
    sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(array + i);
    }
    return true; 
}

int main() {
    const int array[] = {1, 3, 5, 6, 7, 9, 10};
    int x = 0, y = 0;
            
    //STEP 1
    std::cout << "=STEP 1=" << std::endl;
    std::cout << "ENTER \"x\" and \"y\" value:" << std::endl;
    std::cin >> x >> y;

    std::cout << "Before swap (ref): x = " << x << ", y = " << y << std::endl;
    swapByRef(x, y);
    std::cout << "After swap (ref): x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;

    std::cout << "Before swap (pointer): x = " << x << ", y = " << y << std::endl;
    swapByPoint(&x,&y);
    std::cout << "After swap (pointer): x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;

    //STEP 2
    const int size = std::size(array); //С++17
    int num = 0;
    
    std::cout << "=STEP 1=" << std::endl;
    std::cout << "Enter number you want to find: " << std::endl;
    std::cin >> num;

    if (findElementInArray(array, size, num)) {
        std::cout << "Element " << num << " found in the array." << std::endl;
    } else {
        std::cout << "Element " << num << " not found in the array." << std::endl;
    }
    std::cout << std::endl;

    //STEP 3
    int totalSum = 0;

    if (calculateSum(array, size, totalSum)) {
        std::cout << "The sum of the array elements is: " << totalSum << std::endl;
    } else {
        std::cout << "Invalid array size!" << std::endl;
    }
    
    return 0;
}
