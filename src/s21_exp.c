#include "./s21_math.h"

long double s21_exp(double x) {
  long double result = x;
  if (x == 0) {
    result = 1;
  } else if (x == S21_NAN) {
    result = -S21_NAN;
  } else if (x <= 0) {
    result = 1 / s21_exp(-x);
  } else if (s21_fabs(x) < S21_INF) {
    result = 1;
    long int count = 1;
    long double tmp = 1;
    while (tmp > S21_EPS && result != S21_INF) {
      tmp *= x / count;
      count++;
      result += tmp;
      if (result > DBL_MAX) {
        result = S21_INF;
      }
    }
  }
  return result;
}
