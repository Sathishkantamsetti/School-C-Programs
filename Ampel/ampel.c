#include <wiringPi.h>
#include <stdio.h>

int main (void) {
	wiringPiSetup();
	
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(0, OUTPUT);
	
	while (1) {
		digitalWrite(8, HIGH);
		delay(500);
		
		digitalWrite(7, HIGH);
		delay(500);
		
		digitalWrite(0, HIGH);
		delay(500);
		
		digitalWrite(8, LOW);
		delay(500);
		
		digitalWrite(7, LOW);
		delay(500);
		
		digitalWrite(0, LOW);
		delay(500);
	}
	
	return 0;
	
}
