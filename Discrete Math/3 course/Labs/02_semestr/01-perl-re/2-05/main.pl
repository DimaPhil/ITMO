while ($line = <STDIN>) {
  $line =~ s/\b(\w)(\w)(\w*)\b/\2\1\3/g;
  print $line;
}