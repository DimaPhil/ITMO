#!/usr/bin/perl

@lines = ();
while ($line = <STDIN>) {
  $line =~ s/<[^>]*>//g;
  $line =~ s/<\/[^>]*>//g;
  #print $line . "\n";
  push(@lines, $line);
}

$fi = 0;
while (@lines[$fi] =~ /^\s+$|^$/) {
  $fi++;
}
$li = @lines - 1;
while (@lines[$li] =~ /^\s+$|^$/) {
  $li--;
}
$i = $fi;
$last_line = "xxx";
while ($i <= $li) {
  $line = $lines[$i];
  $line =~ s/^\s+//;
  $line =~ s/\s+$//;
  $line =~ s/\ +/ /g;
  if ($last_line !~ /^$/) {
    print $line . "\n";
  }
  if ($last_line =~ /^$/ && $line !~ /^$/) {
    print $line . "\n";
  }
  $last_line = $line;
  $i++;
}
#print @lines;