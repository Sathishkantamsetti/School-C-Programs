#include <stdio.h>
#include <wiringPi.h>

#define PIN_NUMBER 7

int texts[10][100] = {
	"Wie geht es dir?",
	"Ich bin ein Dämon",
	"Pommes",
	"Linux ist besser als Windows"
};


int main(void) {
	wiringPiSetup();
	pinMode(PIN_NUMBER, INPUT);
	digitalWrite(PIN_NUMBER, LOW);

	while (1) {
		if (digitalRead(PIN_NUMBER) == HIGH) {
			system("espeak -vde Hallo");
		}
	}
	
	
	return 0;
}
