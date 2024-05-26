#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
class GenericVector {
public:
    GenericVector();
    ~GenericVector();

    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;
    bool isEmpty() const;

private:
    void resize();

    size_t size;
    size_t capacity;
    std::unique_ptr<T[]> data;
};

template <typename T>
GenericVector<T>::GenericVector() : size(0), capacity(10), data(std::make_unique<T[]>(capacity)) {}

template <typename T>
GenericVector<T>::~GenericVector() = default;

template <typename T>
void GenericVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
void GenericVector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw std::out_of_range("Vector is empty");
    }
}

template <typename T>
T& GenericVector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& GenericVector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t GenericVector<T>::getSize() const {
    return size;
}

template <typename T>
bool GenericVector<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void GenericVector<T>::resize() {
    capacity *= 2;
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
}

#endif // GENERIC_VECTOR_H
