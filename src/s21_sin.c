#include "./s21_math.h"

long double s21_sin(double x) {
  long double result = 0, copy_x = x;
  copy_x = s21_fmod(x, 2 * S21_PI);
  for (int i = 0, sign = 1; i < 20; i++) {
    result += sign * s21_pow(copy_x, (2 * i + 1)) / s21_factorial(1 + 2 * i);
    sign *= -1;
  }
  return result;
}