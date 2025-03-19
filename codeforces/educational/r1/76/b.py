for test in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    #print(*a)
    if (k == n): print(sum(a))
    else:print(sum( a[n-k-1:] ))
