while ($line = <STDIN>) {
  $line =~ s/\b[Aa]+\b/argh/;
  print $line;
}