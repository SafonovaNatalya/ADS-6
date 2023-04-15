// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
 private:
  T *arr;
  int first, last, count;

 public:
  TPQueue(): first(0), last(0), count(0) {
  arr = new T[size];
  }
  bool isEmpty() const {
  return count == 0;
  }
  bool isFull() const {
  return count == size;
  }
  ~TPQueue() {
  delete[] arr;
  }
  void push(const T& value) {
  if (isFull()) {
  throw std::string("Full!!");
  }
  count+=1;
  int helper = last;
  for (int i = first; i < last; i++) {
    if (arr[i].prior < value.prior) {
     helper = i;
     break;
    }
  }
  for (int i = last; i > helper; i--) {
    arr[i % size] = arr[(i - 1) % size];
  }
  arr[helper % size] = value;
  last += 1;
  }
  T& pop() {
  if (isEmpty()) {
  throw std::string("Empty!!");
  }
  count-=1;
  return arr[first++ % size];
  }
};

#endif  // INCLUDE_TPQUEUE_H_
