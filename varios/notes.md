por ejemplo, la combinaicón de los platos, par hallar el precio, será una solución greedy.
**cositas**
no sería necesario comparar los platos con el que es el más grande, puesto que ya se comparó.
**procedimiento**
1. se oderna de mayor a menor
2. Se crea un set: main dishes. S = {1, 2, ...};
2. Se actualiza precio:
  a. plato principal no rstringido+
  b. no se calculo con ese plato previamente
Complejidad: O(n + m + l)


**su código**:
hace la entrada de n, m, l
array a: precio de plato principal
b: platos complementarios
bsort: ordenamde mayor a menor y su posición /es un hash.

bads: para insertar los pares malos
mainDishes: 
