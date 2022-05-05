echo "=============================="
echo "running tests"
$files = dir ./examples
foreach($file in $files){
    # echo ./examples/$file.FullName
    $err =( .\test.exe $file.FullName| sls err ) 2>&1

    if($err){
        echo $file.BaseName " error: " $err 
        echo "run this to debug it "
        echo (".\test.exe "+$file.FullName+" | sls err ")
    }else{
        echo $file.BaseName " success " 

    }
}
# .\test.exe .\examples\ex1.p | sls err 
# .\test.exe .\examples\ex2.p | sls err 
# .\test.exe .\examples\ex3.p | sls err 
# .\test.exe .\examples\ex4.p | sls err 
echo "end of  tests"
echo "=============================="

