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
"load-bins" { return LOAD_BIN; }
{NAME}+{PATH}? { yylval.str = strdup(yytext); return PATH; }
{PATH} { yylval.str = strdup(yytext); return PATH; }

" " {;} /*Do nothing*/

"\n" { return *yytext; }

%%

#ifndef yywrap
yywrap() { return 1; }
#endif

