d = {}
n= int(input())
a = list(map(int, input().split()))
ans = n+2
for i in range(n):
    if a[i] in d:
        if i - d[ a[i] ] < ans:
            ans = i - d[ a[i] ]
    d[ a[i] ]=i
if ans == n+2:print(-1)
else: print(ans+1)
