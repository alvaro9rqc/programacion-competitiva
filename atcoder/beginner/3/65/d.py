N = int(input())
S = input()

memo = {
        'R': [-2]*N,
        'S': [-2]*N,
        'P': [-2]*N
        }
win = { 
       'R':'S',
       'P':'R',
       'S':'P'
       }

def f(c1,c2):
    if c1==c2: return 0
    elif win[c1]==c2: return 1
    else: return -1

memo['R'][0]=f('R',S[0])
memo['S'][0]=f('S',S[0])
memo['P'][0]=f('P',S[0])

for i in range(1, N) :
    c =win[S[i]]
    if c != 'R': memo['R'][i] = f( 'R',S[i] ) + max( memo['P'][i-1], memo['S'][i-1] )
    if c != 'S': memo['S'][i] = f( 'S',S[i] ) + max( memo['P'][i-1], memo['R'][i-1] )
    if c != 'P': memo['P'][i] = f( 'P',S[i] ) + max( memo['R'][i-1], memo['S'][i-1] )

print( max(memo['R'][-1], memo['S'][-1], memo['P'][-1]) )
