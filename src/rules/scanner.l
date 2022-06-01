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
%x LINE
%%

%{
// control structures
// "break"   	{save_token(); return BREAK;}
%}
"if"      	{save_token(); return IF;}
"elif"      {save_token(); return ELIF;}
"else" 		{save_token(); return ELSE;}
"while"	  	{save_token(); return WHILE;}
"for"     	{save_token(); return FOR;}
"switch"  	{save_token(); return SWITCH;}
"case"    	{save_token(); return CASE;}
"default" 	{save_token(); return DEFAULT;}
"repeat"  	{save_token(); return REPEAT;}
"until"   	{save_token(); return UNTIL;}
"end"   	{save_token(); return END;}
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


"&&"		{save_token();return LOGIC_AND;}
"||"		{save_token();return LOGIC_OR;}
"=="		{save_token();return LOGIC_EQ;}
"!="		{save_token();return LOGIC_NEQ;}
">"			{save_token();return LOGIC_GT;}
">="		{save_token();return LOGIC_GEQ;}
"<="		{save_token();return LOGIC_LEQ;}
"<"			{save_token();return LOGIC_LT;}


%{
// arithematic operators
%}

"-" 		{save_token();return MINUS;}
"+"  		{save_token();return PLUS; }
"*" 		{save_token();return MULT;}
"/" 		{save_token();return DIV;}
"=" 		{save_token();return EQUAL;}


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
[(){},] 	{save_token(); return *yytext;}
[ \t]  		; /* skip whitespace */
":"			{save_token(); return COLON;}
";" 		{save_token(); return ENDL;}
"\n" 		{lineno += 1;}
<LINE>"\n"		{ lineno += 1; }
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
