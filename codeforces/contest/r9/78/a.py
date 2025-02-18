T = int(input())
for _ in range(T):
    n,r=map(int,input().split())
    a = list(map(int,input().split()))
    res = 0
    ans = 0
    for i in a:
        ans += i//2*2
        r-=i//2
        res += i&1
    if res > 0:
        if res > r:
            ans += 2*r - res
        else: ans += res
    print(ans)


