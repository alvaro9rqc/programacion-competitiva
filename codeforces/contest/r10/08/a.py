T = int( input() )
for _ in range(T):
    n,x = map(int, input().split())
    a = list(map(int,input().split()))
    tsum = sum(a)
    if (tsum % n==0 and tsum / n == x): print("Yes")
    else: print("No")
