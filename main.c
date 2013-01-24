#include<stdio.h>
#include"change_dir.h"
#include"gram.tab.h"

int main() {
	char* home = "/home/brendan";
	current_dir = home;
	printf("bshell:%s:>", current_dir);
	return yyparse();
}

