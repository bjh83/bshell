#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"change_dir.h"
#include"gram.tab.h"

int main() {
	char* current_dir = (char*)get_current_dir_name();
	printf("bshell:%s:>", current_dir);
	free(current_dir);
	return yyparse();
}

