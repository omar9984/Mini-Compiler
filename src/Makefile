build: parser.y scanner.l
	bison -d parser.y 
	flex scanner.l
	gcc -std=gnu99  -o test.exe lex.yy.c parser.tab.c
test: test.exe
	echo "1+2" |.\test.exe
	echo "2+2*3+2" |.\test.exe
	echo "2+(2)+2" |.\test.exe
	echo "2+23/2" |.\test.exe
