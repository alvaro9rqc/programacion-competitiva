for _ in range(int(input())):
    n = int(input())
    ans =[]
    for i in range(61,-1,-1):
        if n & (1<<i) != 0:
            a = n ^ (1<<i)
            if a > 0: ans.append(a)
    ans.append(n)
    print(len(ans))
    print(*ans)
