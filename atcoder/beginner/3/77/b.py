t = [' ']*8
for i in range(8): t[i] = input()

oc = [False] * 8
sinr = []

for i in range(8):
    h = False
    for j in range(8):
        if (t[i][j] == '#'):
            h = True
            oc[j] = True
    if (not h): sinr.append(i)

ans = 0
for r in sinr:
    for c in range(8):
        if (not oc[c]): ans +=1

print(ans)
