n = int(input())
ret= 0
nums = []

for i in range(n):
    nums.append(int(input()))

for i in range(len(nums)-1, 0, -1):
    if nums[i-1] >= nums[i]:
        cnt =  nums[i-1]-(nums[i] - 1)
        nums[i-1] -= cnt
        ret += cnt

print(ret)
