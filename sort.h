#ifndef SORT_H
#define SORT_H

void bubbleSort(int arr[], int n, long long *swap_count);
void insertionSort(int arr[], int n, long long *swap_count);
void mergeSort(int arr[], int temp[], int left, int right, long long *swap_count);
void merge(int arr[], int temp[], int left, int mid, int right, long long *swap_count);

#endif
