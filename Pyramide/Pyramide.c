#include <stdio.h>

void drawPyramid(int rows, char *str, int strLen);
void drawRow(int count, char *string, int strLen);
void printSpaces(int count);
int getStringLength(char *str);

int main(void){
    int rows, strLen;
    char string[30];

	printf("Rows: ");
	scanf("%d", &rows);

	printf("Building Block (String): ");
	scanf("%s", string);

	strLen = getStringLength(string);

	drawPyramid(rows, string, strLen);

    printf("\n\nPress ENTER to exit...");
    fflush(stdin);
	getchar();//Prevent the program from closing
	return 0;
}

void drawPyramid(int rows, char *str, int strLen) {
	for (int i = 1; i <= rows; i++) {
		printSpaces((rows - i) * strLen + 1);
		drawRow(i, str, strLen);
		printf("\n");
	}

}

void printSpaces(int count) {
	for (int i = 0; i < count; i++) {
		printf(" ");
	}
}

void drawRow(int count, char *str, int strLen) {
	for (int i = 1; i < count*2; i++) {
		if (i % 2 == 0) {
            for (int j = 0; j < strLen; j++) {
                printf(" ");
            }
		} else {
			printf("%s", str);
		}
	}
}

int getStringLength(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
