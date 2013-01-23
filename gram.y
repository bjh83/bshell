%{
#include<stdio.h>
#include<string.h>
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

%token<str> WORD

%type<str> command

%type<list> stmt args

%%

stream:
	  stream stmt '\n' { execute($2); printf("bshell>"); }
	  |
	  ;

stmt:
	command args { $$ = push(&$2, $1); }
	|
	;

command:
	   WORD { $$ = $1; }
	   ;

args:
	args WORD { $$ = push(&$1, $2); }
	| { $$ = NULL; }
	;

%%

void yyerror(char *err_string) {
	printf("%s\n", err_string);
}

