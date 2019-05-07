#include <stdio.h>
#define LEN 7

void swap(int *a, int *b);
void printArr(int *arr, int len);

int main(int argc, char **argv) {
	int arr[] = {7, 1, 3, 2, 5, 4, 17};

	printf("Eingegebenes Feld: ");
	printArr(arr, LEN);
	printf("\n");

	for (int i = LEN-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1])
				swap(arr+j, arr+j+1);
		}
	}
	
	printf("Sortiertes Feld: ");
	printArr(arr, LEN);
	printf("\n");
	
	return 0;
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
