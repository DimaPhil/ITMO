from sys import *
from math import *

inp = open("num2brackets2.in", "r")
out = open("num2brackets2.out", "w")

n, k = inp.read().split()
n = int(n)
k = int(k)

dp = [[0 for i in range(n + 2)] for j in range(2 * n + 2)]
dp[0][0] = 1
for i in range(2 * n + 1):
    for j in range(n + 1):
        if j > 0:
            dp[i + 1][j - 1] += dp[i][j]
        if j + 1 <= n:
            dp[i + 1][j + 1] += dp[i][j]
twos = [1 for i in range(2 * n + 1)]
for i in range(1, 2 * n + 1):
    twos[i] = twos[i - 1] * 2

ans = ""
balance = 0
stack = [0 for i in range(2 * n + 1)]
sz = 0
for i in range(2 * n - 1, -1, -1):
    cur = 0
    if balance + 1 <= n:
        cur = dp[i][balance + 1] * twos[(i - balance - 1) // 2]
    if k < cur:
        ans += '('
        stack[sz] = '('
        sz += 1
        balance += 1
        continue
    k -= cur
    
    cur = 0
    if sz > 0 and stack[sz - 1] == '(' and balance > 0:
        cur = dp[i][balance - 1] * twos[(i - balance + 1) // 2]
    if k < cur:
        ans += ')'
        sz -= 1
        balance -= 1
        continue
    k -= cur

    cur = 0
    if balance + 1 <= n:
        cur = dp[i][balance + 1] * twos[(i - balance - 1) // 2]
    if k < cur:
        ans += '['
        stack[sz] = '['
        sz += 1
        balance += 1
        continue
    k -= cur

    ans += ']'
    sz -= 1
    balance -= 1

print(k)
print(ans)
