#include <stdio.h>

int subtrahieren(int a, int b);

int main(void) {
	int a, b;
	
	printf("Erste Zahl: ");
	scanf("%d", &a);
	printf("Zweite Zahl: ");
	scanf("%d", &b);
	
	printf("\n%d - %d = %d\n", a, b, subtrahieren(a, b));
	return 0;
}

int subtrahieren(int a, int b) {
	return a - b;
}
