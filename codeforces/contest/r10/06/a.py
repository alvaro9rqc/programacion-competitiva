T = int(input())
for _ in range(T):
    n,k,p=map(int,input().split())
    k=abs(k)
    p=abs(p)
    c = k // p
    if (k % p != 0): c+=1
    if (c <= n): print(c)
    else: print(-1)
