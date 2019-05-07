#include<stdio.h>

int main() {

	FILE *fp;
	int i, temp;
	fp = fopen("/home/pi/Desktop/Programme/Dateioperationen/openthesaurus.txt", "r");

	if(fp == NULL) {
		printf("Datei konnte nicht geoeffnet werden.\n");
	} else {
		// komplette Datei zeichenweise ausgeben
		while((temp = fgetc(fp))!=EOF) {
			if (temp == ';' || temp == '\n') i++;
		}
		fclose(fp);
		printf("Es existieren %d mit Semicolons getrennte Zeichenketten.\n", i+1);
		

	}

}
