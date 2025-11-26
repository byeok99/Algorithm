import sys, heapq
input = sys.stdin.readline

a, b, c = map(int, input().split())
lst = [0] * 104

for _ in range(3):
    n, m = map(int, input().split())

    for i in range(n, m):
        lst[i] += 1

ret = 0
for i in lst:
    if i == 1: ret += i * a
    elif i == 2 : ret += i * b
    elif i == 3 : ret += i * c

print(ret)