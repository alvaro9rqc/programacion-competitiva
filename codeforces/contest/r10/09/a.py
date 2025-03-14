T = int(input())
for _ in range(T):
    l,r,d,u = map(int,input().split())
    #l = -l
    #d = -d
    if (l == r and r == d and d == u): print("Yes")
    else: print("No")
