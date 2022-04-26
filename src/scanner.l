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
LETTER [a-zA-Z_$]
VAR {LETTER}({LETTER} | {DIGIT})* 
CHAR (\'.\')

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





DIGIT+ 	{
		//	yylval = atoi(yytext);
			return INT;
		}
"+" TOKEN(PLUS)
"-" TOKEN(MINUS)
"*" TOKEN(MULT)
"/" TOKEN(DIV)
"=" TOKEN(EQUAL)
[-+()\n] return *yytext;
[ \t]  ; /* skip whitespace */
VAR {
	// yylval = *yytext - 'a';
	return VAR;
}

%%
int yywrap(void){
	return 1;
}