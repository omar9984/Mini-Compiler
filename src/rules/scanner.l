%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
%}

%{
#ifdef PRINT
#define TOKEN(t) printf("Token " #t "\n");
#else
#define TOKEN(t) return(t);
#endif
int lineno= 0;
void save_token();
%}
DIGIT 	[0-9]
LETTER 	[a-zA-Z_$]
VARNAME {LETTER}({LETTER}|{DIGIT})*
DOUBLE	"0"|{DIGIT}+"."{DIGIT}+
ASCII	[ -~]
CHAR	(\'{ASCII}\')|(\'\\[nftrbv]\')
STRING	\"{ASCII}*\"
%%

%{
// control structures
%}
"if"      	return IF;
"elif"      return ELIF;
"else" 		return ELSE;
"while"	  	return WHILE;
"for"     	return FOR;
"switch"  	return SWITCH;
"case"    	return CASE;
"default" 	return DEFAULT;
"break"   	return BREAK;
"repeat"  	return REPEAT;
"until"   	return UNTIL;

%{
// types
%}
"int"    	{save_token(); return TYPE_INT;};
"double"	{save_token(); return TYPE_DOUBLE;}
"bool" 		{save_token(); return TYPE_BOOL;}
"char"   	{save_token(); return TYPE_CHAR;}
"string"   	{save_token(); return TYPE_STRING;}
"const"  	return TYPE_CONST;

%{
// logical operators
%}


"&&"		return LOGIC_AND;
"||"		return LOGIC_OR;
"=="		return LOGIC_EQ;
"!="		return LOGIC_NEQ;
">"			return LOGIC_GT;
">="		return LOGIC_GEQ;
"<="		return LOGIC_LEQ;
"<"			return LOGIC_LT;


%{
// arithematic operators
%}

"-" 		return MINUS;
"+"  		return PLUS; 
"*" 		return MULT;
"/" 		return DIV;
"=" 		return EQUAL;


%{
// const values
%}

"false" 	{save_token(); return FALSE_VALUE;}
"true"  	{save_token(); return TRUE_VALUE;}


%{
// variables
%}

{VARNAME}	{
				save_token();
				return VAR;
			}
{DIGIT}+ 	{
				//printf("expression [0-9]+\n");
				//yylval = atoi(yytext);
				save_token();
				return INT_VALUE;
			}
{DOUBLE} 	{save_token(); return DOUBLE_VALUE;}
{CHAR} 		{save_token(); return CHAR_VALUE;}
{STRING} 	{save_token(); return STRING_VALUE;}
[(){}:,] 	{save_token(); return *yytext;}
[ \t]  		; /* skip whitespace */
";" 		{save_token(); return ENDL;}
'\n' 		{lineno++;}
.   {
		printf("unknown %c", *yytext);
		perror("Unknown character ");
	} 
%%
int yywrap(void){
	return 1;
}

void save_token()
{
	yylval.token = strdup(yytext);
}
