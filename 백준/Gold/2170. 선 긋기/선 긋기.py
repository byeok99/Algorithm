import sys
input = sys.stdin.readline

n = int(input())
nums = [tuple(map(int, input().split())) for i in range(n)]
nums.sort()

ret = 0
start, end = nums[0]

for s, e in nums[1:]:
    if s > end: 
        ret += end - start
        start, end = s, e 
    else : 
        end = max(end, e) 

ret += end - start 
print(ret)
