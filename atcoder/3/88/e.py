N = int(input())
A = list(map(int, input().split()))
used = [False]*N
i = N-2
j = N-1
ans = 0
while i >= 0:
    if used[j]: j-=1
    elif used[i] or not(i < j): i-=1
    elif A[i] <= A[j]//2:
        used[i]=True
        used[j]=True
        i-=1
        j-=1
        ans +=1
    else: i-=1
print (ans)
