/*
 * threads.h
 *
 *  Tarek Salama | February 5, 2017
 *  CSE 330
 *
 */

#ifndef THREADS_H_
#define THREADS_H_

#include "q.h"
#include <stdio.h>

TCB_t *RunQ;

void start_thread(void (*function)(void)) {
	// allocate a stack (via malloc) of a certain size (choose 8192)
	void *stack = malloc(8192);

	// allocate a TCB (via malloc)
	TCB_t *tcb = malloc(sizeof(TCB_t));

	// call init_TCB with appropriate arguments
	init_TCB(tcb, function, stack, 8192);

	// call addQ to add this TCB into the �RunQ� which is a global header pointer
	AddQueue(&RunQ, tcb);
}

void run() {
	//get a place to store the main context, for faking
	ucontext_t parent;

	//magic sauce
	getcontext(&parent);

	//start the first thread
	swapcontext(&parent, &(RunQ->context));
}

void yield() {
	//rotate the Run Q
	TCB_t *temp = RunQ;
	TCB_t *newQ;

	RotateQ(&RunQ);

	//swap the context, from previous thread to the thread pointed to by RunQ
	newQ = RunQ;
	swapcontext(&(temp->context), &(newQ->context));
}

#endif /* THREADS_H_ */
