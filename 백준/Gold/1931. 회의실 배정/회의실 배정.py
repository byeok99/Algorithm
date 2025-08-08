n = int(input())
times = []
cnt = 0
new_end = 0

for _ in range(n):
    start, end = map(int, input().split())
    times.append((start, end))
times.sort(key=lambda x: (x[1], x[0]))

for start, end in times:
    if new_end <= start:
        cnt += 1
        new_end = end
print(cnt)
