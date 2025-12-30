%{
#include "y.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+]         { return PLUS; }
[-]         { return MINUS; }
[\n]        { return 0; }
[ \t]       { /* ignore whitespace */ }
.           { printf("Invalid character: %s\n", yytext); }
%%
