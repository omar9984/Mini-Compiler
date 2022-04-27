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
DIGIT [0-9]
LETTER [a-zA-Z_]
VAR {LETTER}({LETTER} | {DIGIT})* 
%%



"if"      return IF;
"elif"      return ELIF;
"else"    return ELSE;
"while"	  return WHILE;
"for"     return FOR;
"switch"  return SWITCH;
"case"    return CASE;
"default" return DEFAULT;
"break"   return BREAK;
"repeat"  return REPEAT;
"until"   return UNTIL;



[a-z] {
	yylval = *yytext - 'a';
	return VAR;
}
[0-9]+ 	{
			yylval = atoi(yytext);
			return INT;
		}
"+" TOKEN(PLUS)
"-" {return MINUS;}
"*" {return MULT;}
"/" {return DIV;}
"^" {return POW;}
[-+()=\n] return *yytext;
[ \t]  ; /* skip whitespace */

%%
int yywrap(void){
	return 1;
}