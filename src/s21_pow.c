#include "./s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0;
  double copy_base = base;
  if (copy_base == 0 && exp > 0) {
    result = 0;
  } else if (copy_base == 0 && exp < 0) {
    result = S21_INF;
  } else if ((copy_base == 0 || copy_base != copy_base ||
              copy_base == S21_INF || copy_base == S21_mINF) &&
             exp == 0) {
    result = 1;
  } else if (copy_base < 0) {
    copy_base = -copy_base;
    result = s21_exp(exp * s21_log(copy_base));
    if (s21_fmod(exp, 2) != 0 && (exp != S21_mINF && exp != S21_INF) &&
        (copy_base != 1 || s21_fmod(exp, 2) != 0)) {
      result = -result;
    }
  } else {
    if ((copy_base != copy_base || exp == S21_mINF || exp == S21_INF) &&
        (copy_base == 1)) {
      result = 1;
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }
  return result;
}