echo "if(a==3){}elif(a==2){}else{a=323;} a=23; while(true){int a=32;} while(false){} repeat{}until(a==2)" | .\test.exe
echo "switch(true){ case 2: a=32; default: }" | ./test.exe
echo "for(a=32;a < 3;a=a+21){a=32;}" | ./test.exe
