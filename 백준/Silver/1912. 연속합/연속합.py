import sys
input = sys.stdin.readline

n = int(input())
lst = list(map(int, input().split()))
dp = [0] * (n)

for i in range(n):
    dp[i] = lst[i]

    if lst[i] + dp[i-1] > lst[i]:
        dp[i] = lst[i] + dp[i-1]

print(max(dp))