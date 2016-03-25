while ($line = <STDIN>) {
  $line =~ s/\b(\d+)0\b/$1/g;
  print $line;
}