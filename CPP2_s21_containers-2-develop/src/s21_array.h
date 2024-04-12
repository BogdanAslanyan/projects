#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();

  array &operator=(array &&a);
  array &operator=(const array &a);

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  reference back();
  const_reference front() const;
  const_reference back() const;
  iterator data();

  iterator begin();
  iterator end();

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void swap(array &other);
  void fill(const_reference value);

 private:
  value_type arr[N];
  size_type size_;
};

template <typename T, size_t N>
array<T, N>::array() : size_(N) {
  for (size_type i = 0; i < N; ++i) {
    arr[i] = value_type();
  }
}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : size_(N) {
  if (items.size() > N) {
    throw std::out_of_range("Initializer list size is greater than array size");
  }

  size_type i = 0;
  for (; i < items.size() && i < N; ++i) {
    arr[i] = *(items.begin() + i);
  }
  for (; i < N; ++i) {
    arr[i] = value_type();
  }
}

template <typename T, size_t N>
array<T, N>::array(const array<T, N> &a) : size_(N) {
  for (size_type i = 0; i < N; ++i) {
    arr[i] = a.arr[i];
  }
}

template <typename T, size_t N>
array<T, N>::array(array<T, N> &&a) : size_(N) {
  for (size_type i = 0; i < N; ++i) {
    arr[i] = std::move(a.arr[i]);
    a.arr[i] = T{};  // Обнуляем исходный объект
  }
}

template <typename T, size_t N>
array<T, N>::~array() {}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array<T, N> &a) {
  if (this != &a) {
    for (size_type i = 0; i < N; ++i) {
      arr[i] = a.arr[i];
    }
  }
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&a) {
  if (this != &a) {
    for (size_type i = 0; i < N; ++i) {
      arr[i] = std::move(a.arr[i]);
    }
    a.size_ = 0;
  }
  return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
  return arr[0];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::front() {
  return arr[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
  return arr[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::back() {
  return arr[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return arr;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return arr;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return arr + N;
}

template <typename T, size_t N>
bool array<T, N>::empty() const {
  return N == 0;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
  return N;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
  return N;
}

template <typename T, size_t N>
void array<T, N>::swap(array &other) {
  for (size_type i = 0; i < N; ++i) {
    std::swap(arr[i], other.arr[i]);
  }
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; ++i) {
    arr[i] = value;
  }
}
}  // namespace s21

#endif  // S21_ARRAY_H
