while ($line = <STDIN>) {
  $line =~ s/human/computer/g;
  print $line;
}