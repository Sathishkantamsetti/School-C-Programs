#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAYS_NUMBER 100
#define ARRAY_LEN 9

void sort(int *arr, int len);
int isSorted(int *arr, int len);
void shuffle(int *arr, int len);
void swap(int *a, int *b);
void printArr(int *arr, int len);
int *generateRandArr(int len);

int main(void) {
    srand(time(NULL));
    clock_t start, end;
    double timeTaken;
    int *arr = NULL;

    start = clock();

    for (int i = 0; i < ARRAYS_NUMBER; i++) {
        arr = generateRandArr(ARRAY_LEN);

        printf("Unsortiert: ");
        printArr(arr, ARRAY_LEN);

        sort(arr, ARRAY_LEN);

        printf("\nSortiert: ");
        printArr(arr, ARRAY_LEN);
        printf("\n\n");

        free(arr);
    }

    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Dauer: %.3lfs\n", timeTaken);
    system("PAUSE");

	return 0;
}


void sort(int *arr, int len) {
    int randNum1, randNum2;
    while (!isSorted(arr, len)) {
        randNum1 = rand() % len;
        randNum2 = rand() % len;
        swap(arr+randNum1, arr+randNum2);
    }
}


int isSorted(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        if (arr[i] > arr[i+1])
            return 0;
    }
    return 1;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}


int *generateRandArr(int len) {
    int *ptr = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        ptr[i] = rand();
    }
    return ptr;
}
