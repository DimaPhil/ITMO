@echo off

g++ -Wall -O2 gen.cpp -o gen.exe
g++ -Wall -O2 stress.cpp -o stress.exe
g++ -Wall -O2 main.cpp -o main.exe

for /L %%i in (1, 1, 100500) do (
  gen.exe
  main.exe
  stress.exe
  fc parking.out stress.out || exit
  echo Test %%i: OK
)