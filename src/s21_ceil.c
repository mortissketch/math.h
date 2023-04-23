#include "./s21_math.h"

long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (x == S21_INF || x == S21_mINF || x == S21_NAN || x == DBL_MAX) {
    result = x;
  } else {
    if (s21_fabs(x) > 0. && x != result) {
      if (x > 0.) result += 1.;
    }
  }
  return result;
}