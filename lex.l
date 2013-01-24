%{
#include<string.h>
#include<stdio.h>
#include"gram.tab.h"
#include"change_dir.h"
YYSTYPE yylval;
%}

NAME [a-zA-Z_.\-+]
SLASH [/]
PATH ({SLASH}{NAME}+)+

%%
"cd" { return CD; }
{NAME}+{PATH}? { yylval.str = get_path(strdup(yytext));
				printf("local: %s\n", yylval.str); return PATH; }
{PATH} { yylval.str = strdup(yytext);
		printf("abs: %s\n", yylval.str); return PATH; }

" " {;} /*Do nothing*/

"\n" { return *yytext; }

%%

#ifndef yywrap
yywrap() { return 1; }
#endif

