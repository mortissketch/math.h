#include "./s21_math.h"

long double s21_fmod(double x, double y) {
  long long int mod = 0;
  long double result = 0, copy_x = (long double)x, copy_y = (long double)y;
  mod = x / y;
  if (y == S21_INF || y == S21_mINF || x == S21_INF || x == S21_mINF) {
    if (x == S21_INF || x == S21_mINF) {
      result = -S21_NAN;
    } else if (y == S21_INF || y == S21_mINF) {
      result = x;
    }
  } else if (x == S21_NAN || y == S21_NAN) {
    result = S21_NAN;
  } else {
    result = copy_x - mod * copy_y;
  }
  return result;
}