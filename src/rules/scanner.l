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
int lineno= 0;
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
"int"    	return TYPE_INT;
"double"	return TYPE_DOUBLE;
"bool" 		return TYPE_BOOL;
"char"   	return TYPE_CHAR;
"string"   	return TYPE_STRING;
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

"false" 	return FALSE_VALUE;
"true"  	return TRUE_VALUE;


%{
// variables
%}

{VARNAME}	return VAR;
{DIGIT}+ 	{
				//printf("expression [0-9]+\n");
				yylval = atoi(yytext);
				return INT_VALUE;
			}
{DOUBLE} 	return DOUBLE_VALUE;
{CHAR} 		return CHAR_VALUE;
{STRING} 	return STRING_VALUE;
[(){}:,] 	return *yytext;
[ \t]  		; /* skip whitespace */
";" 		{return ENDL;}
'\n' 		{lineno++;}
.   {
		printf("unknown %c", *yytext);
		perror("Unknown character ");
	} 
%%
int yywrap(void){
	return 1;
}