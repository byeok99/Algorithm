def solve(lst:list, target:int):
    s=0
    e=len(lst)-1
    while s<=e :
        m = (s+e)//2
        if lst[m] == target:
            return m
        elif lst[m] < target:
            s = m+1
        else : e = m-1

    return -1
if __name__ == '__main__':
    n = int(input())
    lst:list = list(map(int, input().split()))
    sortedList = sorted(set(lst))
    print(" ".join(str(solve(sortedList, k)) for k in lst))
