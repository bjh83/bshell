#include<stdlib.h>

extern char* search(const char* dir_path, const char* name);

char* current_dir = "/home/brendan";

void set_current_dir(char* new_dir) {
	free(current_dir);
	current_dir = new_dir;
}

char* get_path(const char* name) {
	return search(current_dir, name);
}

