#!/usr/bin/perl

@urls = ();
while ($line = <STDIN>) {
  $line =~ s/^\s*//;
  $line =~ s/\s*$//;
  while ($line =~ /<a(.*)href="((http|https|ftp?):\/\/)?(\w+.*?)(:|\/|")(.*)>/g) {
    push(@urls, $4);
  }
}
@urls = sort(@urls);
$i = 0;
$len = @urls;
@unique_urls = (@urls[0]);
while ($i + 1 < $len) {
  if (@urls[$i] ne @urls[$i + 1]) {
    push(@unique_urls, @urls[$i + 1]);
  }
  $i++;
}
print join("\n", @unique_urls) . "\n";

