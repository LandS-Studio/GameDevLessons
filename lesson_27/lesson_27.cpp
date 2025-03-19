#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <random>

//MAIN TASK
// ----------------------------------------------------//
//  Function for splitting a vector (preparation for QuickSort)
size_t split(std::vector<int>& array, size_t low, size_t high) {
    int pivot = array[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (array[j] < pivot) {
            std::swap(array[i], array[j]);
            ++i;
        }
    }
    std::swap(array[i], array[high]);
    return i;
}

//  QuickSort function without threads
void quickSortSingleThread(std::vector<int>& array, size_t low, size_t high) {
    if (low < high) {
        size_t pivot = split(array, low, high);
        quickSortSingleThread(array, low, pivot > 0 ? pivot - 1 : 0);
        quickSortSingleThread(array, pivot + 1, high);
    }
}

//  QuickSort function with threads
void quickSortMultiThread(std::vector<int>& array, size_t low, size_t high, size_t depth) {
    if (low < high) {
        size_t pivot = split(array, low, high);

        if (depth > 0) {
            std::thread leftThread(quickSortMultiThread, std::ref(array), low, pivot > 0 ? pivot - 1 : 0, depth - 1);
            quickSortMultiThread(array, pivot + 1, high, depth - 1);
            leftThread.join();
        } else {
            quickSortSingleThread(array, low, pivot > 0 ? pivot - 1 : 0);
            quickSortSingleThread(array, pivot + 1, high);
        }
    }
}

// Function for running QuickSort with a different number of threads
void quickSort(std::vector<int>& array, size_t threadCount) {
    size_t depth = threadCount > 1 ? std::log2(threadCount) : 0;
    quickSortMultiThread(array, 0, array.size() - 1, depth);
}
// ----------------------------------------------------//

// ADDITIONAL TASK
// ----------------------------------------------------//
// Function for measuring the execution time
template <typename F, typename... Args>
long long measureTime(F func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

// Generating a vector with random numbers
std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    std::generate(array.begin(),array.end(), [&](){ return dis(gen); });
    return array;
}

// ----------------------------------------------------//


int main() {

    //MAIN TASK
    ///*
    // ----------------------------------------------------//
    // Create test vector
    std::vector<int> array = { 10, 7, 8, 9, 1, 5, 3, 2, 6 , 4 };

    // Parameters fot multi-threading
    size_t singleThread = 1;
    size_t twoThreads = 2;
    size_t hardwareThreads = std::thread::hardware_concurrency();
    size_t doubleHardwareThreads = hardwareThreads * 2;

    std::vector<int> arrayCopy;

    // QuickSort with 1 thread
    arrayCopy = array;
    quickSort(arrayCopy, singleThread);
    std::cout << "Single thread: ";
    for (int i : arrayCopy) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // QuickSort with 2 threads
    arrayCopy = array;
    quickSort(arrayCopy, twoThreads);
    std::cout << "Two threads: ";
    for (int i : arrayCopy) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // QuickSort with hardware threads
    arrayCopy = array;
    quickSort(arrayCopy, hardwareThreads);
    std::cout << "Hardware threads: ";
    for (int i : arrayCopy) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // QuickSort with double hardware threads
    arrayCopy = array;
    quickSort(arrayCopy, doubleHardwareThreads);
    std::cout << "Double hardware threads: ";
    for (int i : arrayCopy) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    // ----------------------------------------------------//
    //*/
    
    // ADDITIONAL TASK
    // ----------------------------------------------------//
    // Size vectors for testing
    std::vector<size_t> sizes = { 10, 100, 1000, 10000, 100000, 1000000 };

    // Amount of threads for testing
    std::vector<size_t> threads = {
        1,
        2,
        std::thread::hardware_concurrency(),
        2 * std::thread::hardware_concurrency()
    };

    // Table results
    std::cout << "Size\tThreads\tTime" << std::endl;

    for (size_t size : sizes) {
        auto array = generateRandomVector(size);

        for (size_t thread : threads) {
            auto arrayCopy = array;
            long long time = measureTime(quickSort, arrayCopy, thread);
            std::cout << size << "\t" << thread << "\t" << time << std::endl;
        }
    }
    
    // ----------------------------------------------------//
    return 0;
}
