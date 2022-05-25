%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror(char*);
	void semantic_failure();
	void semantic_failure_param(char *);
	bool in_symbol_table(char*);
	int get_type_from_sym_tab(char*);
	char* get_value_from_sym_tab(char*);
	bool is_intialized(char*);
	bool is_constant(char*);
	void insert_in_sym_tab(char*,char*,bool,bool,char*);
	void set_intialized_state_for_var(char*,char*);
	bool check_type_match(int,int);
	int check_val_type(char*);
	int convert_name_type(char*);
	//void intialize_variable_expression();
	void initialize_variable(char*,char*);
	void print_symbol_table();
	int sym[26];
	#define debug 0
	int i = 0;
	extern int lineno;
	extern "C" FILE* yyin;
	// enum data_type{
	// 	int,		//0
	// 	double,		//1
	// 	bool,		//2		
	// 	char,		//3
	// 	string		//4
	// 	};
	const char* arr_type[5] = {"int","double","bool","char","string"};
	struct symbol_table_element {
		char name[50], value[50];
		int type;
		bool intialized;
		bool constant;
	};
%} 

/* %union {
    int		IValue;
	double 	DValue;
    char* 	SValue;
} */
%union{
	char* token;
}

%type <token> typing Constant_type expr logic_expr
%token <token> EQUAL
%token <token> LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ

%left  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ


%token <token> PLUS MINUS MULT DIV VAR ENDL
%left PLUS MINUS MULT DIV
%right EQUAL
%token <token> IF ELIF ELSE FOR WHILE REPEAT UNTIL SWITCH CASE BREAK DEFAULT      // Keywords

// types 
%token <token> TYPE_INT TYPE_CHAR TYPE_CONST TYPE_BOOL TYPE_DOUBLE TYPE_STRING

// const values
%token <token> INT_VALUE DOUBLE_VALUE FALSE_VALUE TRUE_VALUE CHAR_VALUE STRING_VALUE
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
	| typing VAR ENDL { if(debug){printf("%d typing VAR \n", i++);}insert_in_sym_tab($1,$2,false,false,"");print_symbol_table();  }
	| Constant_type typing VAR EQUAL expr  ENDL {if(debug){printf("%d const typing VAR '=' const_val \n", i++);} insert_in_sym_tab($2,$3,true,true,$5); print_symbol_table();}
	| typing VAR EQUAL expr ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);} insert_in_sym_tab($1,$2,false,true,$4); print_symbol_table();}
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);} initialize_variable($1,$3);print_symbol_table(); }
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

struct symbol_table_element symbol_table[200];
int symbol_table_idx = 0;

bool in_symbol_table(char* var_name) {//symbol_table_contains
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return true;
	}

	return false;
}

int get_type_from_sym_tab(char* var_name)
{
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].type;
	}
}

char* get_value_from_sym_tab(char* var_name)
{
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].value;
	}
}


bool is_intialized(char* var_name)
{
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].intialized;
	}
	return false;
}

bool is_constant(char* var_name)
{
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].constant;
	}
	return false;
}

void insert_in_sym_tab(char* var_type, char* var_name, bool is_const, bool is_initial, char* var_value)
{
	if(in_symbol_table(var_name)) { 
		char err[100];
		sprintf(err,"Redeclaration of already declared variable %s", var_name);
		semantic_failure_param(err); return; 
	}
	int dtype = convert_name_type(var_type);
	if(dtype == -1){
		char err[100];
		sprintf(err,"Unknown type for variable %s", var_name);
		semantic_failure_param(err); return; 
	}

	struct symbol_table_element new_element;
	new_element.type = dtype;
	strcpy(new_element.name, var_name);
	
	new_element.constant = is_const;
	
	int val_type = check_val_type(var_value);
	if(val_type != 5){
		if(new_element.type != val_type){ 
			char err[100];
			sprintf(err,"%s and %s are of different types", var_name, var_value);
			semantic_failure_param(err); return;
		}
		strcpy(new_element.value, var_value);
	}
	// assign var to var
	else{
		if(!in_symbol_table(var_value)) { 
			char err[100];
			sprintf(err,"%s not declared", var_value);
			semantic_failure_param(err); 
			return; 
		}
		if(!is_intialized(var_value)) { 
			char err[100];
			sprintf(err,"%s not intialized", var_value);
			semantic_failure_param(err); return; 
		}

		int v_type_int = get_type_from_sym_tab(var_value);

		if(v_type_int != new_element.type){ 
			char err[100];
			sprintf(err,"%s and %s are of different types", var_name, var_value);
			semantic_failure_param(err); return; 
		}
		strcpy(new_element.value, get_value_from_sym_tab(var_value));
	}

	new_element.intialized = true;
	symbol_table[symbol_table_idx++] = new_element;
}

void set_intialized_state_for_var(char* var_name, char* value)
{

	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0)
		{
			symbol_table[i].intialized = true;
			strcpy(symbol_table[i].value, value);
		}
	}
}

bool check_type_match(int required_type, int var_type)
{
	return (required_type == var_type);
}

int check_val_type(char* val)
{
	// int or double
	if(val[0] >= '0' && val[0] <= '9'){
		if(strchr(val,'.') == NULL){ //int
			return 0;
		}
		else{ //double
			return 1;
		}
	}
	//bool
	if(!strcmp(val,"false") || !strcmp(val,"true") ){
		return 2;
	}
	//char
	if(val[0] == '\''){
		return 3;
	}
	//string
	if(val[0] == '"'){
		return 4;
	}
	return 5;
}

int convert_name_type(char * var_type)
{
	if(!strcmp(var_type, "int")){
		return 0;
	}
	if(!strcmp(var_type, "double")){
		return 1;
	}
	if(!strcmp(var_type, "bool")){
		return 2;
	}
	if(!strcmp(var_type, "char")){
		return 3;
	}
	if(!strcmp(var_type, "string")){
		return 4;
	}
	return -1;
}

void initialize_variable(char * var_name, char * value)
{
	if(!in_symbol_table(var_name)) { 
		char err[100];
		sprintf(err,"%s not declared", var_name);
		semantic_failure_param(err); 
		return; 
	}

	if(is_constant(var_name)){
		char err[100];
		sprintf(err,"Constant var can't be reinitialized %s", var_name);
		semantic_failure_param(err); return; 
	}
	
	int var_type_int = get_type_from_sym_tab(var_name);
	//if( var_type == NULL) { semantic_failure(); return; }
	//int var_type_int = convert_name_type(var_type);
	int val_type = check_val_type(value);
	if(val_type != 5){
		if(var_type_int != val_type){ 
			char err[100];
			sprintf(err,"%s and %s are of different types", var_name, value);
			semantic_failure_param(err); return;
		}
		set_intialized_state_for_var(var_name, value);
	}
	// assign var to var
	else{
		if(!in_symbol_table(value)) { 
			char err[100];
			sprintf(err,"%s not declared", value);
			semantic_failure_param(err); 
			return; 
		}
		if(!is_intialized(value)) { 
			char err[100];
			sprintf(err,"%s not intialized", value);
			semantic_failure_param(err); return; 
		}

		int v_type_int = get_type_from_sym_tab(value);
		//if( v_type == NULL) { semantic_failure(); return; }
		//int v_type_int = convert_name_type(v_type);

		if(v_type_int != var_type_int){ 
			char err[100];
			sprintf(err,"%s and %s are of different types", var_name, value);
			semantic_failure_param(err); return; 
		}
		set_intialized_state_for_var(var_name, get_value_from_sym_tab(value));
	}
}


void print_symbol_table() {
	for(int i = 0; i < symbol_table_idx; i++) {
		printf("[%d] type: %s\t name: %s\t value: %s\n", i+1, arr_type[symbol_table[i].type], symbol_table[i].name, symbol_table[i].value);
	}
}

void semantic_failure()
{
	fprintf(stderr, "Semantic error at line %d\n", lineno);
}

void semantic_failure_param(char * err)
{
	fprintf(stderr, "Semantic error at line %d | %s\n", lineno, err);
}

void yyerror(char*s){
	//fprintf(stderr, "%s\n", s);
	fprintf(stderr, "syntax error at line %d\n", lineno);
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