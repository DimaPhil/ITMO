@echo off
for /L %%i in (1, 1, 100500) do (
  gen.exe
  main2.exe
  main3.exe
  fc stress.out num2perm.out || exit
  echo Test %%i: OK
)