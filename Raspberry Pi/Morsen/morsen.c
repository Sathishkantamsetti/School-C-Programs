#include <stdio.h>
#include <ctype.h>
#include <wiringPi.h>

#define PIN_NUMBER 7
#define DIT_DELAY 200
#define MAX_INPUT_LENGTH 1000

char code[27][5] = {
	{'a','k','l','x','x'},
	{'b','l','k','k','k'},
	{'c','l','k','l','k'},   
	{'d','l','k','k','x'},  
	{'e','k','x','x','x'},  
	{'f','k','k','l','k'},
	{'g','l','l','k','x'},
	{'h','k','k','k','k'},   
	{'i','k','k','x','x'},  
	{'j','k','l','l','l'}, 
	{'k','l','k','l','x'},
	{'l','k','l','k','k'},
	{'m','l','l','x','x'},   
	{'n','l','k','x','x'},  
	{'o','l','l','l','x'}, 
	{'p','k','l','l','k'},
	{'q','l','l','k','l'},
	{'r','k','l','k','x'},   
	{'s','k','k','k','x'},  
	{'t','l','x','x','x'}, 
	{'u','k','k','l','x'},   
	{'v','k','k','k','l'},  
	{'w','k','l','l','x'}, 
	{'x','l','k','k','l'},
	{'y','l','k','l','l'},
	{'z','l','l','k','k'},
	{' ','x','x','x','x'},
};
void morsen(char);
void blink(char);


int main(void) {
	wiringPiSetup();
	pinMode(PIN_NUMBER, OUTPUT);

	int i = 0;
	char input_text[MAX_INPUT_LENGTH];
	printf("Text eingeben: ");
	fgets(input_text, MAX_INPUT_LENGTH, stdin);
	
	while (input_text[i] != '\0') {
		morsen( tolower(input_text[i]) );
		i++;
	}
	
	return 0;
}

void morsen(char letter) {
	for (int i = 0; i < 26; i++) {
		if (letter == code[i][0]) {
			printf("%c:  ", code[i][0]);
			for (int j = 1; j < 5; j++) {
				if (code[i][j] == 'l')
					printf("_ ");
				else if (code[i][j] == 'k')
					printf(". ");
				blink(code[i][j]);
				delay(DIT_DELAY);
			}
			printf("\n");
			delay(DIT_DELAY*2);
		}
	}
}

	
void blink(char value) {
	digitalWrite(PIN_NUMBER, HIGH);
	if (value == 'k')
		delay(DIT_DELAY);
	else if (value == 'l')
		delay(DIT_DELAY * 3);
		
	digitalWrite(PIN_NUMBER, LOW);
}
