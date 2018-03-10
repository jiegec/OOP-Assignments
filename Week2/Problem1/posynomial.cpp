#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double posynomial_qinjiushao(double *a, int len, double x) {
  double answer = 0.0;
  for (int i = len-1; i >= 0; i--) {
    answer /= x;
    answer += a[i];
  }
  return answer;
}

double posynomial_naive(double *a, int len, double x) {
  double answer = 0.0;
  for (int i = 0; i < len; i++) {
    double current_multiplier = 1.0;
    for (int j = 0; j < i; j++) {
      current_multiplier /= x;
    }
    answer += a[i] * current_multiplier;
  }
  return answer;
}
