#include "./s21_math.h"

long double s21_tan(double x) {
  long double result = x;
  if (x == 0) {
    result = x;
  } else if (x == S21_NAN || x == S21_INF || x == S21_mINF) {
    result = -S21_NAN;
  } else if (s21_fabs(x) < S21_INF) {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
