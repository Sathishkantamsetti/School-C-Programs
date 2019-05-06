#include <stdio.h>

int menu(void);
void samer_einlagern(int artikelnummer, int regalnummer);
double easteregg(int tag, int monat, int jahr);

int main(void) {
	int artikelnummer, regalnummer, tag, monat, jahr;
	double mittel;
	
	while (1) {
		switch (menu()) {
			case 1:
				printf("Artikelnummer: ");
				scanf("%d", &artikelnummer);
				printf("Regalnummer: ");
				scanf("%d", &regalnummer);
				
				samer_einlagern(artikelnummer, regalnummer);
				break;
				
			case 2:
				printf("Tag: ");
				scanf("%d", &tag);
				printf("Monat: ");
				scanf("%d", &monat);
				printf("Jahr: ");
				scanf("%d", &jahr);
				
				mittel = easteregg(tag, monat, jahr);
				printf("Das arithmetische Mittel Ihrer Eingaben betraegt %lf", mittel);
				break;
			
			default:
				printf("Geben Sie bitte nur '1' oder '2' ein.\n");
		}
	}
	
	return 0;
}

int menu(void) {
	int auswahl;
	printf("\n\nWillkommen im 1-3-4-7 Store Sales ans Storage System.\n");
	printf("Treffen Sie eine Auswahl:\n");
	printf("1) Ein Produkt einlagern.\n");
	printf("2) Easter Egg.\n");
	scanf("%d", &auswahl);
	return auswahl;
}

void samer_einlagern(int artikelnummer, int regalnummer) {
	int lagerhaus = 2001;
	printf("Der Artikel %d wurde in das Regal %d gelegt und befindet sich im Lagerhaus %d.", artikelnummer, regalnummer, lagerhaus);
}

double easteregg(int tag, int monat, int jahr) {
	if (tag < 0 || monat < 0 || jahr < 0) {
		printf("Fehler: tag, monat und jahr muessen positiv sein.\n");
	} else {
		double mittel = (double) (tag + monat + jahr) / 3;
		return mittel;
	}
}
