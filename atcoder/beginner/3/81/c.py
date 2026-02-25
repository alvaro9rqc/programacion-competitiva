n = int(input())
s = input()
idx = [0]+[ i for i in range(1,n) if s[i] != s[i-1] ]+[n]
blocks = [ s[ idx[i-1]:idx[i] ] for i in range(1,len(idx)) ]
#print(blocks)
p = [ i for i in range(1,len(blocks)-1) if len(blocks[i]) == 1 and blocks[i][0]=='/' ]
#print(p)
if len(p)==0:
    print(1)
else:
    m = [ (len(blocks[i-1]), len(blocks[i+1])) for i in p if ( blocks[i-1][0]=='1' and blocks[i+1][0]=='2' ) ]
    #print(m)
    if len(m)==0: print(1)
    else:
        ans = max( [ min(t) for t in m ] )
        print(2*ans + 1)
