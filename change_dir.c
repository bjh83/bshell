#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

extern char* search(const char* dir_path, const char* name);

char* current_dir;

char** bin_list;

size_t bin_list_size;

void set_up_bins(list_t *list) {
	bin_list_size = len(list);
	bin_list = malloc(bin_list_size);
	int index = 0;
	while(list != NULL) {
		bin_list[index++] = pop(&list);
	}
}

void set_current_dir(char* new_dir) {
	int len = strlen(new_dir);
	if(new_dir[len - 1] != '/') {
		char* temp = malloc(len + 1);
		char* slash = "/";
		strcpy(temp, new_dir);
		strcpy(temp + len, slash);
		free(new_dir);
		new_dir = temp;
	}
	free(current_dir);
	current_dir = new_dir;
}

char* get_path(const char* name) {
	char* result = search(current_dir, name);
	printf("%s\n", result);
	if(result != NULL) {
		char* ret_val = malloc(strlen(name) + strlen(current_dir) + 1);
		strcpy(ret_val, current_dir);
		strcpy(ret_val + strlen(current_dir), name);
		printf("%s\n", ret_val);
		free(result);
		printf("free succeeded\n");
		return ret_val;
	}
	free(result);
	return name;
}

int search_bins(char** name) {
	int index;
	char* ret_val;
	for(index = 0; index < bin_list_size; index++) {
		char* result = search(bin_list[index], *name);
		if(result != NULL) {
			free(result);
			ret_val = malloc(strlen(bin_list[index]) + strlen(*name) + 1);
			strcpy(ret_val, bin_list[index]);
			strcpy(ret_val + strlen(bin_list[index]), *name);
			free(*name);
			(*name) = ret_val;
			return 1;
		} else {
			free(result);
		}
	}
	return 0;
}

