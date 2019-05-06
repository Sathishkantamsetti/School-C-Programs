#include <stdio.h>

int main(void) {
    int dog_age, human_age;
	while (1) {
        printf("Alter des Hundes: ");
        scanf("%d", &dog_age);

        if (dog_age == 1) {
            human_age = 14;
        } else if (dog_age == 2) {
            human_age = 22;
        } else {
            human_age = 22 + (5 * (dog_age - 2));
        }

        printf("Entsprechendes menschlisches Alter: %d\n", human_age);
        printf("_______________________________________\n\n");
	}
	return 0;
}
