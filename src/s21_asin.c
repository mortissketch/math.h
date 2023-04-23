#include "./s21_math.h"

long double s21_asin(double x) {
  long double result = S21_NAN;
  if (x == S21_NAN || x == S21_INF || x == S21_mINF) {
    result = S21_NAN;
    result = -result;
  } else if (x == 1) {
    result = S21_PI / 2.0;
  } else if (x == -1) {
    result = -1.0 * S21_PI / 2.0;
  } else if (x > 1 || x < -1) {
    result = S21_NAN;
    result = -result;
  } else if (x > -1 && x < 1) {
    result = s21_atan(x / (s21_sqrt(1 - x * x)));
  }
  return result;
}