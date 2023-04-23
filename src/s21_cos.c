#include "./s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (x == S21_NAN) {
    result = S21_NAN;
  } else if (x == 0.) {
    result = 1.;
  } else if (x == S21_INF || x == S21_mINF) {
    result = -S21_NAN;
  } else {
    for (; x < -2 * S21_PI || x > 2 * S21_PI;) {
      if (x > 2 * S21_PI) {
        x -= 2 * S21_PI;
      } else {
        x += 2 * S21_PI;
      }
    }
    result = s21_sin(x + S21_PI / 2.);
  }
  return result;
}