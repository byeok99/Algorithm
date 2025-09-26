import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * 1001
dp[0] = 1
dp[1] = 3

for i in range(2, 1001):
    dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007

print(dp[n-1])