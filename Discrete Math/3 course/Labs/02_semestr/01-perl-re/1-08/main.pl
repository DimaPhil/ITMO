while (<>) {
  print if /\([^(^)]*\w([^(^)])*\)/
}