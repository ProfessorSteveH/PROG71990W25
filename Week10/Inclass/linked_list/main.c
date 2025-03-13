#include "item.h"
#include "list.h"
#include <stdio.h>

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(1));
	Add(&list, CreateItem(2));
	Add(&list, CreateItem(3));

	DisplayList(list);

	DeleteList(&list);//gone destroyed, in the past.
 

	//ITEM i = CreateItem(1);
	//PrintItem(i);
	//DeleteItem(i);

	return 0;
}