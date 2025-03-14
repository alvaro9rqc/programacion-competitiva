T=int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    d = {}
    for e in a:
        if e in d: d[e] += 1
        else: d[e] = 1
    al = 0
    ar = -1
    l = -1
    for i in range(n):
        if d[a[i]] == 1:
            if l == -1:
                l = i
            if i - l > ar - al:
                ar = i
                al = l
        else: l = -1
    if ar == -1: print(0)
    else: print(al+1,ar+1)
