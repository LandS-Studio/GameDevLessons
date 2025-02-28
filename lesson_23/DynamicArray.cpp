#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_size(size), m_capacity(size) {
    m_data = new T[m_capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] m_data;
}

//Copy operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    return *this;
}

//Access elements
template <typename T>
T& DynamicArray<T>::operator[](std::size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](std::size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

//Memory methods
template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace) {
    if (reservedSpace > m_capacity) {
        reallocate(reservedSpace);
    }
}

template <typename T>
std::size_t DynamicArray<T>::getCapacity() const {
    return m_capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit() {
    if (m_capacity > m_size) {
        reallocate(m_size);
    }
}

template <typename T>
void DynamicArray<T>::reallocate(std::size_t newCapacity) {
    T* newData = new T[newCapacity];
    std::copy(m_data, m_data + m_size, newData);
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

//Add/remove elements
template <typename T>
void DynamicArray<T>::push_back(const T& element) {
    if (m_size == m_capacity) reallocate(std::max(static_cast<std::size_t>(1), m_capacity * 2));
    m_data[m_size++] = element;
}

template <typename T>
void DynamicArray<T>::pop_back() {
    if (m_size > 0) --m_size;
}

template <typename T>
T DynamicArray<T>::back() const {
    if (m_size == 0) {
        throw std::out_of_range("Empty array");
    }
    return m_data[m_size - 1];
}

//Operator ==
template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const {
    if (m_size != other.m_size) return false;
    for (std::size_t i = 0; i < m_size; ++i) {
        if (m_data[i] != other.m_data[i]) return false;
    }
    return true;
}

//Size management
template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize) {
    if (newSize > m_capacity) {
        reallocate(newSize);
    }
    m_size = newSize;
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const {
    return m_size;
}

template <typename T>
void DynamicArray<T>::clear() {
    m_size = 0;
}

//Explicit instantiations
template class DynamicArray<int>;
