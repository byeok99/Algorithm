n = int(input())
nums = list(map(int, input().split()))

nums.sort()
sum = 0
wait = 0
for i in range(n):
    sum += nums[i] + wait
    wait += nums[i]

print(sum)