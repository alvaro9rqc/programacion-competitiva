N = int(input())
stack = []
H = list(map(int,input().split()))
ans = [0] * N
stack.append(0)
for i in range(N-1, 0, -1):
    while ( not len( stack ) == 0 ) and H[i] > stack[-1]: stack.pop()
    stack.append(H[i])
    ans[i-1] = len(stack)
print(*ans)

