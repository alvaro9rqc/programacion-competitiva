T = int (input())
for _ in range(T):
    n = int(input())
    a = list( map(int, input().split()) )
    b = list( map(int, input().split()) )
    neg = 0
    d = 0
    mi = 1000000000
    for i in range(n):
        t = a[i] - b[i]
        if (t >= 0): mi = min(mi, t)
        else:
            d = t 
            neg += 1
    if neg == 0:
        print("yes")
    elif neg == 1:
        d = abs(d)
        if mi >= d: print("yes")
        else: print("no")
    else: print("no")
        

