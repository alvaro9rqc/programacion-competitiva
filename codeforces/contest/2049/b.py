T = int(input())
for _ in range(T):
    n = int(input())
    p = s = -1
    A = input()
    for i in range(n):
        if p == -1 and A[i]=='p': p=i
        if A[i] == 's': s = i
    if p == -1 or s == -1 or p == n-1 or s == 0: print("yes")
    else: print("no")
