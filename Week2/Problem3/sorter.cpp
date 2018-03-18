#include "sorter.h"
#include <algorithm>
#include <memory.h>
#include "stdlib.h"

void Sorter::bubble_sort(int* arr, int len) {
  int i, j;
  for (i = 0; i < len - 1; i++)
    for (j = 0; j < len - 1 - i; j++)
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
}

int partition(int* arr, int low, int high) {
  int pivot = arr[low];  // no randomize, sorry
  int i = low;
  for (int j = low + 1; j < high; j++) {
    if (arr[j] < pivot) {
      std::swap(arr[++i], arr[j]);
    }
  }
  std::swap(arr[i], arr[low]);
  return i;
}

void quicksort(int* arr, int low, int high) {
  if (low + 1 < high) {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot);
    quicksort(arr, pivot + 1, high);
  }
}

void Sorter::quick_sort(int* arr, int len) {
  quicksort(arr, 0, len);
}

// Base 10, sorry
// I know you love Base 65536, right?
void Sorter::radix_sort(int* arr, int len) {
  int max = arr[0];
  for (int i = 1; i < len; i++) {
    if (max < arr[i])
      max = arr[i];
  }

  // From LSB to MSB
  int* temp = (int*)malloc(sizeof(int) * len);
  for (int exp = 1; max / exp > 0; exp *= 10) {
    // now sort the digit 'exp'
    memset(temp, 0, sizeof(int)*len);
    int count[10] = {0};
    for (int i = 0; i < len; i++) {
      count[(arr[i] / exp) % 10]++;
    }
    // Prefix sum
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; i--) {
      temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    memcpy(arr, temp, sizeof(int) * len);
  }
  free(temp);
}
