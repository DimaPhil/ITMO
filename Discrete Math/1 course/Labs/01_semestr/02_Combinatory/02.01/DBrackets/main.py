from math import *

def cnt(n):
  return factorial(2 * n) // factorial(n) // factorial(n) // (n + 1)

print(cnt(10))