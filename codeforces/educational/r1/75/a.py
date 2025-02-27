T = int(input())
for _ in range(T):
    n = int(input())
    if (n == 0): print(1)
    else: 
        ans = n // 15
        ans = ans*3
        ans += min( (n % 15 +1), 3 )
        print(ans)
        
