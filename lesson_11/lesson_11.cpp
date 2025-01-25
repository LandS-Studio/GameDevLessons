/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (5 бали)
1) Реалізувати функцію лінійного пошуку в двовимірному масиві;
bool find(int arr_2d[ROWS][COLUMNS], int toFind)

2) Функція bool isSorted(const int* arr, int size) яка перевіряє, чи заданий масив посортований за зростанням;

3) Написати функції двовимірного масива зазначеним способом:
    COL1 COL2 COL3 COL4
ROW1 2    5    10   8
ROW2 9    3    6    16
ROW3 12   7    15   11
ROW4 13   1    4    14

    COL1 COL2 COL3 COL4
ROW1 V    V    V    V
ROW2 V    V    V    V
ROW3 V    V    V    V
ROW4 V    V    V    V

{8, 16, 11, 14, 10, 6, 15, 4, 5, 3, 7, 1, 2, 9, 12, 13}

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

4) Написати функції двовимірного масива зазначеним способом:
    COL1 COL2 COL3 COL4
ROW1 <    <    <    <
ROW2 >    >    >    >
ROW3 <    <    <    <
ROW4 >    >    >    >

{13, 1, 4, 14, 11, 15, 7, 12, 9, 3, 6, 16, 8, 10, 5, 2}

5) Розширити функцію bool isSorted(const int* arr, int size, SortingDirection direction) яка перевіряє,
чи заданий масив посортований за спаданням, зростанням, де Sorting Direction: enum class SortingDirection { ascending, descending };
*/

#include <iostream>

// FOR STEP 5
enum class SortingDirection {
    ascending,
    descending
};

const int ROWS = 4;      
const int COLS = 4;   

// FOR STEP 1
// Function to search for an item in a two-dimensional array
bool find(int arr_2d[ROWS][COLS], const int toFind){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr_2d[i][j] == toFind) {
                return true;
            }
        }
    }
    return false;
}

// FOR STEP 2
// Function to check if an array is sorted in ascending order
bool isSorted(const int* arr, const int size, SortingDirection direction) {
    if (size <= 1) { 
        return true; // A single element or empty array is always considered sorted
    }

    for (int i = 0; i < size - 1; ++i) {
        if (direction == SortingDirection::ascending) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        } else if (direction == SortingDirection::descending) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
    }

    return true; 
}

// FOR STEP 3
// Function for displaying the elements of a two-dimensional array in order: columns from top to bottom
void printColumnForward(int arr[ROWS][COLS], const int rows, const int cols) {
    std::cout << "Items are in column order from top to bottom (from first to last): " << std::endl;
    std::cout << "{ ";
    for (int col = 0; col < cols; ++col) {  
        for (int row = 0; row < rows; ++row) {
            std::cout << arr[row][col] << " ";
        }
    }
    std::cout << "}" << std::endl;
}

// A function for displaying the elements of a two-dimensional array in order: columns from top to bottom, starting with the last
void printColumnReverse(int arr[ROWS][COLS], const int rows, const int cols) {
    std::cout << "Items are in column order from top to bottom (from last to first): " << std::endl;
    std::cout << "{ ";
    for (int col = cols - 1; col >= 0; --col) { 
        for (int row = 0; row < rows; ++row) {
            std::cout << arr[row][col] << " ";
        }
    }
    std::cout << "}" << std::endl;
}

// FOR STEP 4
// Print elements in a zigzag pattern, starting from the first row
void printByRowsZigzagFromTop(int arr[ROWS][COLS], const int rows, const int cols) {
    std::cout << "Print elements in a zigzag pattern, starting from the first row: " << std::endl;
    std::cout << "{ ";
    for (int row = 0; row < rows; ++row) {
        if (row % 2 == 0) { // Even numbered row: left to right
            for (int col = 0; col < cols; ++col) {
                std::cout << arr[row][col] << " ";
            }
        } else { // Not even row: right to left
            for (int col = cols - 1; col >= 0; --col) {
                std::cout << arr[row][col] << " ";
            }
        }
    }
    std::cout << "}" << std::endl;
}

// Print elements in a zigzag pattern, starting from the last row
void printByRowsZigzagFromBottom(int arr[ROWS][COLS], const int rows, const int cols) {
    std::cout << "Print elements in a zigzag pattern, starting from the last row: " << std::endl;
    std::cout << "{ ";
    for (int row = rows - 1; row >= 0; --row) {
        if ((rows - 1 - row) % 2 == 0) { // Even numbered row: left to right
            for (int col = 0; col < cols; ++col) {
                std::cout << arr[row][col] << " ";
            }
        } else { // Not even row: right to left
            for (int col = cols - 1; col >= 0; --col) {
                std::cout << arr[row][col] << " ";
            }
        }
    }
    std::cout << "}" << std::endl;
}

int main()
{
    int arr[ROWS][COLS] = {
        {2, 5, 10, 8},
        {9, 3, 6, 16},
        {12, 7, 15, 11},
        {13, 1, 4, 14}
    };

    //STEP 1
    int toFind;
    std::cout << "=STEP 1=" << std::endl;
    std::cout << "Enter the number to find: ";
    std::cin >> toFind;

    if (find(arr, toFind)) {
        std::cout << "Number " << toFind << " was found in the array." << std::endl;
    } else {
        std::cout << "Number " << toFind << " was not found in the array." << std::endl;
    }

    std::cout << std::endl;

    //STEP 2 & STEP 5
    int arr1[] = {2, 5, 10, 8};
    int arr2[] = {3, 4, 5, 6};
    int arr3[] = {77, 76, 75, 74};
    
    std::cout << "=STEP 2 & STEP 5=" << std::endl;
    std::cout << "Array 1 is sorted (ascending): " << std::boolalpha << isSorted(arr1, std::size(arr1), SortingDirection::ascending) << std::endl;
    std::cout << "Array 1 is sorted (descending): " << std::boolalpha << isSorted(arr1, std::size(arr1), SortingDirection::descending) << std::endl;
    std::cout << std::endl;
    std::cout << "Array 2 is sorted (ascending): " << std::boolalpha << isSorted(arr2, std::size(arr2), SortingDirection::ascending) << std::endl;
    std::cout << "Array 2 is sorted (descending): " << std::boolalpha << isSorted(arr2, std::size(arr2), SortingDirection::descending) << std::endl;
    std::cout << std::endl;
    std::cout << "Array 3 is sorted (ascending): " << std::boolalpha << isSorted(arr3, std::size(arr3), SortingDirection::ascending) << std::endl;
    std::cout << "Array 3 is sorted (descending): " << std::boolalpha << isSorted(arr3, std::size(arr3), SortingDirection::descending) << std::endl;
    std::cout << std::endl;
    
    //STEP 3
    std::cout << "=STEP 3=" << std::endl;
    printColumnForward(arr, ROWS, COLS);
    printColumnReverse(arr, ROWS, COLS);

    std::cout << std::endl;
    
    //STEP 4
    std::cout << "=STEP 4=" << std::endl;
    printByRowsZigzagFromTop(arr, ROWS, COLS);
    printByRowsZigzagFromBottom(arr, ROWS, COLS);

    std::cout << std::endl;
    
    return 0;
}
