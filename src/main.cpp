
#include<iostream>
using namespace std;
#include "parser.tab.h"


extern "C" FILE* yyin;
int main(int argc,char* argv[]){

	FILE* fileInput;
    char inputBuffer[36];
    char lineData[36];

    if((fileInput=fopen(argv[1],"r"))==NULL)
    {
    printf("Error reading files, the program terminates immediately\n");
    exit(0);
    }
    // parse(fileInput);
    yyin = fileInput;
	yyparse();
	// printf("end of parser\n"); 
    // cout << "hello world of c++" << endl;

	return 0;
}