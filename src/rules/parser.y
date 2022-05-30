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
	bool is_intialized(char*);
	bool is_constant(char*);
	void insert_in_sym_tab(char*,char*,bool,bool,char*);
	void set_intialized_state_for_var(char*);
	void set_used_state_for_var(char*);
	bool check_type_match(char*,char*,int);
	int check_val_type(char*);
	int convert_name_type(char*);
	char* reverse_type_value(int);
	//void intialize_variable_expression();
	void initialize_variable(char*,char*);
	void print_symbol_table();
	void insert_quadruple(char* op, char* src1, char* src2, char* dst);
	void print_quadruples();
	char* ALU(char,char*,char*);



	int sym[26];
	#define debug 1
	int i = 0;
	int label = 1;
	int t = 1;
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
		char name[50];
		int type;
		bool intialized;
		bool constant;
		bool used;
	};

	struct Quadruple {
		int line_num;
		char dst[50], src1[50], src2[50], op[50];
		char description[100];
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

%type <token> typing Constant_type expr logic_expr const_val
//%type <token> if_block else_block  block_statements block_code statement //elif_block clauses //COND
%token <token> EQUAL
%token <token> LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ

%left  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ


%token <token> PLUS MINUS MULT DIV VAR ENDL
%left PLUS MINUS MULT DIV
%right EQUAL
%token <token> IF ELIF ELSE FOR WHILE REPEAT UNTIL SWITCH CASE BREAK DEFAULT //THEN     // Keywords

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
	| Constant_type typing VAR EQUAL expr  ENDL {if(debug){printf("%d const typing VAR '=' const_val \n", i++);} insert_quadruple("=","t#","NULL",$3); insert_in_sym_tab($2,$3,true,true,$5); print_symbol_table();}
	| typing VAR EQUAL expr ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);} insert_quadruple("=","t#","NULL",$2); insert_in_sym_tab($1,$2,false,true,$4); print_symbol_table();}
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);}insert_quadruple("=","t#","NULL",$1); initialize_variable($1,$3);print_symbol_table(); }
	| IF  '('expr')' if_block    {if(debug){printf("%d if (expr) do expr  \n", i++);} }
	| IF  '('expr')' if_block else_block  {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} }
	//| IF  '('expr')' if_block elif_block else_block   {if (debug){printf("%d IF ELIF ELSE expr  \n", i++);} }
	//| IF  '('expr')' if_block elif_block  {if(debug){printf("%dIF ELIF  expr  \n", i++);} }
	| WHILE '('expr')' if_block  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| REPEAT if_block UNTIL  '('expr')'  {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
	| FOR '(' for_inital ENDL for_condition  ENDL for_inc ')' if_block  { if(debug){printf("%d for loop  expr  \n", i++);} }
	| SWITCH '('expr')' '{' switch_block '}'   {if(debug){printf("%dswitch  expr  \n", i++);} }
	| '{' block_statements '}' { if(debug){printf("%d {  } \n", i++);} }
	//| '{''}'
	;

// for part

for_inital:
	VAR EQUAL expr {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);}/*insert_quadruple("=","t#","NULL",$1);*/ initialize_variable($1,$3);print_symbol_table(); }
	//typing VAR EQUAL expr
	//|VAR EQUAL expr {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);} initialize_variable($1,$3);print_symbol_table(); }
	|
	;
for_condition:
	logic_expr
	|
	;
for_inc:
	VAR EQUAL expr {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);}/*insert_quadruple("=","t#","NULL",$1);*/ initialize_variable($1,$3);print_symbol_table(); }
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
	'{' block_statements '}' {printf("--------------------popoopopopopoopopopoopopoppoopo--------------------\n");}
	|	'{' '}'  {printf("--------------------okookkookoookkokookokokokoookokokko--------------------\n");}
	;
	//block_statements {printf("--------------------popoopopopopoopopopoopopoppoopo--------------------\n");}
	//|

/* elif_block:
		ELIF   '('expr')' if_block
		; */

block_statements:
	statement {}
	| block_statements statement {}
	;

// expr is anything that can appear on the right hand side of expression
expr:
	const_val	{if(debug){printf("%d const_val \n", i++);}insert_quadruple("=",$1,"NULL","t#"); }	
	| VAR	{if(debug){printf("%d VAR \n", i++);}insert_quadruple("=",$1,"NULL","t#"); }	
	| expr PLUS expr {if(debug){printf("%d expr + expr  \n", i++);} if(check_type_match($1,$3,0)  || check_type_match($1,$3,1)) {$$ = ALU('+',$1,$3);insert_quadruple("+",$1,$3,"t#");}else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr MINUS expr {if(debug){printf("%d expr - expr \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('-',$1,$3);insert_quadruple("-",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr MULT expr { if(debug){printf("%d expr * expr \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('*',$1,$3);insert_quadruple("*",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr DIV expr {if(debug){printf("%d  expr / expr  \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('/',$1,$3);insert_quadruple("/",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| logic_expr;

logic_expr:
	expr LOGIC_EQ expr 		{if(check_type_match($1,$3,-1)){$$="true";insert_quadruple("==",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_NEQ expr 	{if(check_type_match($1,$3,-1)){$$="true";insert_quadruple("!=",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_OR expr 	{if(check_type_match($1,$3,2)){$$="true";insert_quadruple("||",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_AND expr	{if(check_type_match($1,$3,2)){$$="true";insert_quadruple("&&",$1,$3,"t#");} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_LT expr 	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";insert_quadruple("<",$1,$3,"t#");}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_LEQ expr	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";insert_quadruple("<=",$1,$3,"t#");}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_GT expr 	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";insert_quadruple(">",$1,$3,"t#");}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_failure_param(err);}}
	| expr LOGIC_GEQ expr	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";insert_quadruple(">=",$1,$3,"t#");}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_failure_param(err);}}
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

	//COND:		{if(debug){printf("Goooooooooooooooooooooooooood\n");}/*insert_quadruple("Jne","t#","true","label#");*/}
	//;


%%

struct symbol_table_element symbol_table[200];
int symbol_table_idx = 0;

struct Quadruple quadruples[200];
int quadruple_idx = 0;

// Symbol table functions

bool in_symbol_table(char* var_name) {//symbol_table_contains
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return true;
	}

	return false;
}

int get_type_from_sym_tab(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].type;
	}
}

bool is_intialized(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].intialized;
	}
	return false;
}

bool is_constant(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0) return symbol_table[i].constant;
	}
	return false;
}

void insert_in_sym_tab(char* var_type, char* var_name, bool is_const, bool is_initial, char* var_value){
	// check if already found
	if(in_symbol_table(var_name)) { 
		char err[100];
		sprintf(err,"Redeclaration of already declared variable %s\n", var_name);
		semantic_failure_param(err); return; 
	}
	// check for type
	int dtype = convert_name_type(var_type);
	if(dtype == -1){
		char err[100];
		sprintf(err,"Unknown type for variable %s\n", var_name);
		semantic_failure_param(err); return; 
	}
	// check if const and not initialized
	if(is_const && !is_initial){
		char err[100];
		sprintf(err,"type Const variable must be initialized immediately %s\n", var_name);
		semantic_failure_param(err); return; 
	}

	struct symbol_table_element new_element;
	new_element.type = dtype;
	new_element.intialized = is_initial;
	new_element.constant = is_const;
	new_element.used = false;
	strcpy(new_element.name, var_name);
	
	// insert a non-initialized element
	if(!is_initial){
		symbol_table[symbol_table_idx++] = new_element;
		return;
	}

	int val_type = check_val_type(var_value);
	if(val_type != 5){
		if(new_element.type != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_failure_param(err); return;
		}
	}
	// assign var to var
	else{
		if(!in_symbol_table(var_value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable: %s\n",var_name, var_value);
			semantic_failure_param(err); 
			return; 
		}
		
		int v_type_int = get_type_from_sym_tab(var_value);

		if(v_type_int != new_element.type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_failure_param(err); return; 
		}

		if(!is_intialized(var_value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not intialized variable: %s\n", var_name, var_value);
			semantic_failure_param(err); //return;/////////////////////////////// 
		}

		set_used_state_for_var(var_value);
	}
	// insert an initialized element
	new_element.intialized = true;
	symbol_table[symbol_table_idx++] = new_element;
}

void set_intialized_state_for_var(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0)
		{
			symbol_table[i].intialized = true;
			return;
		}
	}
}

void set_used_state_for_var(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		int eq = strcmp(var_name, symbol_table[i].name);

		if(eq == 0)
		{
			symbol_table[i].used = true;
			return;
		}
	}
}

bool check_type_match(char* x, char* y, int specified){
	int x_type = check_val_type(x),y_type = check_val_type(y);
	if(x_type == 5){
		x_type = get_type_from_sym_tab(x);
	}
	if(y_type == 5){
		y_type = get_type_from_sym_tab(y);
	}
	if (specified == -1) specified = x_type;
	return (x_type == specified && specified == y_type);
}

int check_val_type(char* val){
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
	if(!strcmp(val,"false") || !strcmp(val,"true") || !strcmp(val,"truepassed") ){
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

int convert_name_type(char * var_type){
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

void initialize_variable(char * var_name, char * value){
	
	if(!in_symbol_table(var_name)) { 
		char err[100];
		sprintf(err,"%s not declared\n", var_name);
		semantic_failure_param(err); 
		return; 
	}

	if(is_constant(var_name)){
		char err[100];
		sprintf(err,"Constant var can't be re-initialized %s\n", var_name);
		semantic_failure_param(err); return; 
	}
	
	if(is_intialized(var_name)){
		set_used_state_for_var(var_name);
	}

	int var_type_int = get_type_from_sym_tab(var_name);
	int val_type = check_val_type(value);
	if(val_type != 5){
		if(var_type_int != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch) %s and %s are of different types\n", var_name, value);
			semantic_failure_param(err); return;
		}
		set_intialized_state_for_var(var_name);
	}
	// assign var to var
	else{
		if(!in_symbol_table(value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable %s\n",var_name ,value);
			semantic_failure_param(err); 
			return; 
		}

		int v_type_int = get_type_from_sym_tab(value);

		if(v_type_int != var_type_int){ 
			char err[100];
			sprintf(err,"%s and %s are of different types\n", var_name, value);
			semantic_failure_param(err); return; 
		}
		
		if(!is_intialized(value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not intialized variable %s\n",var_name ,value);
			semantic_failure_param(err); // return; //////////////////////
		}
		set_intialized_state_for_var(var_name);
	}
}


void print_symbol_table() {
	printf("symbooooooool\n");
	for(int s = 0; s < symbol_table_idx; s++) {
		printf("symbooooooool tabel iterator %d\n",s);
		printf("[%d] type: %s\t name: %s\t \n", s+1, arr_type[symbol_table[s].type], symbol_table[s].name);
	}
}

char* reverse_type_value(int ty){
	switch(ty){
		case 0:
			return "1passed";
		case 1:
			return "1.1passed";
		case 2:
			return "truepassed";
		case 3:
			return "'c'";
		case 4:
			return "\"str\"";
	}
}

char* ALU(char op,char* x,char* y){
	int y_type = check_val_type(y);
	if(y_type == 5){
		y_type = get_type_from_sym_tab(y);
	}else if( op == '/' && atoi(y) == 0){
		char err[100];
		sprintf(err,"Warning: you might be dividing by zero\n");
		semantic_failure_param(err);
	}
	return reverse_type_value(y_type);
	printf("---------------- heeeeeeeeeeeeeeeey --------------------------\n");
	/* int res_i;
	char* res;
	switch(op)
	{
		case '+':
			res_i = atoi(x) + atoi(y);
			sprintf(res, "%d", res_i);
			printf("---------------- res = %s \n",res);
			return res;
		
		case '-':
			res_i = atoi(x) - atoi(y);
			sprintf(res, "%d", res_i);
			return res;
		case '*':
			res_i = atoi(x) * atoi(y);
			sprintf(res, "%d", res_i);
			return res;
		case '/':
			// TODO: handle divide by zero
			res_i = atoi(x) / atoi(y);
			sprintf(res, "%d", res_i);
			return res;
		default:
			return "-1";
	} */
}

void insert_quadruple(char* op, char* src1_passed, char* src2_passed, char* dst_passed)
{
	printf("Quadruples: operator: %s, src1: %s, src2: %s, dst: %s\n",op,src1_passed,src2_passed,dst_passed);
	char str_num[5];
	char src1[10], src2[10], dst[10];
	strcpy(src1, src1_passed);
	strcpy(src2, src2_passed);
	strcpy(dst, dst_passed);
	if (strcmp(src1_passed,"t#") == 0 || strstr(src1_passed, "passed") != NULL){
		strcpy(src1, "t");
		sprintf(str_num, "%d", t-1);
		strcat(src1,str_num);
	}
	if (strcmp(src2_passed,"NULL") == 0){
		strcpy(src2, "");
		//printf("Src2 Quadruples\n");
	}
	if (strcmp(dst_passed,"t#") == 0){
		strcpy(dst, "t");
		sprintf(str_num, "%d", t++);
		strcat(dst,str_num);
		//printf("dst Quadruples\n");
	}
	struct Quadruple new_element;

	/* new_element.line_num = lineno; */
	strcpy(new_element.dst, dst);
	strcpy(new_element.src1, src1);
	strcpy(new_element.src2, src2);
	strcpy(new_element.op, op);

	quadruples[quadruple_idx++] = new_element;
	printf("finissssssssssssshhhhhh Quadruples\n");
	print_quadruples();
}

void print_quadruples()
{
	printf("-------------------------printttttttttt Quadruples-------------------------\n");
	for(int q = 0; q < quadruple_idx; q++){
		//printf("\nline: %d\n", quadruples[q].line_num);
		printf("arg1: %s\t", quadruples[q].src1);
		printf("operation: %s\t", quadruples[q].op);
		printf("arg2: %s\t", quadruples[q].src2);
		printf("result: %s\n", quadruples[q].dst);
	}
	printf("-------------------------End printttttttttt Quadruples-------------------------\n");
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
	int flag;
	flag = yyparse();
	printf("----------------------------------flag--%d-------------------------------\n",flag);
	printf("----------------------------------Symbol Table--%d-------------------------------\n",symbol_table_idx);
	print_symbol_table();
	printf("----------------------------------Quadruples--%d-------------------------------\n",quadruple_idx);
	print_quadruples();
	printf("----------------------------------Quadruples--%d-------------------------------\n",quadruple_idx);
	printf("end of parser\n");
	return 0;
}