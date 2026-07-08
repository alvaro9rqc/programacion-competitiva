# Graphs
## Trees
- juegos/batallas en árboles
  - rootear.
  - si no puedes usar adyacentes, entonces habrá long (n) alternativas.
# STD

- sqrt con round funciona bien hasta $10^6$

# Combinatoria

- b bolsas y k espacios: combinaciones
  - Es como un dp, por cada nueva bolsa, le multiplicas la cantidad de
    combinaciones con 3 bolsas, con 2 etc. Y el resultado lo sumas al global:
    ```
    c1 = c2 = c3 = 0
    for b in bolsas:
      c1+=b
      c2+=b*c1 // comb de esa con dos bolsas
      c3+=b*c2 // comb con tres bolsas
    ```
  - esto es polinómios simétricos elementales
  - número de caminos de long k que pasan por un nodo
  - Encontrar el nodo que minimiza la suma de distancias a otros 3 nodos.
  - Juegos de persecución en árboles (Alice y Bob en grafos).
