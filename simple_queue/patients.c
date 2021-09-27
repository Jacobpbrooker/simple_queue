// Jacob Brooker
//
// PROG72365 Winter 2021
//
// Assignment01

#include "patients.h"

// create patients/patient nodes for linked list

PPATIENT createPatient()
{
	PPATIENT patient;										// create pointer to patient 

	if (!(patient = (PPATIENT)malloc(sizeof(PATIENT))))		// malloc the size of patient at the pointer to patient
	{
		fprintf(stderr, "Failed to allocate memory for patient - Now Exiting\n");
		exit(EXIT_FAILURE);
	}

	patient->age = rand() % 99;								// assign random age 0 - 99 to patient
	patient->patientNumber = (rand() % RAND_MAX + 10000)	// assign random 9 digit patient ID
		* (rand() % 5000 + 10000);

	return patient;											// return the pointer to patient
}

PNODE createPatientNode()
{
	PNODE node;												// create node pointer

	if (!(node = (PNODE)malloc(sizeof(NODE))))				// malloc the size of node at the pointer to node location
	{
		fprintf(stderr, "Failed to allocate memory for queue - Now Exiting\n");
		exit(EXIT_FAILURE);
	}

	memset(node, '\0', sizeof(NODE));						// set the malloc(ed?) memory to '\0'

	node->patientData = createPatient();					// create the patient and assign to the patient data within the node
															// node->pNext intentially left unassigned to be assigned in enqueue function
	return node;											// return the new patient node with created patient
}

// free functions

void freeQueue(PQUEUE queue)
{
	free(queue);											// free the queue
}

void freeNode(PNODE node)
{
	freePatient(node->patientData);							// dive deeper and free the patient
	free(node);												// free the node
}

void freePatient(PPATIENT patient)
{

	free(patient);											// free patient
}

// Queue Functions

PQUEUE initializeQueue()
{
	PQUEUE queue;											// create pointer to a queue variable

	if (!(queue = (PQUEUE)malloc(sizeof(QUEUE))))			// malloc the queue size of queue
	{
		fprintf(stderr, "Failed to allocate memory for queue - Now Exiting\n");
		exit(EXIT_FAILURE);
	}

	memset(queue, '\0', sizeof(QUEUE));						// set memory at queue pointer to '\0'

	return queue;											// return this new pointer to queue
}

int fillQueue(PQUEUE queue, int numPatients)
{
	int comparisonInt = 0;									// int will be used as comparison against number of patients created
	int returnInt = 1;										// set comparison int to failure to be changed upon success

	for (int i = 0; i < numPatients; i++)
	{
		if(enqueue(queue, createPatientNode()))				// enqueue the node into the queue passed argument using the createPatientNode() to fill values
			comparisonInt++;								// if node is enqueue(d?) into queue increment comparisson for return value	
	}

	if (comparisonInt == numPatients)						// compare number of patients passed as parameter and number of patients created
		returnInt = 0;										// if they are the same, return 0
	else
		returnInt = 1;										// return 1 if they are not 

	return returnInt;										// return the returnInt
}

bool enqueue(PQUEUE queue, PNODE node)  
{
	bool returnBool = false;								// set return bool

	if (queue->head == NULL)
	{
		queue->head = node;									// if the head of the queue is null set the head to this node
		queue->tail = node;									// then set the tail to the same location in the queue
		returnBool = true;									// set the return bool to true
	}
	else
	{
		queue->tail->pNext = node;							// if there is a head in the queue we set the queue tail next to the node
		queue->tail = node;									// set the queue tail to the node
		returnBool = true;									// set the return bool to true
	}

	queue->tail->pNext = NULL;								// set the queue tail pNext to NULL with each interation  	

	return returnBool;										// return bool
}

void dequeue(PQUEUE queue)
{
	simpleDisplayPatient(queue->head->patientData);			// dispay the patient
	
	QUEUE tempQUEUE;										// create a temporary copy of the queue

	tempQUEUE.head = queue->head->pNext;					// assign the head of temporary queue to the pNext of queue head
	freeNode(queue->head);									// free the node
	queue->head = tempQUEUE.head;							// set the head of the queue to the head of the temporary queue
}

// display functions

void simpleDisplayPatient(PPATIENT patient)
{
	printf("Patient | Age - %02d | Number - %d\n",			// simple display patient
		patient->age, patient->patientNumber);
}
