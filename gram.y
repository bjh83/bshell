%{
#include<stdio.h>
#include<string.h>
#include"change_dir.h"
#include"list.h"
int yylex();
void yyerror(char *string);
extern int execute(list_t* args);
%}

%start stream

%union {
	char* str;
	struct linked_list* list;
}

%token CD

%token<str> PATH

%type<list> stmt args

%%

stream:
	  stream stmt '\n' { if($2 != NULL) { printf("Execute\n"); execute($2); } 
							printf("bshell:%s:>", current_dir); }
	  |
	  ;

stmt:
	PATH args { $$ = push(&$2, $1); }
	| CD args { $$ = NULL; char* val = pop(&$2); printf("Change dir: %s\n", val); set_current_dir(val); }
	|
	;

args:
	args PATH { $$ = push(&$1, $2); }
	| { $$ = NULL; }
	;

%%

void yyerror(char *err_string) {
	printf("%s\n", err_string);
}

