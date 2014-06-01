@echo off
for /L %%i in (1, 1, 100500) do (
  gen.exe
  main.exe
  stress.exe
  fc crypto.out stress.out || exit
  echo Test %%i: OK
)