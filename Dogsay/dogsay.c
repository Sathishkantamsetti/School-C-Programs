#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc >= 3) {
		int times = atoi( argv[1] );
		int delay = atoi( argv[2] );
		char *command = "fortune";
		
		if (argc == 4) {
			char *speaker = argv[3];
			if (strcmp(speaker, "cow") == 0)
				command = "fortune | cowsay";
			else if (strcmp(speaker, "tux") == 0)
				command = "fortune | cowsay -f tux";
		}
		
		
		
		for (int i = 0; i < times; i++) {
			system(command);
			sleep(delay);
		}
	} else {
		printf("dogsay <wiederholungenanzahl> <verzoegerung>\n");
		return 1;
	}
	
	return 0;
}
