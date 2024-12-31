def solve(lst:list, start:int, end:int, value:int):
    if end < start: return False
    mid = (start + end) // 2
    if lst[mid] == value: return True
    elif lst[mid] > value: return solve(lst, start, mid-1, value)
    elif lst[mid] < value: return solve(lst, mid+1, end, value)

if __name__ == '__main__':
    a,b = map(int, input().split())
    a_, b_ = list(map(int, input().split())), list(map(int, input().split()))
    a_, b_ = sorted(a_), sorted(b_)
    rets = [k for k in a_ if not solve(b_, 0, len(b_)-1, k)]

    print(len(rets))
    print(*rets)