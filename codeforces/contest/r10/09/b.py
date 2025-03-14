T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    ans = a[0]
    for i in range(1, n):
        ans = ans + a[i]-1
    print(ans)

