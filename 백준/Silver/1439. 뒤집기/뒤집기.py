s = input()

flag = 0
target = 0
cnt = 0
for i in s:
    if int(i) == target and flag == 0:
        flag = 1
        cnt += 1
    elif int(i) != target:
        flag = 0

flag = 0
target = 1
_cnt = 0
for i in s:
    if int(i) == target and flag == 0:
        flag = 1
        _cnt += 1
    elif int(i) != target:
        flag = 0

print(min(cnt, _cnt))