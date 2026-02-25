N = int(input())
A = list(map(int,input().split()))
#print(*A)
mid = N//2 + ( N&1 )
#print("m", mid)
low = 0
up = mid
ans = 0
while(low < mid and up < N):
    #print(A[low], A[up])
    if A[low] <= A[up]//2: 
        up+=1
        low+=1
        ans +=1
    else: 
        up+=1
print(ans)
