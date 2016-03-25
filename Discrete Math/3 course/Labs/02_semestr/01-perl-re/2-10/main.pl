while ($line = <STDIN>) {
  $line =~ s/a.*?aa.*?aa.*?a/bad/g;
  print $line;
}