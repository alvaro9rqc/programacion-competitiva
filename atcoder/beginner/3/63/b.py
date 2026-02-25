N, T, P = map(int, input().split())
L = list(map(int, input().split()))
L.sort()
ans = T - L[N-P]
if ans < 0: print(0)
else:print(ans)
