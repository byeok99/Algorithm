import sys
input = sys.stdin.readline

n, k = map(int, input().split())
lst = list(map(int,input().split()))

prefix_sum = [0] * (n+1)

for i in range(1,n+1):
    prefix_sum[i] = prefix_sum[i-1] + lst[i-1]

ans = float('-inf')
for i in range(k, n+1):
    ans = max(ans, prefix_sum[i] - prefix_sum[i-k])

print(ans)