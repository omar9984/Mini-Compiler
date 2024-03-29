(make build )2>build_out.txt
$conf = cat build_out.txt | sls  conflict,"Error" -CaseSensitive
echo $conf
if ( $conf ) {
    # echo $file.BaseName " error: " $err 
    Write-Host  ("parser confilct or error run `make debug` for more info ") -ForegroundColor red
    exit
} else {
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
        Write-Host "  success "   -ForegroundColor Blue

    }
}
if($wins -eq $files.Count){

    Write-Host  ("success rate " + $wins +  "/"+ $files.Count)  -ForegroundColor DarkGreen -BackgroundColor DARKYELLOW
}else{
    Write-Host  ("success rate " + $wins +  "/"+ $files.Count)  -ForegroundColor DarkGreen

}

echo "end of  tests"
echo "=============================="

