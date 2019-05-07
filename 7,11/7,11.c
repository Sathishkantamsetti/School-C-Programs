/*
*A Solution for the 7-Eleven problem
*Programmed by Samer Alkabbaz
*All Rights Reserved (c)
*/

#include <stdio.h>

int increase_vars(int max_val, int *a, int *b, int *c);

int main(void) {
    int sum = 7.11 * 100;
    int product = 7.11 * 100 * 100 * 100 * 100;
    int a = 1; int b = 1; int c = 1;

    do {

        if ( ((double) sum - (a + b + c)) ==  ((double) product / (a * b * c)) ) {
            printf(
                "Loesung gefunden:\n\tArtikel1 = %.2lf Euro\n\tArtikel2 = %.2lf Euro\n\tArtikel3 = %.2lf Euro\n\tArtikel4 = %.2lf Euro",
                (double) a / 100,
                (double) b / 100,
                (double) c / 100,
                (double) (sum - (a + b + c)) / 100
            );
            break;
        }

    } while (increase_vars(sum, &a, &b, &c));

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

int increase_vars(int max_val, int *a, int *b, int *c) {
    (*a)++;
    if (*a > max_val) {
        *a = 1;
        (*b)++;
        if (*b > max_val) {
            *b = 1;
            (*c)++;
            if (*c > max_val) {
                return 0;
            }
        }
    }
    return 1;
}
