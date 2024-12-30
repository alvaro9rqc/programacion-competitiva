s = input()
a = 0
ans = []
for c in s[1:]:
    if (c == "|"):
        ans.append(a)
        a=0
    else: a+=1
for x in ans: print(x,end=" ")
print()
