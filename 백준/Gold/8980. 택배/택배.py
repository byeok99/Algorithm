import sys
input = sys.stdin.readline
n, c = map(int, input().split())
m = int(input())

boxs = [tuple(map(int, input().split())) for _ in range(m)]
boxs.sort(key=lambda x: (x[0], x[1], x[2]))
truck = [c] * (n+1)
ret = 0

for s, e, w in boxs:
    can = min(truck[s:e])
    load = min(can, w)

    if load > 0:
        for i in range(s, e):
            truck[i] -= load

        ret += load

print(ret)
