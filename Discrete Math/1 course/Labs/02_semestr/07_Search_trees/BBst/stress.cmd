@echo off
for /L %%i in (1, 1, 100500) do (
  gen.exe
  main2.exe
  stress.exe
  fc stress.out bst.out || exit
  echo Test %%i: OK
)