T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    a = list( map(int, input().split()) )
    b = k+1
    if k == n:
        f = True
        for i in range(1, n, 2):
            if a[i] != (i // 2 + 1): 
                print(i // 2 + 1)
                f = False
                break
        if f:
            print(k // 2 + 1)
    else:
        f = True
        for i in range(n -k +1):
            idx = 1 + i
            if a[idx] != 1:
                f = False
                print(1)
                break
        if f: print(2)
