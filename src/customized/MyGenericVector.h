#ifndef MY_GENERIC_VECTOR_H
#define MY_GENERIC_VECTOR_H

#include <iostream>
#include <memory>
#include <stdexcept>

/**
 * @brief Шаблонный класс MyGenericVector для работы с динамическим массивом любого типа данных.
 * 
 * @tparam T Тип элементов в векторе.
 */
template<typename T>
class MyGenericVector {
public:
    /**
     * @brief Конструктор по умолчанию. Создает пустой вектор с начальной емкостью 10 элементов.
     */
    MyGenericVector();

    /**
     * @brief Деструктор. Освобождает память, выделенную для массива.
     */
    ~MyGenericVector();

    /**
     * @brief Добавляет новый элемент в конец вектора.
     * 
     * @param value Значение элемента, которое нужно добавить.
     * 
     * @details Если внутренний массив заполнен, происходит его увеличение.
     */
    void push_back(const T &value);

    /**
     * @brief Удаляет последний элемент из вектора.
     * 
     * @throw std::out_of_range Если вектор пуст.
     */
    void pop_back();

    /**
     * @brief Доступ к элементу по указанному индексу (неконстантная версия).
     * 
     * @param index Индекс элемента.
     * @return Ссылка на элемент с указанным индексом.
     * 
     * @throw std::out_of_range Если индекс выходит за пределы размера вектора.
     */
    T &operator[](size_t index);

    /**
     * @brief Доступ к элементу по указанному индексу (константная версия).
     * 
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент с указанным индексом.
     * 
     * @throw std::out_of_range Если индекс выходит за пределы размера вектора.
     */
    const T &operator[](size_t index) const;

    /**
     * @brief Получает текущий размер вектора.
     * 
     * @return Текущий размер вектора.
     */
    size_t getSize() const;

    /**
     * @brief Проверяет, пуст ли вектор.
     * 
     * @return true, если вектор пуст, в противном случае - false.
     */
    bool isEmpty() const;

private:
    /**
     * @brief Изменяет размер внутреннего массива для размещения большего количества элементов.
     * 
     * @details Увеличивает вместимость вдвое и копирует все существующие элементы в новый массив.
     */
    void resize();

    /**
     * @brief Текущее количество элементов в векторе.
     */
    size_t size;

    /**
     * @brief Общая вместимость вектора.
     */
    size_t capacity;

    /**
     * @brief Умный указатель для управления динамическим массивом.
     */
    std::unique_ptr<T[]> data;
};

template<typename T>
MyGenericVector<T>::MyGenericVector() : size(0), capacity(10), data(std::make_unique<T[]>(capacity)) {
}

template<typename T>
MyGenericVector<T>::~MyGenericVector() = default;

template<typename T>
void MyGenericVector<T>::push_back(const T &value) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
}

template<typename T>
void MyGenericVector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw std::out_of_range("Vector is empty");
    }
}

template<typename T>
T &MyGenericVector<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T &MyGenericVector<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t MyGenericVector<T>::getSize() const {
    return size;
}

template<typename T>
bool MyGenericVector<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void MyGenericVector<T>::resize() {
    capacity *= 2;
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
}

#endif //MY_GENERIC_VECTOR_H
