# this powershell is assuming you're using powershell to run it 

build: ./rules/parser.y ./rules/scanner.l
	bison -d ./rules/parser.y 
	flex ./rules/scanner.l
	g++ -o test.exe lex.yy.c parser.tab.c main.cpp
# gcc -std=gnu99  -o test.exe lex.yy.c parser.tab.c
# some cases need to be copy pasted into powershell to work
test: test.exe
	echo if(a==3){}elif(a==2){}else{a=323;} a=23; while(true){int a=32;} while(false){} repeat{}until(a==2) |.\test.exe
	echo "switch(true){ case 2: a=32; default: }" | ./test.exe
	echo "for(a=32;a < 3;a=a+21){a=32;}" | ./test.exe
debug: parser.y
	bison -d ./rules/parser.y -Wcounterexamples