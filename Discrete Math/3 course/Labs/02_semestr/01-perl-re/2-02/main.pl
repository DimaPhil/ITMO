while ($line = <STDIN>) {
  $line =~ s/\bhuman\b/computer/g;
  print $line;
}