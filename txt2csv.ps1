function tocsv($file)
{
    $target = $file -replace "(\w+)\..*",'$1.csv';
    $data = (Get-Content $file) -match "'data':(\[(.*)\])";
    
    if($data.Length -eq 0) {write-host "not found";return;}
    
    $head = $data[0] -replace "'data':\[\{([^\}]*)\},.*", '$1';
    $head = $head -replace "'(\w*)':'\w*'", '$1';
    Set-Content $target $head;

    foreach($con in $data) {
        $con = $con -replace "'data':\[\{(.*)\}\]", '$1';
        $con = $con -replace "},{", "`r`n";
        $con = $con -replace "'\w*':'(\w*)'", '$1';
    
        Add-Content $target $con;
    }

}

$files = (Get-ChildItem -name *.txt);
foreach($f in $files)
{
    tocsv($f);
}