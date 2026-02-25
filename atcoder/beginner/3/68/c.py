n = input()
a = map(int, input().split())
t = 0
for i in a:
    x = i // 5
    i %= 5
    t += x*3
    while (i > 0):
        t+=1
        if (t%3 == 0): i -= 3
        else: i -= 1
print(t)
