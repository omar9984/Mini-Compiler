build: parser.y scanner.l
	bison -d parser.y 
	flex scanner.l
	gcc -std=gnu99  -o test.exe lex.yy.c parser.tab.c
test: test.exe
	echo if(a==3){}elif(a==2){}else{a=323;} a=23; while(true){int a=32;} while(false){} repeat{}until(a==2) |.\test.exe

