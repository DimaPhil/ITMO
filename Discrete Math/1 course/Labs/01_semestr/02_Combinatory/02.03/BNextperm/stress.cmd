@echo off
for /L %%i in (1, 1, 100500) do (
  gen.exe
  stress.exe
  main.exe
  fc nextperm.out stress.out || exit
  echo Test %%i: OK
)
