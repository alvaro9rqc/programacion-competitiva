N = int(input()) 
A = list( map(int, input().split()) )
D = [0]*N
c = 0
for i in range(N):
    c -= D[i]
    A[i] += c
    inc = min(A[i], N-1-i)
    A[i] -= inc
    if i + inc +1 < N: D[i+inc+1]+=1
    c+=1
print(*A)
