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
	| FOR '(' for_inital ENDL for_condition  ENDL for_inc ')' if_block  { if(debug){printf("%d for loop  expr  \n", i++);} }
	| SWITCH '('expr')' '{' switch_block '}'   {if(debug){printf("%dswitch  expr  \n", i++);} }
	| '{' block_statements '}' { if(debug){printf("%d {  } \n", i++);} }
	| '{''}'
	;

// for part

for_inital:
	VAR EQUAL expr
	|
	;
for_condition:
	logic_expr
	|
	;
for_inc:
	VAR EQUAL expr
	|
	;
// switch case part
switch_block:
		case_block switch_block { if(debug){printf("%d {  } \n", i++);} }
	   | DEFAULT ':' case_statement	 { if(debug){printf("%d {  } \n", i++);} }
	   | DEFAULT ':' 	 { if(debug){printf("%d {  } \n", i++);} }
	   |
	   ;

case_statement:
	statement
	| statement BREAK ENDL;
	| BREAK ENDL
	;
case_block:
	CASE const_val ':' case_statement {  if(debug){printf("%dcase_block statement break;\n", i++);} }
	;

// if block can also be used for FOR , WHILE , REPEAT UNTIL
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
	|logic_expr;
logic_expr:
	expr LOGIC_EQ expr {}
	| expr LOGIC_NEQ expr {}
	| expr LOGIC_OR expr {}
	| expr LOGIC_AND expr {}
	| expr LOGIC_LT expr {}
	| expr LOGIC_LEQ expr {}
	| expr LOGIC_GT expr {}
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