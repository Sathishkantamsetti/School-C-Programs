#include <stdio.h>

int main() {

	FILE *fp;
	int anzahl_c = 0, temp;

	fp = fopen("./text.txt", "r");

	if (fp == NULL) {
		printf("Datei konnte nicht geoeffnet werden.\n");
	} else {
		// komplette Datei zeichenweise ausgeben
		while((temp = fgetc(fp))!=EOF) {
			printf("%c ", temp);
			if (temp == 'c') anzahl_c++;
		}
		fclose(fp);
		printf("Der Buchstabe 'c' (lower case) kommt im Text %d mal vor.\n", anzahl_c);
	}

}
