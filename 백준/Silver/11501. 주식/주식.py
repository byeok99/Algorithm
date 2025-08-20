t = int(input())

for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    max_arr = [0] * len(nums)
    max_num = 0
    for i in range(len(nums)-1, -1, -1):
        if max_num < nums[i]:
            max_num = nums[i]
        max_arr[i] = max_num

    ret = 0
    for i in range(len(nums)):
        if nums[i] < max_arr[i]:
            ret += max_arr[i] - nums[i]
            
    print(ret)

