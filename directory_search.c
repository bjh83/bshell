#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

char* search_term;

int filter(const struct dirent* entry) {
	if(strcmp(entry->d_name, search_term) == 0) {
		return 1; //Term matches
	} else {
		return 0; //Term does not match
	}
}

int search(const char* dir_path, char* search_name) {
	search_term = search_name;
	int found = 0;
	struct dirent** entry_list;
	int num = scandir(dir_path, &entry_list, &filter, alphasort);
	if(num > 0) {
		found = 1;
	}
	while(num--) {
		free(entry_list[num]);
	}
	free(entry_list);
	return found;
}

