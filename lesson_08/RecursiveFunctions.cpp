#include "RecursiveFunctions.h"
#include <iostream>

// For STEP 2
// Function for calculating the factorial using recursion
int factorialRecursive(int count) {
    if (count <= 1) {
        return 1;
    }
    return count * factorialRecursive(count - 1);
}

// For STEP 4
// Print numbers from largest to smallest using recursion
void printNaturalNumbersLargeToSmallRecursion(int count) {
    if (count < 1) {
        std::cout << std::endl; 
        return;
    }
    std::cout << count << " ";
    printNaturalNumbersLargeToSmallRecursion(count - 1);
}