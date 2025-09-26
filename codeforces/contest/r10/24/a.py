def f(a):
    ans = 0
    n   = len(a)
    for top in range(n):
        for bottom in range(top, n):
            for left   in range(n):
                for right  in range(left, n):
                    # marcamos qué valores aparecen en la subgrilla [top..bottom]×[left..right]
                    present = [False] * (n*n + 1)  # uno extra para el caso “todos”
                    for r in range(top,    bottom + 1):
                        for c in range(left, right  + 1):
                            present[a[r][c]] = True
                    # buscamos MEX en 0..n*n
                    for k in range(n*n + 1):
                        if not present[k]:
                            ans += k
                            break
    return ans


# Prueba
a = [
    [8, 4,5],
    [6,0,1],
    [7,2,3]
]
a = [
        [6,7,8],
        [5,0,1],
        [4,3,2],
        ]
print(f(a))   # → 8

