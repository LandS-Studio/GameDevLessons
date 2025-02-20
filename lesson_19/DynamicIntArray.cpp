#include "DynamicIntArray.h"
//#include <algorithm> for std::min and std::copy
#include <iostream>

// default c-tor
DynamicIntArray::DynamicIntArray() : m_data(nullptr), m_size(0) {}

// c-tor with size
DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size) {
    m_data = new int[size];
}

DynamicIntArray::~DynamicIntArray() {
    delete[] m_data;
}

// Access element by index
int& DynamicIntArray::operator[](std::size_t index) {
    return m_data[index];
}

// Clear internal memory, set size to 0
void DynamicIntArray::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

// Comparison operators ==
bool DynamicIntArray::operator==(const DynamicIntArray& other) {
    if (m_size != other.m_size) return false;
    
    for (std::size_t i = 0; i < m_size; ++i) {
        if (m_data[i] != other.m_data[i]) {
            return false;
        }
    }
    return true;
}

// Comparison operators !=
bool DynamicIntArray::operator!=(const DynamicIntArray& other) {
    return !(*this == other);
}

// Get size of the array
std::size_t DynamicIntArray::getSize() const {
    return m_size;
}

// copy c-tor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : m_size(other.m_size) {
    m_data = new int[m_size];
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    // Is this a normal alternative?
    // std::copy(other.m_data, other.m_data + m_size, m_data);
}

// assignment operator
DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this == &other) return *this;
    
    delete[] m_data;
    m_size = other.m_size;
    m_data = new int[m_size];
    for (std::size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    return *this;
}

// set new size for the array
void DynamicIntArray::setSize(std::size_t newSize) {
    int* newData = new int[newSize]; // new memory

    // copy old content to new inner array
    std::size_t minSize = newSize < m_size ? newSize : m_size;
    for (std::size_t i = 0; i < minSize; ++i) {
        newData[i] = m_data[i];
    }
    /* alternative with std::min and std::copy when m_size is size_t type
     * std::size_t minSize = std::min(newSize, m_size);
     * std::copy(m_data, m_data + minSize, newData);
     */
    delete[] m_data; // delete previous memory
    m_data = newData;
    m_size = newSize;
}

// Allocate new memory (old memory + 1 new element)
void DynamicIntArray::push_back(int element) {
    setSize(m_size + 1);
    m_data[m_size - 1] = element;
}

