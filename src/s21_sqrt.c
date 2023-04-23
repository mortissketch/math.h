#include "./s21_math.h"

long double s21_sqrt(double x) {
  long double first_value = 0, second_value, middle_value;
  if (x == S21_INF || x == S21_mINF) {
    middle_value = S21_INF;
  } else if (x == S21_NAN || x < 0) {
    if (x < 0) {
      middle_value = -S21_NAN;
    } else {
      middle_value = S21_NAN;
    }
  } else {
    if (x == 0) {
      middle_value = 0.0;
    } else {
      if (x < 1)
        second_value = 1;
      else
        second_value = x;
      middle_value = (first_value + second_value) / 2;
      while ((middle_value - first_value) > S21_EPS) {
        if (middle_value * middle_value > x)
          second_value = middle_value;
        else
          first_value = middle_value;
        middle_value = (first_value + second_value) / 2;
      }
    }
  }
  return middle_value;
}