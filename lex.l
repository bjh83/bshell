%{
#include<string.h>
#include"gram.tab.h"
YYSTYPE yylval;
%}

%%
[a-zA-Z_]+ { yylval.str = strdup(yytext); return WORD}

" " {;} /*Do nothing*/

"\n" { return *yytext; }

%%

#ifndef yywrap
yywrap { return 1;}
#endif

