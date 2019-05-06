#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int val;
	struct node *next;
} node_t;

node_t *new_linked_list(int len);
void random_assing_digits(node_t *head);
int digits_are_equal(node_t *head);
void print_digits(node_t *head);


int main(void) {
	int rounds = 0;
	int wins = 0;
	node_t *random_num;
	random_num = new_linked_list(3);

	srand(time(NULL));

	printf("Wollen Sie eine feste Anzahl an Runden spielen? (ja/nein)\n");

	if ( (getchar()) == 'j') {

		do {
			printf("Anzahl der Runden: ");
			while ((getchar()) != '\n') {} // empties input buffer
			scanf("%d", &rounds);

		} while (rounds <= 0);

		for (int i = 0; i < rounds; i++) {
			random_assing_digits(random_num);
			print_digits(random_num);
			if (digits_are_equal(random_num)) {
                wins++;
				printf("WIN!!!\n\n");
			}
		}
		printf("Du hast %d Runden gewonnen und %d Runden verloren.\n", wins, rounds - wins);

	} else {

		do {
			rounds++;
			random_assing_digits(random_num);
			print_digits(random_num);
		} while (!digits_are_equal(random_num));
		printf("Du hast %d Runden bis zum Gewinn gebraucht.\n", rounds);

	}

  return 0;
}


node_t * new_linked_list(int len) {
	node_t *head = malloc(sizeof(node_t));
	node_t *current = head;

	while (len > 1) {
		current->next = malloc(sizeof(node_t));
		current = current->next;
		len--;
	}
	current->next = NULL;

	return head;
}

void random_assing_digits(node_t *head) {
	node_t *current = head;
	while (current != NULL) {
		current->val = rand() % 10;
		current = current->next;
	}
}

int digits_are_equal(node_t *head) {
	node_t *current = head->next;
	int first_val = head->val;

	while (current != NULL) {
		if (current->val != first_val)
			return 0;
		current = current->next;
	}

	return 1;
}

void print_digits(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

