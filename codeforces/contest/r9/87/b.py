for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    f = True
    for i in range(n):
        f2 = False
        for j in range(max(0, i-1), min(n, i+2)):
            if a[j] == i+1: f2 = True
        if not f2: 
            f = False
            break
    if f: print("yes")
    else: print("no")
            


