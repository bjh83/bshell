#ifndef CHANGE_DIR_H
#define CHANGE_DIR_H

#include"list.h"
extern char* current_dir;
void set_current_dir(const char* new_name);
void set_up_bins(list_t* list);
int search_bins(char** name);
int search_current_dir(char** name);
#endif

