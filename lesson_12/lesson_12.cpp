/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (4 бали)
1) Реалізувати void bubbleSort(int arr[], int size) для сортування вхідного масиву алгоритмом сортування бульбашкою;

2) Відсортувати двовимірний масив по рядкам: void sort(int arr[ROWS][COLUMNS], SortingDirection);
де SortingDirection - enum class SortingDirection{ByRows, byColumn};
Використовуючи будь-які алгоритми сортування
(можна використовувати реалізації з лекції та з бібліотеки <algorithm>)

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

3) Відсортувати двовимірний масив по стовпцям: void sort(int arr[ROWS][COLUMNS], SortingDirection);
де SortingDirection - enum class SortingDirection{ByRows, byColumn};
Використовуючи будь-які алгоритми сортування
(можна використовувати реалізації з лекції та з бібліотеки <algorithm>)
 */

#include <iostream>
#include <algorithm>

const int ROWS = 4;
const int COLS = 4;

enum class SortingDirection {
    ByRows,
    ByColumns
};

// FOR STEP 1
// Array sorting function using the bubble algorithm
void bubbleSort(int arr[], const int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// FOR STEP 2 && STEP 3
void sort(int arr[ROWS][COLS], SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; ++i) {
            std::sort(arr[i], arr[i] + COLS);
        }
    } else if (direction == SortingDirection::ByColumns) {
        for (int col = 0; col < COLS; ++col){
            for (int i = 0; i < ROWS - 1; ++i) {
                for (int j = 0; j < ROWS - 1; ++j) {
                    if (arr[j][col] > arr[j+1][col]){
                        std::swap(arr[j][col], arr[j+1][col]);
                    }
                }
            }
        }
    }
}

void printArray(int arr[ROWS][COLS]){
    for (int i = 0; i < ROWS; ++i){
        for (int j = 0; j < COLS; ++j){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int testArray[] = { 5, 4, 2, 1, 3, 6, 8, 7};
    
    std::cout << "Original Test Array:" << std::endl;
    for (int i = 0; i < std::size(testArray); ++i){
        std::cout << testArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    bubbleSort(testArray, std::size(testArray));

    std::cout << "Sorted Test Array:" << std::endl;
    for (int j = 0; j < std::size(testArray); ++j){
        std::cout << testArray[j] << " ";
    }
    std::cout << std::endl << std::endl;

    int array[ROWS][COLS] = {
        {1, 9, 13, 8},
        {10, 5, 2, 7},
        {11, 16, 3, 14},
        {4, 15, 6, 12}
    };

    std::cout << "Original Two-Array:" << std::endl;
    printArray(array);
    std::cout << std::endl;

    sort(array, SortingDirection::ByRows);
    std::cout << "Array sorted by rows:" << std::endl;
    printArray(array);
    std::cout << std::endl;

    sort(array, SortingDirection::ByColumns);
    std::cout << "Array sorted by columns:" << std::endl;
    printArray(array);
    std::cout << std::endl;

    return 0;
}