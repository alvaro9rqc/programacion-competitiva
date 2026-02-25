sc = list(map(int, input().split()))
c = "ABCDE"
i = 1
ans = []
while(i <= (1 << 5)):
    s = 0
    n = []
    for j in range ( 5 ):
        if (i & (1 << j) != 0): 
            s += sc[j]
            n.append(c[j])
    ans.append([s, "".join(n)])
    i += 1
ans.sort(key=lambda x: (-x[0], x[1]))
for x in ans:
    print(x[1])
