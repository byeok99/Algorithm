import sys
input = sys.stdin.readline

n, k = map(int, input().split())
nums = list(map(int, input().split()))
tap = [0] * n
ret = 0

for i in range(k):
    item = nums[i]

    if item in tap:
        continue

    if tap.count(0) > 0:
        tap[tap.index(0)] = item
        continue

    temp = 0
    idx = 0
    for j in range(n):
        # 앞으로 안쓰면
        if tap[j] not in nums[i:] :
            idx = j
            break

        # 더 쓰이면
        elif nums[i:].index(tap[j]) > temp:
            temp = nums[i:].index(tap[j])
            idx = j

    tap[idx] = item
    ret += 1

print(ret)
