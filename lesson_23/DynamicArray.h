#pragma once
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

template <typename T>
class DynamicArray {
public:

    //Default constructor and destructor
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    //Methods to access elements
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;

    //Size management
    void setSize(std::size_t newSize);
    std::size_t getSize() const;
    void clear();

    //Add/remove elements
    void push_back(const T& element);
    void pop_back();
    T back() const;

    //Reserve memory
    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;
    void shrinkToFit();

    //Operators
    bool operator==(const DynamicArray& other) const;   
    DynamicArray& operator=(const DynamicArray& other); 

private:
    T* m_data;
    std::size_t m_size;
    std::size_t m_capacity;

    void reallocate(std::size_t newCapacity);
};