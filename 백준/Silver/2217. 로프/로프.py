n = int(input())
nums = [int(input()) for _ in range(n)]
nums.sort()

_max = 0
for i in range(n):
    _max = max(_max, nums[i] * (n-i))

print(_max)