T = int(input())
for _ in range(T):
    n,x,k = map(int,input().split())
    s = input()
    m = k % n
    c = 0
    ex = 0
    for i in range(n):
        if s[i] == "L": x-=1
        else: x+=1
        if i <= m:
            if x == 0:
                ex += 1
                c = ex
        else:
            if x == 0:
                c += 1
    print(ex + (k // n) * c)



