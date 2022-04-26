%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
%}

%token INT PLUS MINUS MULT DIV POW VAR
%left PLUS Minus
%left MULT DIV
%right POW
%%
program:
	program statement '\n'
	|
	;
statement: 
	expr	{ printf("%d\n", $1); }
	| VAR '=' expr {sym[$1]=$3;}
	;
expr:
	INT	{ $$  = $1; }
	| VAR { $$ = sym[$1]; }
	| expr PLUS expr { $$ = $1 + $3;}
	| expr Minus expr { $$ = $1 - $3;}
	| expr MULT expr { $$ = $1 * $3;}
	| expr DIV expr { $$ = $1 / $3;}
	| expr POW expr {
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