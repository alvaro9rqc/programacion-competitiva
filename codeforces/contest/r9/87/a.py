for _ in range( int(input()) ):
    n = int(input())
    a = list(map(int, input().split()))
    v = []
    c = 1
    for i in range(1, n):
        if a[i]==a[i-1]:
            c+=1
        else:
            v.append(c);
            c = 1
    v.append(c)
    print(n - max(v))
