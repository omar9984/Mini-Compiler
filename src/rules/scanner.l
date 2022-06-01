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
int lineno= 1;
void claim_token();
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
%}
"if"      	{claim_token(); return IF;}
"elif"      {claim_token(); return ELIF;}
"else" 		{claim_token(); return ELSE;}
"while"	  	{claim_token(); return WHILE;}
"for"     	{claim_token(); return FOR;}
"switch"  	{claim_token(); return SWITCH;}
"case"    	{claim_token(); return CASE;}
"default" 	{claim_token(); return DEFAULT;}
"repeat"  	{claim_token(); return REPEAT;}
"until"   	{claim_token(); return UNTIL;}
"end"   	{claim_token(); return END;}
%{
// types
%}
"int"    	{claim_token(); return TYPE_INT;};
"double"	{claim_token(); return TYPE_DOUBLE;}
"bool" 		{claim_token(); return TYPE_BOOL;}
"char"   	{claim_token(); return TYPE_CHAR;}
"string"   	{claim_token(); return TYPE_STRING;}
"const"  	return TYPE_CONST;

%{
// logical operators
%}


"&&"		{claim_token();return LOGIC_AND;}
"||"		{claim_token();return LOGIC_OR;}
"=="		{claim_token();return LOGIC_EQ;}
"!="		{claim_token();return LOGIC_NEQ;}
">"			{claim_token();return LOGIC_GT;}
">="		{claim_token();return LOGIC_GEQ;}
"<="		{claim_token();return LOGIC_LEQ;}
"<"			{claim_token();return LOGIC_LT;}


%{
// arithematic operators
%}

"-" 		{claim_token();return MINUS;}
"+"  		{claim_token();return PLUS; }
"*" 		{claim_token();return MULT;}
"/" 		{claim_token();return DIV;}
"=" 		{claim_token();return EQUAL;}


%{
// const values
%}

"false" 	{claim_token(); return FALSE_VALUE;}
"true"  	{claim_token(); return TRUE_VALUE;}


%{
// variables
%}

{VARNAME}	{
				claim_token();
				return VAR;
			}
{DIGIT}+ 	{
				//printf("expression [0-9]+\n");
				//yylval = atoi(yytext);
				claim_token();
				return INT_VALUE;
			}
{DOUBLE} 	{claim_token(); return DOUBLE_VALUE;}
{CHAR} 		{claim_token(); return CHAR_VALUE;}
{STRING} 	{claim_token(); return STRING_VALUE;}
[(){},] 	{claim_token(); return *yytext;}
[ \t]  		; /* skip whitespace */
":"			{claim_token(); return COLON;}
";" 		{claim_token(); return ENDL;}
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

void claim_token()
{
	yylval.token = strdup(yytext);
}
