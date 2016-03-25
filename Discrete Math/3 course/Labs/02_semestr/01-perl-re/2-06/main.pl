while ($line = <STDIN>) {
  $line =~ s/([A-Za-z])\g1/$1/g;
  print $line;
}