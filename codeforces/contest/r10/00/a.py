T = int(input())
for _ in range(T):
    a,b= map(int,input().split())
    if a == 1 and b == 1: print(1)
    else:
        print(b - a)
