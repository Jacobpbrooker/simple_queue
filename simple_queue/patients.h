#pragma once
// Jacob Brooker
//
// PROG72365 Winter 2021
//
// Assignment01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct patient {
	int patientNumber;
	int age;
}PATIENT, * PPATIENT;

typedef struct node {
	struct patient* patientData;
	struct node* pNext;
}NODE, * PNODE;

typedef struct queue {
	struct node* head;
	struct node* tail;
}QUEUE, * PQUEUE;

// creates / destory
PPATIENT createPatient();
PNODE createPatientNode();
void freeQueue(PQUEUE);
void freeNode(PNODE);
void freePatient(PPATIENT);

//queue functions
PQUEUE initializeQueue();
int fillQueue(PQUEUE, int);
bool enqueue(PQUEUE, PNODE);
void dequeue(PQUEUE);

//display
void simpleDisplayPatient(PPATIENT);