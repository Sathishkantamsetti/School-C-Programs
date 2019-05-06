#include <stdio.h>

int main(void){
	int zahl1, zahl2, zahl3, zahl4;
	int summe, diff, produkt, quot, rest;

	printf("Zahl 1: ");
	scanf("%d", &zahl1);

	printf("Zahl 2: ");
	scanf("%d", &zahl2);

	printf("Zahl 3: ");
	scanf("%d", &zahl3);

	printf("Zahl 4: ");
	scanf("%d", &zahl4);


	summe = zahl1 + zahl2;
	diff = zahl2 - zahl4;
	produkt = zahl2 * zahl3;
	quot = zahl4 / zahl3;
	rest = zahl4 % zahl3;

	printf("\nDie Summe von %d und %d ist: %d\n", zahl1, zahl2, summe);
	printf("Die Differenz von %d und %d ist: %d\n", zahl2, zahl4, diff);
	printf("Das Produkt von %d und %d ist: %d\n", zahl2, zahl3, produkt);
	printf("Der Quotient von %d und %d ist: %d\n", zahl4, zahl3, quot);
	printf("Der Rest der Modulo-Division aus %d und %d ist: %d\n", zahl4, zahl3, rest);

	return 0;
}
