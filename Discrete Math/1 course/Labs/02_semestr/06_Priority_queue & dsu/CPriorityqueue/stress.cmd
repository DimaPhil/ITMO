@echo off
for /L %%i in (1, 1, 100500) do (
  gen.exe
  main.exe
  a.exe
  fc stress.out priorityqueue.out || exit
  echo Test %%i: OK
)