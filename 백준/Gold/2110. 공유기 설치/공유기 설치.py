def can(dist):
    count = 1
    prev = lst[0]

    for i in range(n):
        if lst[i] - prev >= dist:
            count += 1
            prev = lst[i]

    return count >= c

n ,c = map(int, input().split())
lst = list(int(input()) for _ in range(n))
chk = [False] * n
lst.sort()

min_value = (lst[-1] - lst[0]) // c

ret = 0
low, high = 1, lst[-1] - lst[0]
while low <= high and c > 0:
    mid = (low + high) // 2

    if can(mid):
        ret = mid
        low = mid + 1
    else :
        high = mid -1

print(ret)