#include <iostream>

using namespace std;

#define BUFFER_SIZE 10

typedef struct {
	
} item;

void main()
{
	item buffer[BUFFER_SIZE];
	int in = 0;
	int out = 0;
	int counter = 0;
	
	item nextproduced;
	while (true) {
		while (counter == 0)
			;
		buffer[in] = nextproduced;
		counter--;
		in = (in + 1) % BUFFER_SIZE;
	}
	
	item nextconsumed;
	while (true) { 
		while (counter == BUFFER_SIZE)
			; 
		nextconsumed = buffer[out];
		counter++;
		out = (out + 1) % BUFFER_SIZE;
	}

	system("pause");
}