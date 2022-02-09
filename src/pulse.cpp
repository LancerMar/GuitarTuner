#include <iostream>

#include <pigpio.h>

void callback(uint32_t signal) {
	std::cout << "signal = " << signal << std::endl;
}

int main(int argc, char *argv[]){
	double start;

	if (gpioInitialise() < 0){
		fprintf(stderr, "piggpio initialisation failed\n");
		return 1;
	}

	/*  Set GPIO modes */
	gpioSetMode(20, PI_INPUT);
	//printf("%d", gpioGetMode(20));
	return 0;
}

