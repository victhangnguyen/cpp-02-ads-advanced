#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {

public:
  Pair() : first(0), second(0) {}
  Pair(int firstValue, int secondValue);

  ~Pair() {}

private:
  int first;
  int second;
};

#endif