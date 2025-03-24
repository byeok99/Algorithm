import sys

K = int(sys.stdin.readline())

nums = []
for i in range(K) :
    nums.append(int(sys.stdin.readline()));

cnt = 0;
sum = 0;
for i in range(1,len(nums)+1) :
    if nums[-i] == 0 :
        cnt += 1
    else :
        if cnt == 0 :
            sum += nums[-i]
        else :
            cnt -= 1

print(sum)