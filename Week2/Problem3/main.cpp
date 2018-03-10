#include "timer.h"
#include "sorter.h"
#include <random>
using namespace std;

typedef void (*func)(int*, int);

double test_func(const char* name, func tested_func, int arr[], int len) {
  printf("%s: Begin testing.\n", name);
  timer_begin();
  int* temp = (int*)malloc(sizeof(int) * len);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 1000; j++) {
      memcpy(temp, arr, sizeof(int) * len);
      tested_func(temp, len);
    }
  }
  double time = timer_end();
  printf("%s: %.2lf time elapsed.\n", name, time);
  memcpy(temp, arr, sizeof(int) * len);
  tested_func(temp, len);
  // Check for validity.
  for (int k = 0; k < len - 1; k++) {
    if (temp[k] > temp[k + 1]) {
      printf("%s: Wrong implementation?\n", name);
      break;
    }
  }
  free(temp);
  return time;
}

int main(int argc, char* argv[]) {
  const int n = 100;
  int arr[n];
  mt19937 rng(random_device{}());
  for (int i = 0; i < n; i++) {
    arr[i] = rng() % 1000;
  }
  double bubble_sort = test_func("bubble_sort", Sorter::bubble_sort, arr, n);
  double quick_sort = test_func("quick_sort", Sorter::quick_sort, arr, n);
  double radix_sort = test_func("radix_sort", Sorter::radix_sort, arr, n);

  printf("QuickSort over BubbleSort: %.2lf\n", (bubble_sort - quick_sort) / bubble_sort);
  printf("RadixSort over BubbleSort: %.2lf\n", (bubble_sort - radix_sort) / bubble_sort);

  return 0;
}
