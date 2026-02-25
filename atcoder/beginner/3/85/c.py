N = int(input())
H = list( map(int, input().split()) )
ans = 1
for i in range(1,N):
    #print("-> ",i)
    for j in range(i):
        k = j
        lt = H[k]
        lan = 0
        while k < N:
            #print(": ",k)
            if H[k] == lt: lan += 1
            else: 
                lt = H[k]
                ans = max (ans, lan)
                lan = 1
            k += i
        ans = max(lan, ans)
print(ans)
