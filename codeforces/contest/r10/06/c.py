T = int(input())
for _ in range(T):
    n,x = map(int,input().split())
    idx = 0
    while (x & (1<<( idx )) != 0): idx += 1
    el = 0
    ans = []
    for _ in range(n):
        if el < (1 << idx):
            ans.append(el)
            el += 1
        else: 
            ans.append(x)
    #ans[-1]=x
    deb = 0
    for i in ans:
        deb |= i
    if (deb != x):ans[-1]=x
    print(*ans)


