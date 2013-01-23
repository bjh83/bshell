%{
#include<stdio.h>
#include<string.h>
int yylex();
void yyerror(char *string);
extern int execute(char* value);
void concat(char* list, char* word);
%}

%start stream

%union {
	char *str;
}

%token<str> WORD

%type<str> stream stmt

%%

stream:
	  stream stmt '\n' { execute($2); }
	  |
	  ;

stmt:
	stmt WORD { concat($$, $2); }
	| { $$ = NULL; }
	;

%%

void yyerror(char *err_string) {
	printf("%s\n", err_string);
}

void concat(char* list, char* word) {
	if(list != NULL) {
		char* space = " ";
		list = strcat(list, space);
	} else {
		list = malloc(256);
	}
	list = strcat(list, word);
}

