import math
for _ in range(int(input())):
    n,m,k = map(int,input().split())
    c_d = math.ceil(k / n)
    mid = math.ceil(m / 2)
    if c_d <= mid:
        print(1)
    else:
        if c_d == m:print(m)
        else:
            g = ( m - c_d + 1 )
            ans = math.ceil( c_d /g  )
            if g * ans > m: ans-=1
            print(ans)
        #elif m % 2 != 1:print(c_d-mid+1)
        #else: 
            #d = math.ceil( (c_d-mid)/2+q )
        #print( math.ceil( m / (m-c_d+1) ) )
