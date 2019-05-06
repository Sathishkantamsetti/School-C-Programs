#include <stdio.h>

int main(void){
	int note;
	char* fehlermeldung = "Ihre Eingabe ist nicht gueltig.";
	while (1) {
		printf("Geben Sie eine Note ein: ");
		scanf("%d", &note);

		switch (note) {
			case 1:
				printf("sehr gut");
				break;
			case 2:
				printf("gut");
				break;
			case 3:
				printf("befriedigend");
				break;
			case 4:
				printf("ausreichend");
				break;
			case 5:
				printf("mangelhaft");
				break;
			case 6:
				printf("ungenuegend");
				break;
			default:
				printf("%s", fehlermeldung);
		}
		printf("\n--------------------------\n");
	}

	return 0;
}
