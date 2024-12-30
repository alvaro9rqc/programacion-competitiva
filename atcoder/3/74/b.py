a = input()
b = input()
if (len(a) > len(b)): a,b=b,a
i = -1
for i in range(len(a)):
    if (b[i] != a[i]):
        break
if (a[i] == b[i]): i+=1
if(len(a) == len(b) == i): print(0)
else:print(i+1)
