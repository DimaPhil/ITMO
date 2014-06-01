@echo off

g++ -Wall -O2 solve.cpp -o solve.exe
g++ -Wall -O2 silly.cpp -o silly.exe
g++ -Wall -O2 gen.cpp -o gen.exe

for /L %%i in (1, 1, 100500) do (
  gen.exe
  solve.exe
  silly.exe
  fc stress.out queuemin2.out || exit
  echo Test %%i: OK
  echo %TIME%
)