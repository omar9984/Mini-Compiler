%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
%}

%token EQUAL PLUS MINUS MULT DIV  VAR
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
	program statement '\n' {printf("matched okay\n");}
	| 
	;
statement: 
	expr	{  }
	| VAR '=' expr {}
	;
expr:
	CONST_INT	{ }
	| typing VAR { printf("this is declaration"); }
	| VAR EQUAL const_val {}
	| expr PLUS expr {  }
	| expr MINUS expr {}
	| expr MULT expr { }
	| expr DIV expr {}
	| '(' expr ')' {  }
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