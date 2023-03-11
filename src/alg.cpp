// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0){
      return 1;
    }
    if ((n & 1) == 0){
      double result = pown(value, n >> 1);
      return result * result;
    }
    else return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x,n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 1;
    for (uint16_t i = 1; i <= count; i++)
        result += calcItem(x, i);
    return result;
}

double sinn(double x, uint16_t count) {
  double result = x;
  for (uint16_t i = 2; i <= count; i++) {
      if ((i & 1) == 0)
          result -= calcItem(x, 2 * i - 1);
      else  result += calcItem(x, 2 * i - 1);
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 1;
  for (uint16_t i = 2; i <= count; i++) {
     if ((i & 1) == 0)
       result -= calcItem(x, 2 * i - 2);
     else  result += calcItem(x, 2 * i - 2);
  }
  return result;
}
