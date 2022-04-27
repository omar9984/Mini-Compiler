%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
	#define debug 1
	int i;
%}
%token EQUAL PLUS MINUS MULT DIV  VAR ENDL
%left PLUS MINUS
%left MULT DIV
%right POW
%token IF ELIF ELSE  FOR  WHILE REPEAT UNTIL  SWITCH CASE BREAK DEFAULT      // Keywords
// types 
%token TYPE_INT TYPE_CHAR TYPE_CONST TYPE_BOOL

// const values
%token CONST_INT CONST_FALSE CONST_TRUE
%%
program:
	program block_code {printf("matched okay\n");}
	|
	;
block_code:
	statement;
// this is the main building block of our program
statement:
	'\n'
	| expr ENDL {}
	| VAR '=' expr  ENDL { if(debug){printf("%d typing VAR=expr \n", i++);} }
	| typing VAR   ENDL { if(debug){printf("%d typing VAR \n", i++);}  }
	| typing VAR '=' const_val  ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);} }
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);} }
	| '{' program '}' {if(debug){printf("%d {  } \n", i++);} }
	;
// expr is anything that can appear on the right hand side of expression
expr:
	const_val	{if(debug){printf("%d const_val \n", i++);} }	
	| VAR	{if(debug){printf("%d VAR \n", i++);} }	
	| expr PLUS expr { if(debug){printf("%d expr + expr  \n", i++);} }
	| expr MINUS expr {if(debug){printf("%d expr - expr \n", i++);}}
	| expr MULT expr { if(debug){printf("%d expr * expr \n", i++);}}
	| expr DIV expr {if(debug){printf("%d  expr / expr  \n", i++);}}
	| '(' expr ')' {if(debug){printf("%d (expr) \n", i++);}  }
	;
const_val:
	CONST_FALSE
	| CONST_TRUE
	| CONST_INT;
typing:
	TYPE_INT {}
	| TYPE_BOOL { }
	| TYPE_CHAR { }
	;
%%


void yyerror(char*s){
	fprintf(stderr, "%s\n", s);
}
int main(void){
	yyparse();
	printf("end of parser\n");
	return 0;
}