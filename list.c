#include<stdlib.h>
#include"list.h"

list_t* push(list_t** list, char* value) {
	list_t* head = malloc(sizeof(list_t));
	head->next = *list;
	head->value = value;
	(*list) = head;
	return head;
}

char* pop(list_t** list) {
	list_t* head = *list;
	(*list) = (*list)->next;
	char* ret_val = head->value;
	free(head);
	return ret_val;
}

int len(list_t* list) {
	int depth;
	for(depth = 0; list != NULL; depth++) {
		list = list->next;
	}
	return depth;
}

