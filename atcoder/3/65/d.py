n = int(input())
s = input()
l = ' '
win = {
        "S":"R",
        "R":"P",
        "P":"S",
        }
ans = 0
stk = [' ', ' ', ' ']
for i, m in enumerate(s):
    if win[m] !=l: 
        ans += 1
        l = win[m]
    else:
        if m != stk[-1] and m != stk[1]:
            l = win[m]
            ans += 1
            #print("->", *stk)
            #print(i)
        else: l = m
    if m != stk[-1]:
        stk.pop(0)
        stk.append(m)
print(ans)
