from sys import *
inp = open("subtract.in", "r")
out = open("subtract.out", "w")
a, b = inp.read().split()
a = int(a)
b = int(b)
out.write(str(a - b))