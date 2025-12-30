%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(char *s);
%}

%token NUMBER PLUS MINUS

%%
expression:
      expression PLUS expression   { $$ = $1 + $3; printf("Result = %d\n", $$); }
    | expression MINUS expression  { $$ = $1 - $3; printf("Result = %d\n", $$); }
    | NUMBER                       { $$ = $1; }
    ;
%%
void yyerror(char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter arithmetic expression:\n");
    yyparse();
    return 0;
}
