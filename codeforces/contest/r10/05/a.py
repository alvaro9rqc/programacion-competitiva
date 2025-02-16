t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans = sum([ 1 for i in range(1,n) if s[i-1] != s[i] ])
    if s[0] == '1': ans+=1
    print(ans)
