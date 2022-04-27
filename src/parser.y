%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
	#define debug 1
	int i;
%} 
%token EQUAL
%token  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ

%left  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ


%token  PLUS MINUS MULT DIV  VAR ENDL
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
	'\n' {}
	| expr ENDL {}
	| VAR '=' expr  ENDL { if(debug){printf("%d typing VAR=expr \n", i++);} }
	| typing VAR   ENDL { if(debug){printf("%d typing VAR \n", i++);}  }
	| typing VAR '=' const_val  ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);} }
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);} }
	| IF  '('expr')' if_block    {if(debug){printf("%d if (expr) do expr  \n", i++);} }
	| IF  '('expr')' if_block ELSE if_block   {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} }
	| IF  '('expr')' if_block ELIF   '('expr')' if_block ELSE if_block   {if (debug){printf("%d IF ELIF ELSE expr  \n", i++);} }
	| IF  '('expr')' if_block ELIF   '('expr')' if_block  {if(debug){printf("%dIF ELIF  expr  \n", i++);} }
	| WHILE '('expr')' if_block  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| REPEAT if_block UNTIL  '('expr')'  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| '{' block_statements '}' { if(debug){printf("%d {  } \n", i++);} }
	;
if_block:
	'{' block_statements '}' |
	'{' '}';


block_statements:
	statement {}
	|block_statements statement {}
	;
// expr is anything that can appear on the right hand side of expression
expr:
	const_val	{if(debug){printf("%d const_val \n", i++);} }	
	| VAR	{if(debug){printf("%d VAR \n", i++);} }	
	| expr PLUS expr { if(debug){printf("%d expr + expr  \n", i++);} }
	| expr MINUS expr {if(debug){printf("%d expr - expr \n", i++);}}
	| expr MULT expr { if(debug){printf("%d expr * expr \n", i++);}}
	| expr DIV expr {if(debug){printf("%d  expr / expr  \n", i++);}}
	| expr LOGIC_EQ expr {}
	| expr LOGIC_NEQ expr {}
	| expr LOGIC_OR expr {}
	| expr LOGIC_AND expr {}
	| expr LOGIC_LEQ expr {}
	| expr LOGIC_GEQ expr {}
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