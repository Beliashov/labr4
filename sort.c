#include "sort.h"

// Пузырёк
void bubbleSort(int arr[], int n, long long *swap_count) {
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                (*swap_count)++;
                swap = 1;
            }
        }
        if (!swap) {
            break;
        }
    }
}

// Вставки
void insertionSort(int arr[], int n, long long *swap_count) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            (*swap_count)++;
            j--;
        }
        arr[j + 1] = key;
    }
}

// 2 части
void merge(int arr[], int temp[], int left, int mid, int right, long long *swap_count) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
        (*swap_count)++;
    }
}

// Слияние
void mergeSort(int arr[], int temp[], int left, int right, long long *swap_count) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid, swap_count);
        mergeSort(arr, temp, mid + 1, right, swap_count);

        merge(arr, temp, left, mid, right, swap_count);
    }
}
