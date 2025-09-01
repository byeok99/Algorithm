import sys, heapq
input = sys.stdin.readline


n = int(input())
times= [tuple(map(int, input().split())) for _ in range(n)]
times.sort(key=lambda x: (x[0], x[1]))

que = []
heapq.heappush(que, times[0][1])

for s, e in times[1:]:
    if que[0] <= s:
        heapq.heappop(que)
    heapq.heappush(que, e)

print(len(que))
