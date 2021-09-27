// Jacob Brooker
//
// PROG72365 Winter 2021
//
// Assignment01

#include "patients.h"

int main(int argc, char* argv[])
{
	int numberOfPatients = atoi(argv[1]);			// converts command line input into int number of patients

	srand(clock());									// seed random using cpu clock cycles since program start

	PQUEUE queue = initializeQueue();				// initialize queue

	if (fillQueue(queue, numberOfPatients))			// this function will return 0 if successfull and 1 if unsuccessfull
	{
		fprintf(stderr, "Application failed to create required number of patients - now exiting\n");
		exit(EXIT_FAILURE);
	}
		
	for (int i = 0; i < numberOfPatients; i++)
	{
		dequeue(queue);								// dequeue each patient in the queue one by one and display to terminal
	}

	freeQueue(queue);								// free queue

	exit(EXIT_SUCCESS);								// exit program	
}