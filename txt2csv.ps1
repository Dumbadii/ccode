function tocsv($file)
{
    $target = $file -replace "(\w+)\..*",'$1.csv';
    $con = Get-Content $file;

    $head = $con -replace ".*'data':\[\{([^\}]*)\},.*", '$1';
    $head = $head -replace "'(\w*)':'\w*'", '$1';
    Set-Content $target $head;

    $con = $con -replace ".*'data':\[\{(.*)\}\].*", '$1';
    $con = $con -replace "},{", "`r`n";
    $con = $con -replace "'\w*':'(\w*)'", '$1';
    
    Add-Content $target $con;
}

$files = (Get-ChildItem -name *.txt);
foreach($f in $files)
{
    tocsv($f);
}