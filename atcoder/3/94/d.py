import sys
st = []
s = input()
close = {
      ")" : "(",
      "]" : "[",
      ">" : "<",
        }
for c in s:
    if c in close:
        if len(st) == 0 or st.pop()!= close[c]: 
            print("No")
            sys.exit()
    else: st.append(c)
if(len(st) == 0): print("Yes")
else: print("No")
