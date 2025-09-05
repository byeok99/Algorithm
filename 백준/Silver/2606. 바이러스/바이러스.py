import sys
input = sys.stdin.readline

def dfs(u):
    visited[u] = True
    global cnt
    for v in graph[u]:
        if not visited[v]:
            cnt += 1
            dfs(v)

v = int(input())
e = int(input())

graph = [[] for _ in range(v+1)]
visited = [False] * (v+1)
cnt = 0
for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(1)

print(cnt)