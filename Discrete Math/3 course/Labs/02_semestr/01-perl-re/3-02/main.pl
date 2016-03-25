#!/usr/bin/perl

@lines = ();
while (<>) {
  $line =~ s/<[^>]*>//g;
  $line =~ s/<\/[^>]*>//g;
  #print $line . "\n";
  push(@lines, $line);
}

