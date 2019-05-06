#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int int_input(char *str, int min, int max);

int main(void) {
	int anzahl_geister, ektoplasma, groesse;
	char klassenamen[3][20] = {"nieder Geist", "normaler Geist", "hoeher Geist"};
	
	printf("Anzahl der Geister: ");
	scanf("%d", &anzahl_geister);

	int *klasse_array = malloc(sizeof (int) * anzahl_geister);
	int *machtlevel_array = malloc(sizeof (int) * anzahl_geister);
	char *bereich_array = malloc(sizeof (char) * anzahl_geister);

	for (int i = 0; i < anzahl_geister; i++) {
		printf("\n%d. Geist:", i+1);

		klasse_array[i] = int_input("klasse: ", 0, 2);
		ektoplasma = int_input("Ektoplasma: ", 0, INT_MAX);
		groesse = int_input("Groesse: ", 1, 666);

		machtlevel_array[i] = ektoplasma / (groesse * groesse);

		if (machtlevel_array[i] <= 17)
			bereich_array[i] = 'A';
		else if (machtlevel_array[i] <= 24)
			bereich_array[i] = 'B';
		else
			bereich_array[i] = 'C';
	}

	printf("\nErgebnisse: \n\n");

	for (int i = 0; i < anzahl_geister; i++) {
		printf("\tDer %d. Geist ist ein %s. Sein Machtlevel ist %d. Er soll im Bereich %c eingekerkert werden.\n\n", i+1, klassenamen[klasse_array[i]], machtlevel_array[i], bereich_array[i]);
	}

	return 0;
}

int int_input(char *str, int min, int max) {
	int result;
	printf("\n\t%s", str);
	scanf("%d", &result);
	while (result < min || result > max) {
		printf("\tUngueltige Eingabe. Geben Sie einen Wert zwischen %d und %d: ", min, max);
		scanf("%d", &result);
	}
	return result;
}