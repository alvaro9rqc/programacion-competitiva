s = input()

f = False
if len(s)%2==0:
    f = True
    con = set()
    for i in range(int( len(s)/2 )):
        #print(i)
        if s[2*i] in con or s[2*i] != s[i*2+1]:
            f = False
            break
        con.add(s[i*2])
if (f): print("Yes")
else: print("No")
