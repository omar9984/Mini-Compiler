%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
	#define debug 0
	int i = 0;
	#include <stdlib.h>
	extern "C" FILE* yyin;

%} 

/* %union {
    int		IValue;
	double 	DValue;
    char* 	SValue;
} */

%token EQUAL
%token  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ

%left  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ


%token  PLUS MINUS MULT DIV VAR ENDL
%left PLUS MINUS MULT DIV
%right EQUAL
%token IF ELIF ELSE FOR WHILE REPEAT UNTIL SWITCH CASE BREAK DEFAULT      // Keywords

// types 
%token TYPE_INT TYPE_CHAR TYPE_CONST TYPE_BOOL TYPE_DOUBLE TYPE_STRING

// const values
%token INT_VALUE DOUBLE_VALUE FALSE_VALUE TRUE_VALUE CHAR_VALUE STRING_VALUE
/* %token <IValue> INT_VALUE 
%token <DValue> DOUBLE_VALUE
%token <IValue> FALSE_VALUE
%token <IValue> TRUE_VALUE
%token <IValue> CHAR_VALUE
%token <SValue> STRING_VALUE */

%%
program:
	program block_code {printf("matched okay\n");}
	|
	;
block_code:
	statement;
// this is the main building block of our program
statement:
	 expr ENDL
	| typing VAR ENDL { if(debug){printf("%d typing VAR \n", i++);}  }
	| Constant_type typing VAR EQUAL expr  ENDL {if(debug){printf("%d const typing VAR '=' const_val \n", i++);} }
	| typing VAR EQUAL expr  ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);} }
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);} }
	| IF  '('expr')' if_block    {if(debug){printf("%d if (expr) do expr  \n", i++);} }
	| IF  '('expr')' if_block else_block  {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} }
	| IF  '('expr')' if_block elif_block else_block   {if (debug){printf("%d IF ELIF ELSE expr  \n", i++);} }
	| IF  '('expr')' if_block elif_block  {if(debug){printf("%dIF ELIF  expr  \n", i++);} }
	| WHILE '('expr')' if_block  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| REPEAT if_block UNTIL  '('expr')'  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| FOR '(' for_inital ENDL for_condition  ENDL for_inc ')' if_block  { if(debug){printf("%d for loop  expr  \n", i++);} }
	| SWITCH '('expr')' '{' switch_block '}'   {if(debug){printf("%dswitch  expr  \n", i++);} }
	| '{' block_statements '}' { if(debug){printf("%d {  } \n", i++);} }
	| '{''}'
	;

// for part

for_inital:
	typing VAR EQUAL expr
	|VAR EQUAL expr
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

// the "IF-ELIF-ELSE" part
else_block:
ELSE if_block ;

// if block can also be used for FOR , WHILE , REPEAT UNTIL
if_block:
'{' block_statements '}'
	|	'{' '}';

elif_block:
ELIF   '('expr')' if_block;
block_statements:
	statement {}
	| block_statements statement {}
	;

// expr is anything that can appear on the right hand side of expression
expr:
	const_val	{if(debug){printf("%d const_val \n", i++);} }	
	| VAR	{if(debug){printf("%d VAR \n", i++);} }	
	| expr PLUS expr { if(debug){printf("%d expr + expr  \n", i++);} }
	| expr MINUS expr {if(debug){printf("%d expr - expr \n", i++);}}
	| expr MULT expr { if(debug){printf("%d expr * expr \n", i++);}}
	| expr DIV expr {if(debug){printf("%d  expr / expr  \n", i++);}}
	| logic_expr;

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
	FALSE_VALUE
	| TRUE_VALUE
	| DOUBLE_VALUE
	| INT_VALUE
	| CHAR_VALUE
	| STRING_VALUE
	;

typing:
	TYPE_INT 		{if(debug){printf("Type INT recieved\n");}}
	| TYPE_DOUBLE 	{if(debug){printf("Type Double recieved\n");}}
	| TYPE_BOOL 	{if(debug){printf("Type BOOL recieved\n");}}
	| TYPE_CHAR 	{if(debug){printf("Type CHAR recieved\n");}}
	| TYPE_STRING 	{if(debug){printf("Type STRING recieved\n");}}
	;

Constant_type:
	TYPE_CONST		{if(debug){printf("Type CONST recieved\n");}}
	;

%%


void yyerror(char*s){
	fprintf(stderr, "%s\n", s);
	//fprintf(stderr, "syntax error at line %d\n", i);
}


// void parse(FILE* fileInput)
//     {
//         yyin= fileInput;
//         while(feof(yyin)==0)
//         {
//         yyparse();
//         }
//     }


int main(int argc,char* argv[])
{
	/* FILE* fileInput;
    char inputBuffer[36];
    char lineData[36];
    if((fileInput=fopen(argv[1],"r"))==NULL)
        {
        printf("Error reading files, the program terminates immediately\n");
        exit(0);
        }
    parse(fileInput); */
	yyparse();
	printf("end of parser\n");
	return 0;
}