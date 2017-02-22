/*
 * thread_test.c
 *
 *  Tarek Salama | February 5, 2017
 *  CSE 330
 *
 */

#include "threads.h"
#include <stdbool.h>

int globalSum = 0;

void PlusOne();
void MinusTwo();
void TimesThree();

int main() {
	// Initialize RunQ
	RunQ = NewItem();
	InitQueue(&RunQ);
	printf("\nRunQ Initialized...\n");
	sleep(1);

	// Start threads
	printf("Starting Threads...\n\n");
	sleep(1);
	start_thread(&PlusOne);
	start_thread(&MinusTwo);
	start_thread(&TimesThree);

	// Call run() and watch
	run();

	return 0;
}

void PlusOne() {
	int localSum = 0;

	while (true) {
		localSum++;
		globalSum += localSum;
		printf("PlusOne Function\tLocal Sum: %d\tGlobal Sum: %d\n", localSum,
				globalSum);

		sleep(1);

		yield();
	}
}

void MinusTwo() {
	int localSum = 0;

	while (true) {
		localSum -= 2;
		globalSum += localSum;
		printf("MinusTwo Function\tLocal Sum: %d\tGlobal Sum: %d\n", localSum,
				globalSum);

		sleep(1);

		yield();
	}
}

void TimesThree() {
	int localSum = 1;

	while (true) {
		localSum *= 3;
		globalSum += localSum;
		printf("TimesThree Function\tLocal Sum: %d\tGlobal Sum: %d\n\n",
				localSum, globalSum);

		sleep(1);

		yield();

	}
}
