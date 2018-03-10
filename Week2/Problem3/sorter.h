#ifndef __SORTER_H__
#define __SORTER_H__

class Sorter {
 public:
    static void bubble_sort(int *arr, int len);
    static void quick_sort(int *arr, int len);
    static void radix_sort(int *arr, int len);
};

#endif