#include "participant.h"
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
bool Add(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (newNode == NULL) {
		fprintf(stderr, "error allocating memory\n");
		return false;
	}
	else {
		newNode->data = CopyParticipant(p);
		newNode->next = *list;
		
		*list = newNode;
	}
	return true;
}

/// <summary>
/// remove item from list
/// </summary>
/// <param name="list">initialized list</param>
/// <param name="i">item to be removed</param>
void Remove(PLISTNODE* list, PARTICIPANT p) {
	PLISTNODE current = *list;
	if (current != NULL && CompareParticipants(current->data, p)) {
		*list = current->next;
		DestroyParticipant(current->data);
		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareParticipants(current->data, p)) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		return;				// end of list, not found
	else {
		prev->next = current->next;
		DestroyParticipant(current->data);
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
		PrintParticipant(current->data);
		current = current->next;
	}
}

void WriteListToStream(PLISTNODE list, FILE* stream) {
	PLISTNODE current = list;
	while (current != NULL) {
		WriteParticipantToStream(current->data, stream);
		current = current->next;
	}
}

int GetListCount(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}


PARTICIPANT* FindParticipantInList(PLISTNODE list, PARTICIPANT p) {
	PLISTNODE current = list;
	while (current != NULL) {
		if (CompareParticipants(current->data, p))
			return(&(current->data));
		current = current->next;
	}
	return (PARTICIPANT*)NULL;
}

PARTICIPANT* rFindParticipantInList(PLISTNODE list, PARTICIPANT p) {
	PLISTNODE current = list;
	// base - how do we know we are done
	if(current == NULL)
		return (PARTICIPANT*)NULL;
	// recursive step (how we procceed towards being done
	else {		// 2cases
		if (CompareParticipants(current->data, p))
			return(&(current->data));
		else
			rFindParticipantInList(current->next, p);
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
		DestroyParticipant(current->data);
		current = current->next;
		free(tmp);
	}
}
