%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
	  stream stmt '\n' { 	
							if($2 != NULL) { 
								printf("Execute\n");
								execute($2); 
							} 
							char* current_dir = (char*)get_current_dir_name();
							printf("bshell:%s:>", current_dir); 
							free(current_dir);
						}
	  |
	  ;

stmt:
	PATH args { search_bins(&$1); $$ = push(&$2, $1); }
	| LOAD_BIN args { set_up_bins($2); $$ = NULL; }
	| CD args { 
				$$ = NULL;
				char* current_dir = pop(&$2);
				chdir(current_dir);
				free(current_dir); 
			  }
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

