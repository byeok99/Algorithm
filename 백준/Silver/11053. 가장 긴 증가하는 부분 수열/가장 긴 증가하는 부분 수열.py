def go(lst):
    d = [0] * len(lst)

    for i in range(len(lst)):
        d[i] = 1
        for j in range(i):
            if lst[j] < lst[i] and d[j]+1 > d[i]:
                d[i] = d[j] + 1
    return max(d)

if __name__ == '__main__':
    n = int(input())
    lst = list(map(int, input().split()))
    
    print(go(lst))