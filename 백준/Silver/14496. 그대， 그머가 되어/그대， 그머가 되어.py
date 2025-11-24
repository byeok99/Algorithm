import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, graph):
    dist = [INF] * len(graph)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if cost > dist[now]:
            continue

        for nxt, w in graph[now]:
            new_cost = cost + w
            if dist[nxt] > new_cost:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))

    return dist

def main():
    a, b = map(int, input().split())
    n, m = map(int, input().split())

    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        c, d = map(int, input().split())
        graph[c].append((d, 1))
        graph[d].append((c, 1))

    ret = dijkstra(a, graph)
    ret = ret[b]
    print(-1 if ret == INF else ret)

if __name__ == "__main__":
    main()
