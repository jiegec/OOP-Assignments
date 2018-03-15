#include "func.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
using namespace std;

typedef double (*func)(double *, int, double);

double test_func(const char *name, func tested_func, double coef[], int len,
                 double x) {
  printf("%s: Begin testing.\n", name);
  printf("%s: Test run answer: %.2lf\n", name, tested_func(coef, len, x));
  timer_begin();
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 1000; j++) {
      tested_func(coef, len, x);
    }
  }
  double time = timer_end();
  printf("%s: %.2lf time elapsed.\n", name, time);
  return time;
}

int main(int argc, char *argv[]) {
  const int n = 100;
  double coef[n];
  double x;
  srand(time(NULL));
  x = rand() % 10;
  for (int i = 0; i < n; i++) {
    coef[i] = rand() % 10;
  }
  double poly_naive = test_func("poly_naive", polynomial_naive, coef, n, x);
  double poly_qinjiushao =
    test_func("poly_qinjiushao", polynomial_qinjiushao, coef, n, x);
  printf("Boost: %.2lf\n", (poly_naive - poly_qinjiushao) / poly_naive);

  double posy_naive = test_func("posy_naive", posynomial_naive, coef, n, x);
  double posy_qinjiushao =
    test_func("posy_qinjiushao", posynomial_qinjiushao, coef, n, x);
  printf("Boost: %.2lf\n", (posy_naive - posy_qinjiushao) / posy_naive);

  return 0;
}
