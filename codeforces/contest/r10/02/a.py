T = int(input())
for _ in range(T):
    N = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sa = set()
    sb = set()

    for i in a: sa.add(i)
    for i in b: sb.add(i)

    c = len(sa) * len(sb)
    if c >= 3: print("Yes")
    else: print("No")


