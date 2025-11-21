import sys
import heapq

input = sys.stdin.readline

def dijkstra(graph, n, start):
    INF = int(1e9)
    dist = [INF] * (n+1)
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        cost, now = heapq.heappop(pq)
        if cost > dist[now]:
            continue

        for nxt, w in graph[now]:
            new_cost = cost + w
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))

    cnt = sum(1 for x in dist[1:] if x != INF)
    time = max([x for x in dist[1:] if x != INF])
    return cnt, time

t = int(input())

while t > 0:
    t -= 1
    n, d, c = map(int, input().split())

    graph = [[] for _ in range(n+1)]
    for i in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))

    ret = dijkstra(graph, n, c)
    print(ret[0], ret[1])