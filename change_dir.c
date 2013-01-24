#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

extern int search(const char* dir_path, const char* name);
char* append_slash(char* word);

char* current_dir;

char** bin_list;

size_t bin_list_size;

void set_up_bins(list_t *list) {
	bin_list_size = len(list);
	bin_list = malloc(bin_list_size);
	int index = 0;
	while(list != NULL) {
		bin_list[index++] = append_slash(pop(&list));
	}
}

char* append_slash(char* word) {
	int len = strlen(word);
	if(word[len - 1] != '/') {
		char* temp = malloc(len + 1);
		char* slash = "/";
		strcpy(temp, word);
		strcpy(temp + len, slash);
		free(word);
		return temp;
	}
	return word;
}

void set_current_dir(char* new_dir) {
	if(strlen(new_dir) >= 2 && new_dir[0] == '.' && new_dir[1] == '.') {
		int len = strlen(current_dir);
		if(len > 1) {
			current_dir[--len] = '\0';
			for(len--; current_dir[len] != '/'; len--) {
				current_dir[len] = '\0';
			}
		}
	} else {
		free(current_dir);
		current_dir = append_slash(new_dir);
	}
}

int search_bins(char** name) {
	int index;
	char* ret_val;
	for(index = 0; index < bin_list_size; index++) {
		if(search(bin_list[index], *name)) {
			ret_val = malloc(strlen(bin_list[index]) + strlen(*name) + 1);
			strcpy(ret_val, bin_list[index]);
			strcpy(ret_val + strlen(bin_list[index]), *name);
			free(*name);
			(*name) = ret_val;
			return 1;
		}
	}
	return 0;
}

int search_current_dir(char** name) {
	if(strlen(*name) >= 2 && (*name)[0] == '.' && (*name)[1] == '.') {
		return 0;
	}
	if(search(current_dir, *name)) {
		int current_len = strlen(current_dir);
		char* temp = malloc(strlen(*name) + current_len + 1);
		strcpy(temp, current_dir);
		strcpy(temp + current_len, *name);
		free(*name);
		(*name) = temp;
		return 1;
	}
	return 0;
}

