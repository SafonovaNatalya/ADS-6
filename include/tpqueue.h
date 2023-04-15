// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  SYM <T> arr[size];
  int first, last, count;

 public:
  TQueue(): first(0), last(0), count(0) {}
  bool isEmpty() const {
  return count == 0;
  }
  bool isFull() const {
  return count == size;
  }
  ~TQueue() {
  delete[] arr;
  }
  void push(const T& value) {
  if (isFull())
  throw std::string("Full!!");
  else {
  count += 1;
  int helper = last;
  for (int i = first; i < last; i++) {
    if (arr[i].prior < value.prior) {
     helper = i;
     break;
    }
  }
  for (int i = last; i < helper; i++) {
    arr[i % size] = arr[(i - 1) % size];
  }
  arr[helper % size] = value;
  last += 1;
  }
  }
  }
  T& pop() {
  if (isEmpty())
  throw std::string("Empty!!");
  else {
  count -= 1;
  return arr[first++ % size];
  }
  }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
