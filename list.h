#ifndef LIST_H
#define LIST_H
struct linked_list {
	struct linked_list* next;
	char* value;
};

typedef struct linked_list list_t;

list_t* push(list_t** list, char* value);

char* pop(list_t** list);

int len(list_t* list);
#endif

