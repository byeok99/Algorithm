import sys
input = sys.stdin.readline

n = int(input())
lst = list(map(int, input().split()))
m = int(input())

low, high = 0, max(lst)
ret = 0

while low <= high:
    mid = (low + high) // 2
    total = sum(min(i, mid) for i in lst)

    if total <= m:
        ret = mid
        low = mid + 1
    else :
        high = mid - 1

print(ret)