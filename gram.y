%{
#include<string.h>
int yylex();
void yyerror(char *string);
extern int execute(char* value);
void concat(YYSTYPE list, YYSTYPE word);
%}

%start stream

%union {
	char *str;
}

%token WORD

%%

stream:
	  stream stmt '\n' { execute($2.str); }
	  |
	  ;

stmt:
	stmt WORD { concat($$, $2); }
	| { $$.str = NULL; }
	;

%%

void yyerror(char *err_string) {
	printf("%s\n", err_string);
}

void concat(YYSTYPE list, YYSTYPE word) {
	if(list.str != NULL) {
		char* space = " ";
		list.str = strcat(list.str, space);
	}
	list.str = strcat(list.str, word.str);
}

