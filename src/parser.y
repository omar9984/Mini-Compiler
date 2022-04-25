%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
%}

%token Integer Plus Minus Mult Div Power Var
%left Plus Minus
%left Mult Div
%right Power
%%
program:
	program statement '\n'
	|
	;
statement: 
	expr	{ printf("%d\n", $1); }
	| Var '=' expr {sym[$1]=$3;}
	;
expr:
	Integer	{ $$  = $1; }
	| Var { $$ = sym[$1]; }
	| expr Plus expr { $$ = $1 + $3;}
	| expr Minus expr { $$ = $1 - $3;}
	| expr Mult expr { $$ = $1 * $3;}
	| expr Div expr { $$ = $1 / $3;}
	| expr Power expr {
			int x = $1;
			for (int i = 1; i < $3; i++){
				x *= $1;
			}
			$$ = x;
	}
	| '(' expr ')' { $$ = $2; }
	
%%


void yyerror(char*s){
	fprintf(stderr, "%s\n", s);
}
int main(void){
	yyparse();
	printf("hello we are good");
	return 0;
}