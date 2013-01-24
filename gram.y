%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"change_dir.h"
#include"list.h"
int yylex();
void yyerror(char *string);
extern int execute(list_t* args);
char* get_dot();
%}

%start stream

%union {
	char* str;
	struct linked_list* list;
}

%token CD
%token LOAD_BIN

%token<str> PATH

%type<list> stmt args

%%

stream:
	  stream stmt '\n' { if($2 != NULL) { printf("Execute\n"); execute($2); } 
							printf("bshell:%s:>", current_dir); }
	  |
	  ;

stmt:
	PATH args { search_bins(&$1); if($2 == NULL) {
				$2 = push(&$2, strdup(current_dir)); } $$ = push(&$2, $1); }
	| LOAD_BIN args { set_up_bins($2); $$ = NULL; }
	| CD args { $$ = NULL; set_current_dir(pop(&$2)); }
	|
	;

args:
	args PATH { search_current_dir(&$2); $$ = push(&$1, $2); }
	| { $$ = NULL; }
	;

%%

void yyerror(char *err_string) {
	printf("%s\n", err_string);
}

