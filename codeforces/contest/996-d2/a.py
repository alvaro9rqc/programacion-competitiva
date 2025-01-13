T = int(input())
for _ in range(T):
    n,a,b= map(int, input().split())
    d = abs(a-b)-1
    if d & 1 == 1: print("yes")
    else: print("no")
