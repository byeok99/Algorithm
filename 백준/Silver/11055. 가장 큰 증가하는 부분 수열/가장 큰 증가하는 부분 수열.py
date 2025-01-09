def go(lst):
    d = [0] * len(lst)

    for i in range(len(lst)):
        d[i] = lst[i]
        for j in range(i):
            if lst[j] < lst[i] and d[j] + lst[i] > d[i]:
                d[i] = d[j] + lst[i]

    return max(d)

if __name__ == "__main__":
    # lst = [1,100,2,50,60,3,5,6,7,8]
    n = int(input())
    lst = list(map(int, input().split()))
    print(go(lst))
