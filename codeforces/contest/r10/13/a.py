for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    m = {
            0:3,
            1:1,
            3:1,
            2:2,
            5:1,
            }
    ans =0
    for i in range(n):
        e = a[i]
        if e in m:
            m[e]-=1
            if m[e]==0:m.pop(e)
        if len(m)==0:
            ans=i+1
            break
    print(ans)
