#include "item.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// list impl
// week10 - steveh - prog71990-w25

/// <summary>
/// adds item to list. 
/// list must be existing or at least NULL initialized
/// </summary>
/// <param name="list">initialized list</param>
/// <param name="i">item to be added</param>
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

/// <summary>
/// remove item from list
/// </summary>
/// <param name="list">initialized list</param>
/// <param name="i">item to be removed</param>
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

/// <summary>
/// displays a list of items to screen
/// </summary>
/// <param name="list">initialized list</param>
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
/// <param name="list">initialized list</param>
void DeleteList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		DeleteItem(tmp->data);
		free(tmp);
	}
}