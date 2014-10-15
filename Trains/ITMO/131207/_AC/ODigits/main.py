from sys import *

inp = open("digits.in", "r")
out = open("digits.out", "w")
n = int(inp.readline())

dp = [0 for i in range(n + 10)]
sum = [0 for i in range(n + 10)]
ten = [0 for i in range(n + 10)]
ten[0] = 1
for i in range(1, n + 1):
  ten[i] = ten[i - 1] * 10

for i in range(1, n + 1):
  for d in range(1, 10):
    dp[i] += d * ten[i - 1] + sum[i - 1]
  sum[i] = sum[i - 1] + dp[i]
out.write(str(sum[n]))