n, m = map(int, input().split())
nums = list(map(int, input().split()))

for i in range(m):
    nums.sort()
    nums[0] = nums[0] + nums[1]
    nums[1] = nums[0]

print(sum(nums))