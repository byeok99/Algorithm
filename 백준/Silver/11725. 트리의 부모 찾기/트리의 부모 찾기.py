import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
tree = [[0] for _ in range(n+1)]
parent = [0] * (n+1)
parent[1] = 0

for _ in range(n-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

q = deque()
q.append(1)

while q:
    current = q.popleft()
    for v in tree[current]:
        if parent[v] == 0:
            parent[v] = current
            q.append(v)

for v in parent[2:]:
    print(v)