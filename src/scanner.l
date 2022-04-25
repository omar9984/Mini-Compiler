%{
#include<stdlib.h>
#include "parser.tab.h"
%}

%{
#ifdef PRINT
#define TOKEN(t) printf("Token " #t "\n");
#else
#define TOKEN(t) return(t);
#endif
%}

%%
[a-z] {
	yylval = *yytext - 'a';
	return Var;
}
[0-9]+ 	{
			yylval = atoi(yytext);
			return Integer;
		}
"+" TOKEN(Plus)
"-" {return Minus;}
"*" {return Mult;}
"/" {return Div;}
"^" {return Power;}
[-+()=\n] return *yytext;
[ \t]  ; /* skip whitespace */

%%
int yywrap(void){
	return 1;
}