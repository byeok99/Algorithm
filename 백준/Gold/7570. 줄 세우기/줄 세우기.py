import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

dp = [0] * (n + 1)
ret = 0
for i in nums:
    dp[i] = dp[i-1] + 1
    if dp[i] > ret:
        ret = dp[i]

print(n-ret)