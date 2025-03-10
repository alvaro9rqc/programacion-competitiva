T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    a = []
    if k % 2 == 0:
        a = [n-1]*n
        a[-2]=n
    else: 
        a = [n]*n
        a[-1]=n-1
    print(*a)


