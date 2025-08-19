_str = list(input().split('-'))
nums = []
ret = 0

for i in _str:
    if i.isdigit():
        nums.append(int(i))
    else :
        nums.append(sum(map(int, i.split('+'))))

ret = nums[0]
for i in nums[1:]:
    ret -= i

print(ret)