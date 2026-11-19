#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void generateArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void copyArr(int *original, int *copy, int n) {
    for (int i = 0; i < n; i++) {
        copy[i] = original[i];
    }
}

int main() {
    srand(time(NULL));
    int sizes[] = {10, 1000, 10000, 100000};
    for (int i = 0; i < 4; i++) {
        int n = sizes[i];
        int *original = malloc(n * sizeof(*original));
        generateArr(original, n);

        //Пузырёк
        long long swap_count_bubble = 0;
        int *copy_bubble = malloc(n * sizeof(*copy_bubble));
        copyArr(original, copy_bubble, n);
        clock_t start_bubble = clock();
        bubbleSort(copy_bubble, n, &swap_count_bubble);
        clock_t end_bubble = clock();
        double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

        //Вставки
        long long swap_count_insertion = 0;
        int *copy_insertion = malloc(n * sizeof(*copy_insertion));
        copyArr(original, copy_insertion, n);
        clock_t start_insertion = clock();
        insertionSort(copy_insertion, n, &swap_count_insertion);
        clock_t end_insertion = clock();
        double time_insertion = (double)(end_insertion - start_insertion) / CLOCKS_PER_SEC;

        //Слияние
        long long swap_count_merge = 0;
        int *temp = malloc(n * sizeof(int));
        int *copy_merge = malloc(n * sizeof(*copy_merge));
        copyArr(original, copy_merge, n);
        clock_t start_merge = clock();
        mergeSort(copy_merge, temp, 0, n - 1, &swap_count_merge);
        clock_t end_merge = clock();
        double time_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

        //Вывод
        printf("size: %d \n", n);
        printf("[bubble: %f sec, swaps: %lld] O(n^2)\n", time_bubble, swap_count_bubble);
        printf("[insertion: %f sec, swaps: %lld] O(n^2)\n", time_insertion, swap_count_insertion);
        printf("[merge: %f sec, swaps: %lld] O(n logn)\n\n", time_merge, swap_count_merge);

        free(original);
        free(copy_bubble);
        free(copy_insertion);
        free(copy_merge);
        free(temp);
    }
    return 0;
}
