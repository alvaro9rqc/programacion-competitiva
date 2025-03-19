for test in range(int(input())):
    n,k = map(int,input().split())
    ans = 0
    if n % 2 == 1: 
        n -= k
        ans+=1
    ans += n // (k-1)
    if n % (k-1) != 0: ans +=1
    print(ans)
