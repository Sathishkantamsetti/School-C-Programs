#include <stdio.h>


void brett_ausgeben(char brett[8][8]);
void figur_ziehen(char brett[8][8], int x1, int y1, int x2, int y2);

int main(void) {

	int x1, y1, x2, y2;
	char brett[8][8] = {
                        'T','S','L','D','K','L','S','T',
						'B','B','B','B','B','B','B','B',
						'.','.','.','.','.','.','.','.',
						'.','.','.','.','.','.','.','.',
						'.','.','.','.','.','.','.','.',
						'.','.','.','.','.','.','.','.',
						'B','B','B','B','B','B','B','B',
						'T','S','L','D','K','L','S','T',
  };


  while (1) {
    brett_ausgeben(brett);
    printf("\n");

    printf("Bitte geben Sie die Position einer Figur ein.\n");
    scanf("%d,%d", &x1, &y1);
    printf("Wohin soll die Figur zieheb?\n");
    scanf("%d,%d", &x2, &y2);

    figur_ziehen(brett, x1, y1, x2, y2);
  }

	return 0;
}

void brett_ausgeben(char brett[8][8]) {
	for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      printf("%c", brett[row][col]);
    }
    printf("\n");
  }
}

void figur_ziehen(char brett[8][8], int x1, int y1, int x2, int y2) {
	brett[x2][y2] = brett[x1][y1];
  brett[x1][y1] = '.';
}
