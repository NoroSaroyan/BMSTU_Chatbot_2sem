#ifndef GENERICVECTOR_H
#define GENERICVECTOR_H

#include <algorithm>

template<typename T>
class GenericVector {
public:
    GenericVector();

    explicit GenericVector(size_t size);

    ~GenericVector();

    size_t size() const;

    size_t capacity() const;

    bool empty() const;

    void push_back(const T &value);

    void resize(size_t new_size);

    T &operator[](size_t index);

    const T &operator[](size_t index) const;

    void pop_back();

    void clear();

    void swap(GenericVector<T> &other);

private:
    T *array;
    size_t current_size;
    size_t max_size;
};

#include "GenericVector.cpp"

#endif // GENERICVECTOR_H
