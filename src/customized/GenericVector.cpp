//#include "GenericVector.h"
//
//template<typename T>
//GenericVector<T>::GenericVector() : array(nullptr), current_size(0), max_size(0) {}
//
//template<typename T>
//GenericVector<T>::GenericVector(size_t size) : array(new T[size]), current_size(size), max_size(size) {}
//
//template<typename T>
//GenericVector<T>::~GenericVector() {
//    delete[] array;
//}
//
//template<typename T>
//size_t GenericVector<T>::size() const {
//    return current_size;
//}
//
//template<typename T>
//size_t GenericVector<T>::capacity() const {
//    return max_size;
//}
//
//template<typename T>
//bool GenericVector<T>::empty() const {
//    return current_size == 0;
//}
//
//template<typename T>
//void GenericVector<T>::push_back(const T& value) {
//    if (current_size == max_size) {
//        resize(max_size == 0 ? 1 : max_size * 2);
//    }
//    array[current_size++] = value;
//}
//
//template<typename T>
//void GenericVector<T>::resize(size_t new_size) {
//    T* new_array = new T[new_size];
//    for (size_t i = 0; i < current_size && i < new_size; ++i) {
//        new_array[i] = array[i];
//    }
//    delete[] array;
//    array = new_array;
//    max_size = new_size;
//    current_size = std::min(current_size, new_size);
//}
//
//template<typename T>
//T& GenericVector<T>::operator[](size_t index) {
//    return array[index];
//}
//
//template<typename T>
//const T& GenericVector<T>::operator[](size_t index) const {
//    return array[index];
//}
//
//template<typename T>
//void GenericVector<T>::pop_back() {
//    if (current_size > 0) {
//        --current_size;
//    }
//}
//
//template<typename T>
//void GenericVector<T>::clear() {
//    current_size = 0;
//}
//
//template<typename T>
//void GenericVector<T>::swap(GenericVector<T>& other) {
//    std::swap(array, other.array);
//    std::swap(current_size, other.current_size);
//    std::swap(max_size, other.max_size);
//}
