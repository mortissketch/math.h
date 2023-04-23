#include "./s21_math.h"

long double s21_factorial(int x) {
  long double result = 0;
  if (x == 0) {
    result = 1;
  }
  if (x > 0) {
    result = x * s21_factorial(x - 1);
  }
  return result;
}
