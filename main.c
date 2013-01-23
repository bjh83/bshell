#include<stdio.h>
#include"gram.tab.h"

int main() {
	printf("bshell>");
	return yyparse();
}

