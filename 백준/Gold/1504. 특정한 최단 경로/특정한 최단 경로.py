import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)
def dijkstra(start, graph, n):
    dist = [INF] * (n+1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if dist[now] < cost:
            continue

        for nxt, w in graph[now]:
            new_cost = w + cost
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))

    return dist
n, e = map(int, input().split())
graph = [[] for _ in range(n+1)]
for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

d1 = dijkstra(1, graph, n)
d2 = dijkstra(v1, graph, n)
d3 = dijkstra(v2, graph, n)

path1 = d1[v1] + d2[v2] + d3[n]
path2 = d1[v2] + d3[v1] + d2[n]

ret = min(path1, path2)
print(ret if ret < INF else -1)