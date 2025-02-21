N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(27):
    s = 0
    ones = 0
    zeros = 0
    for j in range(1, N):
        if( A[j] & (1<<i) != 0 ): 
            ones, zeros = zeros, ones
        if (A[j] & (1<<i) ) ^ (A[j-1] & (1<<i)) == 0: zeros+=1
        else: ones+=1
        s+=ones

    ans += s * (1<<i)
    #print("->",s)
print(ans)
