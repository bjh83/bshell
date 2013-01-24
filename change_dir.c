#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern char* search(const char* dir_path, const char* name);

char* current_dir;

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

