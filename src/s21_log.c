#include "./s21_math.h"

long double s21_log(double x) {
  int exp_count = 0;
  long double result = 0.0;
  double duplicate = 0.0;
  if (x == -S21_INF || x < 0. || x == S21_NAN) {
    if (x < 0.) {
      result = -S21_NAN;
    } else {
      result = S21_NAN;
    }
  } else if (x == 0.0) {
    result = -S21_INF;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == 1.0) {
    result = 0;
  } else {
    for (; x >= S21_EXP; x /= S21_EXP, exp_count++) continue;
    for (int i = 0; i < 100; i++) {
      duplicate = result;
      result =
          duplicate + 2 * (x - s21_exp(duplicate)) / (x + s21_exp(duplicate));
    }
    result += exp_count;
  }
  return result;
}