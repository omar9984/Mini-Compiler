%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#define debug 0
	int yylex(void);
	void yyerror(char*);
	void semantic_error();
	void semantic_error_with_msg(char *);
	bool symbol_table_contains(char*);
	int symbol_table_get_varType(char*);
	bool is_var_initialized(char*);
	bool is_var_constant(char*);
	void symbol_table_insert(char*,char*,bool,bool,char*);
	void set_var_initialized(char*);
	void set_var_used(char*);
	bool check_type_match(char*,char*,int);
	int check_val_type(char*);
	int convert_name_type(char*);
	char* reverse_type_value(int);
	void initialize_variable(char*,char*);
	void print_symbol_table();
	void quadruple_insert(char* op, char* src1, char* src2, char* dst,bool defer);
	void print_quadruples();
	char* ALU(char,char*,char*);
	void manage_colon();
	void add_label();
	void jump(bool,int);
	void apply_defer();
	void print_warning();


	int i = 0;
	// int scope = 1;
	int label = 1;
	int label_switch_case = 1;
	int t = 1, t_reg = 0;
	int flag_until = 0;
	int flag_case = 0;
	int flag_last_case = 0;
	bool semantic_error_found = false;
	extern int lineno;
	extern FILE *yyin;
	const char* arr_type[5] = {"int","double","bool","char","string"};
	struct symbol_table {
		char name[50];
		int type;
		bool initialized;
		bool constant;
		bool used;
		int line_num;
	};

	struct Quadruple {
		char dst[50], src1[50], src2[50], op[50];
		char description[100];
	};
%} 

%union{
	char* token;
}

%type <token> typing Constant_type expr logic_expr const_val colon
%type <token> if_clause while_clause repeat_clause until_clause for_clause switch_clause else_clause case_clause default_clause elif_clause
%token <token> EQUAL
%token <token> LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ

%left  LOGIC_OR LOGIC_AND LOGIC_EQ LOGIC_NEQ  LOGIC_LT LOGIC_LEQ LOGIC_GT LOGIC_GEQ


%token <token> PLUS MINUS MULT DIV VAR ENDL COLON
%left PLUS MINUS MULT DIV
%right EQUAL
%token <token> IF ELIF ELSE FOR WHILE REPEAT UNTIL SWITCH CASE DEFAULT END //THEN BREAK    // Keywords

// types 
%token <token> TYPE_INT TYPE_CHAR TYPE_CONST TYPE_BOOL TYPE_DOUBLE TYPE_STRING

// const values
%token <token> INT_VALUE DOUBLE_VALUE FALSE_VALUE TRUE_VALUE CHAR_VALUE STRING_VALUE


%%
program:
	program block_code {if(debug)printf("matched okay");} // t=1;
	|
	;
block_code:
	statement;
// this is the main building block of our program
statement:
	 expr ENDL
	| typing VAR ENDL { if(debug){printf("%d typing VAR \n", i++);print_symbol_table();}symbol_table_insert($1,$2,false,false,"");  }
	| Constant_type typing VAR ENDL {if(debug){printf("%d const typing VAR \n", i++);print_symbol_table();} symbol_table_insert($2,$3,true,false,"");}
	| Constant_type typing VAR EQUAL expr ENDL {if(debug){printf("%d const typing VAR '=' const_val \n", i++);print_symbol_table();} symbol_table_insert($2,$3,true,true,$5); quadruple_insert("=","t#","NULL",$3,false);  }
	| typing VAR EQUAL expr ENDL {if(debug){printf("%d typing VAR '=' const_val \n", i++);print_symbol_table();} symbol_table_insert($1,$2,false,true,$4); quadruple_insert("=","t#","NULL",$2,false); }
	| VAR EQUAL expr ENDL {if(debug){printf("%d VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable($1,$3);quadruple_insert("=","t#","NULL",$1,false); }
	| if_clause '('expr')' colon if_block END  {if(debug){printf("%d if (expr) do expr  \n", i++);} add_label(); }
	| if_clause '('expr')' colon if_block else_clause if_block END {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} add_label(); }
	| if_clause '('expr')' colon if_block elif_block else_clause if_block END {if (debug){printf("%d if ELIF ELSE expr  \n", i++);}flag_last_case = 1;add_label();flag_last_case = 0; }
	| while_clause '('expr')' colon if_block  {if(debug){printf("%d WHILE  expr  \n", i++); }jump(false,-1); add_label(); }
	| repeat_clause if_block until_clause  '('expr')' colon {if(debug){printf("%d Repeat Until  \n", i++);}}
	| for_clause '(' for_inital ENDL for_condition colon for_inc ')' if_block  { if(debug){printf("%d for loop  expr  \n", i++);} apply_defer();jump(false,-1);add_label();}
	| switch_clause '('expr')' '{' switch_block '}'   {if(debug){printf("%dswitch  expr  \n", i++);}}
	| '{' block_statements '}' { if(debug){printf("%d {  } \n", i++);} }
	| '{''}'
	;

// for part

for_inital:
	VAR EQUAL expr {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable($1,$3);quadruple_insert("=","t#","NULL",$1,false); }
	//typing VAR EQUAL expr {if(debug){printf("%d For Initial: typing VAR EQUAL expr  \n", i++);}quadruple_insert("=","t#","NULL",$2,false); symbol_table_insert($1,$2,false,true,$4);print_symbol_table(); }
	|
	;
for_condition:
	logic_expr
	|
	;
for_inc:
	VAR EQUAL expr {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable($1,$3);quadruple_insert("=","t#","NULL",$1,true); }
	|
	;

// switch case part
switch_block:
		case_block switch_block { if(debug){printf("%d {  } \n", i++);} }
	   | default_clause case_statement	 { if(debug){printf("%d {  } \n", i++);} flag_case=0; flag_last_case = 1;add_label();flag_last_case = 0; }
	   | default_clause  	 { if(debug){printf("%d {  } \n", i++);} flag_case=0; flag_last_case = 1;add_label();flag_last_case = 0; }
	   ;

/*case_statement:
	statement 
	//| statement BREAK ENDL	////////////////////;
	//| BREAK ENDL
	;
 case_statement_extended:
	statement case_statement_extended
	|
	; */
case_statement:
	statement case_statement_extended
	//| statement BREAK ENDL	////////////////////;
	//| BREAK ENDL
	;
case_statement_extended:
	statement case_statement_extended
	|
	;

case_block:
	case_clause const_val colon case_statement {  if(debug){printf("%dcase_block statement break;\n", i++);} }
	;


// the "IF-ELIF-ELSE" part

// if block can also be used for FOR , WHILE , REPEAT UNTIL
if_block:
	'{' block_statements '}'
	|	'{' '}'
	;

elif_block:
		elif_clause  '('expr')' colon if_block elif_block_extended
		;
/* elif_block:
		elif_clause  '('expr')' colon if_block elif_block
		|
		; */

elif_block_extended:
		elif_clause  '('expr')' colon if_block elif_block_extended
		|
		;

block_statements:
	statement {}
	| block_statements statement {}
	;

// expr is anything that can appear on the right hand side of expression
expr:
	const_val	//{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false); }	
	| VAR	{if(debug){printf("%d VAR \n", i++);}if(symbol_table_contains($1)){quadruple_insert("=",$1,"NULL","t#",false);set_var_used($1);}else{char err[100];sprintf(err,"varaible %s is not declared\n", $1);semantic_error_with_msg(err);}}	
	| expr PLUS expr {if(debug){printf("%d expr + expr  \n", i++);} if(check_type_match($1,$3,0)  || check_type_match($1,$3,1)) {$$ = ALU('+',$1,$3);quadruple_insert("+",$1,$3,"t#",false);}else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr MINUS expr {if(debug){printf("%d expr - expr \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('-',$1,$3);quadruple_insert("-",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr MULT expr { if(debug){printf("%d expr * expr \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('*',$1,$3);quadruple_insert("*",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr DIV expr {if(debug){printf("%d  expr / expr  \n", i++);}  if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){ $$ = ALU('/',$1,$3);quadruple_insert("/",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| logic_expr;

logic_expr:
	expr LOGIC_EQ expr 		{if(check_type_match($1,$3,-1)){$$="true";quadruple_insert("==",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_NEQ expr 	{if(check_type_match($1,$3,-1)){$$="true";quadruple_insert("!=",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_OR expr 	{if(check_type_match($1,$3,2)){$$="true";quadruple_insert("||",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_AND expr	{if(check_type_match($1,$3,2)){$$="true";quadruple_insert("&&",$1,$3,"t#",false);} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_LT expr 	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";quadruple_insert("<",$1,$3,"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_LEQ expr	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";quadruple_insert("<=",$1,$3,"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_GT expr 	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";quadruple_insert(">",$1,$3,"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| expr LOGIC_GEQ expr	{if(check_type_match($1,$3,0) || check_type_match($1,$3,1)){$$="true";quadruple_insert(">=",$1,$3,"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", $1,$3);semantic_error_with_msg(err);}}
	| '(' expr ')' {if(debug){printf("%d (expr) \n", i++);}  }
	;

const_val:
	FALSE_VALUE   	{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
	| TRUE_VALUE	{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
	| DOUBLE_VALUE	{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
	| INT_VALUE		{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
	| CHAR_VALUE	{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
	| STRING_VALUE	{if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",$1,"NULL","t#",false);}
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

colon:
	COLON			{if(debug){printf("Type COLON recieved\n");} manage_colon();}
	;
if_clause:
	IF			{if(debug){printf("Type IF recieved\n");}}
	;
elif_clause:
	ELIF			{if(debug){printf("Type ELIF recieved\n");} jump(true,+1); add_label();}
	;
else_clause:
	ELSE			{if(debug){printf("Type ELSE recieved\n");} jump(true,+1); add_label();}
	;
while_clause:
	WHILE			{if(debug){printf("Type WHILE recieved\n");} add_label();}
	;
repeat_clause:
	REPEAT			{if(debug){printf("Type REPEAT recieved\n");}add_label();}
	;
until_clause:
	UNTIL			{if(debug){printf("Type UNTIL recieved\n");} flag_until=1;}
	;
for_clause:
	FOR			{if(debug){printf("Type FOR recieved\n");}add_label();}
	;
switch_clause:
	SWITCH			{if(debug){printf("Type SWITCH recieved\n");}}
	;
case_clause:
	CASE			{if(debug){printf("Type Case recieved\n");} if(!flag_case){t_reg=t-1;flag_case=1;}else{jump(true,+1); add_label();}}
	;
default_clause:
	DEFAULT			{if(debug){printf("Type Default recieved\n");} jump(true,+1); add_label();}
	;


%%

struct symbol_table symbol_table_elements[500];
/* struct symbol_table symbol_table_elements_scoped[200]; */
int symbol_table_idx = 0;
/* int symbol_table_scope_idx = 0; */

struct Quadruple quadruples[200];
struct Quadruple defer_quadruples[5];
int quadruple_idx = 0;

// Symbol table functions

bool symbol_table_contains(char* var_name) {//symbol_table_contains
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return true;
	}

	return false;
}

int symbol_table_get_varType(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].type;
	}
}

bool is_var_initialized(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].initialized;
	}
	return false;
}

bool is_var_constant(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].constant;
	}
	return false;
}

void symbol_table_insert(char* var_type, char* var_name, bool is_const, bool is_initial, char* var_value){
	// check if already found
	if(symbol_table_contains(var_name)) { 
		char err[100];
		sprintf(err,"Redeclaration of already declared variable %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	// check for type
	int dtype = convert_name_type(var_type);
	if(dtype == -1){
		char err[100];
		sprintf(err,"Unknown type for variable %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	// check if const and not initialized
	if(is_const && !is_initial){
		char err[100];
		sprintf(err,"type Const variable must be initialized immediately %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}

	struct symbol_table new_element;
	new_element.type = dtype;
	new_element.initialized = is_initial;
	new_element.constant = is_const;
	new_element.used = false;
	new_element.line_num = lineno;
	
	strcpy(new_element.name, var_name);
	
	// insert a non-initialized element
	if(!is_initial){
		symbol_table_elements[symbol_table_idx++] = new_element;
		return;
	}

	int val_type = check_val_type(var_value);
	if(val_type != 5){
		if(new_element.type != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_error_with_msg(err); return;
		}
	}
	// assign var to var
	else{
		if(!symbol_table_contains(var_value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable: %s\n",var_name, var_value);
			semantic_error_with_msg(err); 
			return; 
		}
		
		int v_type_int = symbol_table_get_varType(var_value);

		if(v_type_int != new_element.type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_error_with_msg(err); return; 
		}

		if(!is_var_initialized(var_value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not initialized variable: %s\n", var_name, var_value);
			semantic_error_with_msg(err);
		}

		set_var_used(var_value);
	}
	// insert an initialized element
	new_element.initialized = true;
	symbol_table_elements[symbol_table_idx++] = new_element;
}

void set_var_initialized(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
		{
			symbol_table_elements[i].initialized = true;
			return;
		}
	}
}

void set_var_used(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
		{
			symbol_table_elements[i].used = true;
			return;
		}
	}
}

bool check_type_match(char* x, char* y, int specified){
	int x_type = check_val_type(x),y_type = check_val_type(y);
	if(x_type == 5){
		x_type = symbol_table_get_varType(x);
	}
	if(y_type == 5){
		y_type = symbol_table_get_varType(y);
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
	
	if(!symbol_table_contains(var_name)) { 
		char err[100];
		sprintf(err,"%s not declared\n", var_name);
		semantic_error_with_msg(err); 
		return; 
	}

	if(is_var_constant(var_name)){
		char err[100];
		sprintf(err,"Constant var can't be re-initialized %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	
	if(is_var_initialized(var_name)){
		set_var_used(var_name);
	}

	int var_type_int = symbol_table_get_varType(var_name);
	int val_type = check_val_type(value);
	if(val_type != 5){
		if(var_type_int != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch) %s and %s are of different types\n", var_name, value);
			semantic_error_with_msg(err); return;
		}
		set_var_initialized(var_name);
	}
	// assign var to var
	else{
		if(!symbol_table_contains(value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable %s\n",var_name ,value);
			semantic_error_with_msg(err); 
			return; 
		}

		int v_type_int = symbol_table_get_varType(value);

		if(v_type_int != var_type_int){ 
			char err[100];
			sprintf(err,"%s and %s are of different types\n", var_name, value);
			semantic_error_with_msg(err); return; 
		}
		
		if(!is_var_initialized(value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not initialized variable %s\n",var_name ,value);
			semantic_error_with_msg(err);
		}
		set_var_initialized(var_name);
	}
}


void print_symbol_table() {
	for(int s = 0; s < symbol_table_idx; s++) {
		printf("[%d] type: %s\tname: %s\tconst: %s\tinitialized: %s\tused: %s\tline#: %d\n", s+1, arr_type[symbol_table_elements[s].type], symbol_table_elements[s].name, symbol_table_elements[s].constant ? "true" : "false", symbol_table_elements[s].initialized? "true" : "false",symbol_table_elements[s].used? "true" : "false",symbol_table_elements[s].line_num);
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
		y_type = symbol_table_get_varType(y);
	}else if( op == '/' && atoi(y) == 0){
		char err[100];
		sprintf(err,"Warning: you might be dividing by zero\n");
		semantic_error_with_msg(err);
	}
	return reverse_type_value(y_type);
}

void quadruple_insert(char* op, char* src1_passed, char* src2_passed, char* dst_passed, bool defer){
	if(debug)printf("Quadruples: operator: %s, src1: %s, src2: %s, dst: %s\n",op,src1_passed,src2_passed,dst_passed);
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
	}
	if (strcmp(dst_passed,"t#") == 0){
		strcpy(dst, "t");
		sprintf(str_num, "%d", t++);
		strcat(dst,str_num);
	}
	struct Quadruple new_element;

	/* new_element.line_num = lineno; */
	strcpy(new_element.dst, dst);
	strcpy(new_element.src1, src1);
	strcpy(new_element.src2, src2);
	strcpy(new_element.op, op);

	if (defer){
		defer_quadruples[0] = new_element;
	}
	else{
		quadruples[quadruple_idx++] = new_element;
	}
}

void manage_colon(){
	char str_num[5];
	struct Quadruple new_element;
	// operation
	strcpy(new_element.op, "JNE");

	// first argument
	if(flag_case){
		strcpy(new_element.src1, "t");
		sprintf(str_num, "%d", t-1);
		strcat(new_element.src1,str_num);	
	}
	else{
		strcpy(new_element.src1, "true");
	}
	// t# at second argument
	strcpy(new_element.src2, "t");
	if(flag_case){
		sprintf(str_num, "%d", t_reg);
		strcat(new_element.src2,str_num);	
	}
	else{
		sprintf(str_num, "%d", t-1);
		strcat(new_element.src2,str_num);
	}
	// label at dst
	strcpy(new_element.dst, "label");
	if(flag_until == 1){
		sprintf(str_num, "%d", label-1);
		flag_until = 0;
	}else if(flag_case){
		sprintf(str_num, "%d", label++);
	}
	else{
		sprintf(str_num, "%d", label);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void jump(bool switch_case, int to){
	char str_num[5];
	struct Quadruple new_element;
	strcpy(new_element.src1, "");
	strcpy(new_element.src2, "");
	strcpy(new_element.op, "jmp");
	if(switch_case){
		strcpy(new_element.dst, "lbl");
		sprintf(str_num, "%d", label_switch_case);
	}else{
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label+to);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void add_label(){
	char str_num[5];
	struct Quadruple new_element;
	strcpy(new_element.src1, "");
	strcpy(new_element.src2, "");
	strcpy(new_element.op, "");
	if(flag_last_case){
		strcpy(new_element.dst, "lbl");
		sprintf(str_num, "%d", label_switch_case++);
	}
	else if(flag_case){
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label-1);
	}else{
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label++);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void apply_defer(){
	quadruples[quadruple_idx++] = defer_quadruples[0];
}

void print_quadruples(){
	printf("\n-------------------------printttttttttt Quadruples-------------------------\n");
	for(int q = 0; q < quadruple_idx; q++){
		//printf("\nline: %d\n", quadruples[q].line_num);
		printf("arg1: %s\t", quadruples[q].src1);
		printf("operation: %s\t", quadruples[q].op);
		printf("arg2: %s\t", quadruples[q].src2);
		printf("result: %s\n", quadruples[q].dst);
	}
	printf("-------------------------End printttttttttt Quadruples-------------------------\n");
}

void print_warning(){
	for(int i = 0; i < symbol_table_idx; i++){
		if(!symbol_table_elements[i].initialized && symbol_table_elements[i].used)
			printf("Warning! variable %s at line %d used without being initialized, contain garbage(Rubbish)\n",symbol_table_elements[i].name,symbol_table_elements[i].line_num);
		if(!symbol_table_elements[i].used)
			printf("Warning! variable %s at line %d is not used, please take care of your memory\n",symbol_table_elements[i].name,symbol_table_elements[i].line_num);
	}
}


void semantic_error_with_msg(char * err){
	semantic_error_found = true;
	fprintf(stderr, "Semantic error at line %d | %s\n", lineno, err);
}

void yyerror(char*s){
	fprintf(stderr, "syntax error at line %d\n", lineno);
	exit(1);
}

int main(int argc,char* argv[])
{
	int syntax_err_found;
	yyin = fopen(argv[1], "r");
	syntax_err_found = yyparse();
	fclose(yyin);
	
	if(!syntax_err_found && !semantic_error_found) print_quadruples();
	print_symbol_table();
	print_warning();
	printf("end of parser\n");
	return 0;
}