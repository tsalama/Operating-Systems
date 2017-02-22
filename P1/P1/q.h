/*
 * q.h
 *
 *  Tarek Salama | February 5, 2017
 *  CSE 330
 *
 */

#ifndef Q_H
#define Q_H

#include "TCB.h"
#include <stdlib.h>

// returns a pointer to a new q-element
TCB_t* NewItem() {
	TCB_t* item = (TCB_t*) malloc(sizeof(TCB_t));
	item->next = NULL;
	item->prev = NULL;

	return item;
}

// creates a empty queue, pointed to by the variable head.
void InitQueue(TCB_t **head) {
	*head = NULL;
}

// adds a queue item, pointed to by "item", to the queue pointed to by head.
void AddQueue(TCB_t **head, TCB_t* item) {
	if (*head == NULL) {
		*head = item;
		(*head)->next = *head;
		(*head)->prev = *head;
	} else {
		TCB_t* temp = *head;

		while (temp->next != *head)
			temp = temp->next;

		(*head)->prev = item;
		temp->next = item;
		item->prev = temp;
		item->next = *head;
	}
}

// deletes an item from head and returns a pointer to the deleted item
TCB_t* DelQueue(TCB_t **head) {
	TCB_t* item;

	if ((*head)->next == *head && (*head)->prev == *head) {
		item = *head;
		*head = NULL;
	} else {
		item = *head;
		*head = (*head)->next;
		(*head)->prev = (*head)->prev->prev;
		(*head)->prev->next = *head;
	}

	return item;
}

// Moves the header pointer to the next element in the queue.
// This is equivalent to AddQ(&head, DeleteQ(&head)), but is simpler to use and more efficient to implement.
void RotateQ(TCB_t **head) {
	if (*head != NULL)
		AddQueue(head, DelQueue(head));
}

#endif /* Q_H_ */
