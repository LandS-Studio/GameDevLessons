#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	//Testing of ALL methods
	//default c-tor
	DynamicIntArray arr1;
	std::cout << "Default 'arr1' size: " << arr1.getSize() << std::endl;
	std::cout << std::endl;
	
	//c-tor with size
	DynamicIntArray arr2(5);
	DynamicIntArray arr3(5);
	std::cout << "Size of 'arr2' with 5 elements: " << arr2.getSize() << std::endl;
	for (std::size_t i = 0; i < arr2.getSize(); ++i) {
        arr2[i] = i;
        std::cout << "Element " << i << " of 'arr2': " << arr2[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Size of 'arr3' with 5 elements: " << arr2.getSize() << std::endl;
    for (std::size_t i = 0; i < arr3.getSize(); ++i) {
        arr3[i] = i;
        std::cout << "Element " << i << " of 'arr3': " << arr3[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing operators ==
    // how bool is printed
    std::cout << "Are 'arr2' and 'arr3' equal? " << std::boolalpha << (arr2 == arr3) << std::endl;
    std::cout << std::endl;
    
    // Testing set size
    arr2.setSize(8);
    std::cout << "Size of 'arr2' after setSize: " << arr2.getSize() << std::endl;
    for (std::size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << "Element " << i << " of 'arr2': " << arr2[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing push_back
    arr2.push_back(8);
    std::cout << "Size of 'arr2' after push_back: " << arr2.getSize() << std::endl;
    for (std::size_t i = 0; i < arr2.getSize(); ++i) {
        std::cout << "Element " << i << " of 'arr2': " << arr2[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing operator !=
    std::cout << "Are 'arr2' and 'arr3' equal? " << std::boolalpha << (arr2 == arr3) << std::endl;
    std::cout << std::endl;
    
    // Testing copy c-tor
    DynamicIntArray arr4(arr2);
    std::cout << "Size of 'arr4' after copy c-tor: " << arr4.getSize() << std::endl;
    for (std::size_t i = 0; i < arr4.getSize(); ++i) {
        std::cout << "Element " << i << " of 'arr4': " << arr4[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing operator ==
    std::cout << "Are 'arr2' and 'arr4' equal? " << (arr2 == arr4) << std::endl;
    std::cout << std::endl;
    
    // Testing assignment operator
    arr1 = arr3;
    std::cout << "Size of 'arr1' after assignment operator: " << arr1.getSize() << std::endl;
    for (std::size_t i = 0; i < arr1.getSize(); ++i) {
        std::cout << "Element " << i << " of 'arr1': " << arr1[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Testing clear
    arr1.clear();
    std::cout << "Size of 'arr1' after clear: " << arr1.getSize() << std::endl;
    arr2.clear();
    std::cout << "Size of 'arr2' after clear: " << arr2.getSize() << std::endl;
    arr3.clear();
    std::cout << "Size of 'arr3' after clear: " << arr3.getSize() << std::endl;
    std::cout << std::endl;
    
    // Testing operator []
    std::cout << "Element 4 of 'arr4': " << arr4[4] << std::endl;
    arr4[4] = 5;
    std::cout << "Element 4 after change of 'arr4': " << arr4[4] << std::endl;
    std::cout << std::endl;
    
    return 0;
}