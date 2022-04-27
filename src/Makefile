build: parser.y scanner.l
	bison -d parser.y 
	flex scanner.l
	gcc -std=gnu99  -o test.exe lex.yy.c parser.tab.c
test: test.exe
	echo "if(true){ a=23; if(true){a=23;}}" |.\test.exe

