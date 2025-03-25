n = int(input())
for i in range(1, n+1):
    _list = list(map(int, input().split()))
    _list.pop(0)
    max_gap = 0
    _list.sort()
    for j in range(1, len(_list)):
        if _list[j] - _list[j-1] > max_gap: max_gap = _list[j] - _list[j-1]
    print("Class",i)
    print(f"Max {_list[-1]}, Min {_list[0]}, Largest gap {max_gap}")