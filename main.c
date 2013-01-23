#include<stdio.h>
#include"change_dir.h"
#include"gram.tab.h"

int main() {
	printf("bshell:%s:>", current_dir);
	return yyparse();
}

