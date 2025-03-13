#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void Add(PLISTNODE* list, ITEM i) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (newNode == NULL) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	else {
		newNode->data = CopyItem(i);
		newNode->next = *list;
		
		*list = newNode;
	}
}

void Remove(PLISTNODE* list, ITEM i) {
	PLISTNODE current = *list;
	if (current != NULL && CompareItems(current->data, i)) {
		*list = current->next;
		DeleteItem(current->data);
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareItems(current->data, i)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;				// end of list, not found
	else {
		prev->next = current->next;
		DeleteItem(current->data);
		free(current);
	}

}

void DisplayList(PLISTNODE list) {
	PLISTNODE current = list;
	while (current != NULL) {
		PrintItem(current->data);
		current = current->next;
	}
}

/// <summary>
/// removes all items and destroys the list.  
/// note: list is not consistent after delete
/// </summary>
/// <param name="list"></param>
void DeleteList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		DeleteItem(tmp->data);
		free(tmp);
	}
}