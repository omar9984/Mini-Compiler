$conf = (make build | sls confict)2>&1

if($conf){
    # echo $file.BaseName " error: " $err 
    Write-Host  ("parser confilct run `make debug` for more info ") -ForegroundColor red

}else{
    $wins++
    Write-Host   "build is ok no confilcts "   -ForegroundColor DarkGreen

}


echo "=============================="
echo "running tests"
$files = dir ./examples
$wins=0
foreach($file in $files){
    # echo ./examples/$file.FullName
    $err =( .\test.exe $file.FullName| sls err ) 2>&1
    echo $file.BaseName
    if($err){
        Write-Host  ("  syntax error in " +$file.BaseName ) -ForegroundColor red
    }else{
        $wins++
        echo "  success " 

    }
}

Write-Host  ("success rate " + $wins +  "/"+ $files.Count)  -ForegroundColor DarkGreen -BackgroundColor DARKYELLOW

echo "end of  tests"
echo "=============================="

