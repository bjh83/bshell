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

char* search(const char* dir_path, const char* search_name) {
	search_term = search_name;
	char* ret_val = NULL;
	struct dirent** entry_list;
	int num = scandir(dir_path, &entry_list, &filter, alphasort);
	while(num--) {
		if(ret_val == NULL) {
			ret_val = entry_list[num]->d_name;
			printf("%s\n", ret_val);
		} else {
			free(entry_list[num]);
		}
	}
	free(entry_list);
	return ret_val;
}

