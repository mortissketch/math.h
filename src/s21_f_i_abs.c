#include "./s21_math.h"

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_fabs(double x) {
  long double result = x;
  if (x == S21_INF || x == S21_mINF) {
    result = S21_INF;
  } else {
    result *= (x < 0) ? -1 : 1;
  }
  return result;
}