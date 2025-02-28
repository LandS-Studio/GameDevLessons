#include "DynamicArray.h"
#include <iostream>


int main() {
    //Create a dynamic array
    DynamicArray<int> array;

    //Test push_back
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    std::cout << "Size after push_back: " << array.getSize() << std::endl;

    //Test operator[]
    std::cout << "Elements: ";
    for (std::size_t i = 0; i < array.getSize(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //Test pop_back
    array.pop_back();
    std::cout << "Size after pop_back: " << array.getSize() << std::endl;

    //Test back
    std::cout << "Last element: " << array.back() << std::endl;

    //Test reserve and getCapacity
    array.reserve(10);
    std::cout << "Capacity after reserve: " << array.getCapacity() << std::endl;

    //Test setSize
    array.setSize(5);
    std::cout << "Size after setSize: " << array.getSize() << std::endl;

    //Test copy constructor
    DynamicArray<int> array2;
    array2 = array;
    std::cout << "Size of array2 after copy constructor: " << array2.getSize() << std::endl;

    //Test operator==
    std::cout << "Are arrays equal? " << (array == array2) << std::endl;

    //Test clear
    array.clear();
    std::cout << "Size after clear: " << array.getSize() << std::endl;
    
    return 0;
}
