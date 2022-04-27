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
VARNAME {LETTER}({LETTER}|{DIGIT})*
%%

%{
// control structures
%}
"if"      TOKEN( IF);
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

%{
// types
%}
"int"    return TYPE_INT;
"bool" return TYPE_BOOL;
"char"   return TYPE_CHAR;
"const"  return TYPE_CONST;

%{
// logical operators
%}


"&&"		return LOGIC_AND;
"||"		return LOGIC_OR;
"=="		return LOGIC_EQ;
"!="		return LOGIC_NEQ;
">"		return LOGIC_GT;
">="		return LOGIC_GEQ;
"<="		return LOGIC_LEQ;
"<"		return LOGIC_LT;


%{
// arithematic operators
%}
"+"  { return PLUS;} 
"-" { return MINUS;}
"*" {return MULT;}
"/" {return DIV;}


%{
// const values
%}

"false" return CONST_FALSE;
"true" return CONST_TRUE;


%{
// variables
%}

 {VARNAME}   {
	return VAR;
}
[0-9]+ 	{
		// printf("expression [0-9]+\n");
			yylval = atoi(yytext);
			return CONST_INT;
		}

[()=\n{}] return *yytext;
[ \t]  ; /* skip whitespace */
";" {return ENDL;}
.   {
		printf("unknown %c", *yytext);
		perror("Unknown character ");
	} 
%%
int yywrap(void){
	return 1;
}