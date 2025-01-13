#include "LoopFunctions.h"
#include <iostream>

// For STEP 1
// Function for counting numbers
void countNumbers(int count) {
    int positive = 0, negative = 0, zeroes = 0; // Counters
    int number;

    std::cout << "Enter " << count << " numbers: " << std::endl;
    for (int i = 0; i < count; i++) {
        std::cin >> number;
        if (number > 0) {
            positive++;
        } else if (number < 0) {
            negative++;
        } else {
            zeroes++;
        }
    }

    std::cout << "positive: " << positive << ", negative: " << negative << ", zeroes: " << zeroes << std::endl;
}

// For STEP 2
// The function of calculating the factorial using a for
int factorialIterative(int count) {
    int result = 1;
    for (int i = 1; i <= count; ++i) {
        result *= i;
    }
    return result;
}

// For STEP 4
// Print numbers from largest to smallest using a loop
void printNumbersLargeToSmallLoop(int count) {
    for (int i = count; i >= 1; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Print numbers from smallest to largest using a loop
void printNumbersSmallToLargeLoop(int count) {
    for (int i = 1; i <= count; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}