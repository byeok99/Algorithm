import sys
sys.setrecursionlimit(2000)
input = sys.stdin.readline
n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)
cnt = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(u):
    visited[u] = True
    for v in graph[u]:
        if not visited[v]:
            dfs(v)

for i in range(1, n+1):
    if not visited[i]:
        cnt += 1
        dfs(i)

print(cnt)