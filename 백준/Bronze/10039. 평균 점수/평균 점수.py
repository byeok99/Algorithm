_list = []
for _ in range(5):
    _list.append(int(input()))

_sum = 0

for x in _list:
    if x < 40: x = 40
    _sum += x

print(int(_sum / 5))