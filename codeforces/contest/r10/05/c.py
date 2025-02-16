T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    r, l = n-1, 0
    ans = 0
    while r >= 0 and (a[r] < 0): 
        ans -= a[r]
        r-=1
    while l < n and a[l] > 0: 
        ans += a[l]
        l+=1
    delta = 0
    if l < r:
        sumpos = ([0]* (r+1 -l))
        #print(*sumpos)
        for i in range(l+1, r+1):
            #print(": ", i, l, r)
            sumpos[i-l] += sumpos[i-l-1]
            if a[i] > 0: sumpos[i-l] += a[i]
        sumneg =0
        #print("->", *sumpos)
        for i in range(r, l-1,-1):
            if a[i] < 0: sumneg -= a[i]
            #print("->", sumpos[i-l], sumneg)
            delta = max(sumpos[i-l] + sumneg, delta)
    print(ans + delta)
        
