# Retroalimentación

## I. MENTALIDAD Y ESTRATEGIA DE CONTEST (Mindset & Strategy)

_El código se escribe en la mente y en el papel antes de tocar el teclado._

- **Simulación Real:** Trainea siempre con tiempos y cronómetro (en el celular,
  no en la PC). Si no lo logras en el tiempo, pierdes. Así se maneja el estrés:
  exponiéndote a él.

- **El Poder del Papel:** No uses el papel solo para conclusiones; úsalo para
  trazar rutas de ideas y evitar dar vueltas en círculos. Anota corolarios,
  esquematiza tu solución simple y plantea siempre cómo se vería la respuesta en
  la _mejor_ y en la _peor_ situación.

- **Gestión del Tiempo:** Si pasa más de una hora o una hora y media y estás
  atascado, libera tu cabeza. No te encapriches con una solución (ej. querer meter
  DP a la fuerza); ten la valentía de abortar y pensar en fuerza bruta o cambiar
  de enfoque.

- **Control Emocional:** El objetivo es dar lo mejor, no mantener una racha de
  rapidez. No te dejes llevar por el ruido de las demás posibilidades ni te pongas
  a dudar reflexivamente cambiando código a lo ciego. Medita, respira hondo y
  revisa estructuradamente.

- **Ceguera por Inatención y Cierre Cognitivo:** No asumas que la parte "fácil"
  de tu código está bien solo porque usa un patrón familiar. El cerebro apaga el
  análisis lógico ante lo conocido para ahorrar energía. Si hay un error, tu
  cerebro ignorará activamente esa sección. Mantén la guardia alta en las
  condiciones triviales.

- **Casos borde**: Está genial que durante la solución busques los casos bordes,
  pero te pasa regularmente que te distraen en vez de ayudarte, tal vez te
  puedes ayudar anotándolos en una parte del papel, pero la solución no debería
  concentrarse en ellos

## II. CATÁLOGO DE ERRORES FRECUENTES (Error & Debugging)

_Antes de enviar, revisa esta lista._

- **Lectura y Límites:** Revisa siempre los parámetros (ej. usar `1e10` cuando era `1e18`). Analiza con lupa los límites abiertos y cerrados, especialmente en geometría o rangos. ¡Y lee bien las variables del input (no confundas N con M)!
- **Tipos de Datos y Precisión:** \_ Los errores de precisión en `double` son letales (el error se calcula como error \* número de operaciones).
- Las raíces cuadradas y los negativos diminutos generan `NaN`. Usa `(unsigned long long) sqrt((long double) k)` o `sqrtl(n)`.
- Si tienes que calcular más que distancias enteras, usa estructuras `Point` y `long double`.
- **Ordenamiento (Sort):** El comparador de `sort` exige un "estrictamente menor". NUNCA uses `<=`, `>=`, o `==`. La transitividad estricta es obligatoria (`cmp(x,x)` debe dar `false`).
- **Grafos:** En Floyd-Warshall, el nodo intermedio (puente) debe ir en el bucle superior. En Bellman-Ford, ten cuidado con el infinito (`inf`); la relajación en ciclos negativos puede excederlo si no usas algo mayor que `longmax * n`.
- **Depuración (Debugging):**
  - Si sabes que el algoritmo base está bien pero te da RE, prueba con instancias grandes en local. Usa `asserts` para validar estados imposibles en el código que "casi nunca modificas". Si haces un cambio que lógicamente no altera el resultado, cámbialo igual para probar.

## III. PARADIGMAS Y TÉCNICAS (Approaches & Techniques)

_Cómo atacar el problema cuando no sabes por dónde empezar._

### Búsqueda y Optimización (BS, Two Pointers, Sliding Window)

- **Sliding Window:** Implica recalcular resultados en un rango con updates `O(1)`. No siempre se desplazan dos índices; a veces (como en anillos) precalculas y actualizas desplazando solo uno.
  - digamos, un problema de rangos, que se irán desplazando, te exige alguna igualdad, digamos que el rango de a y b sea igual, entonces, debes de hacer saltar esa restricción en pasos de tamaño k, que es equivalente a agrupar los índices en módulo k. _Tienes que formular una ecuación de transición_

- **Binary Search (BS):** Si necesitas contar pares o rangos que se intersectan y sientes que es `O(N^2)`, ordenar y usar BS (o `lower_bound`) baja la complejidad para contar rápido.
- **K-ésimo elemento:** Cuando te pidan "halla el k-ésimo elemento tal que...", evalúa si existe una función monótona para usar Binary Search.
- **Búsqueda Ternaria:** Mucho cuidado con los elementos adyacentes que son iguales, pueden arruinar la convexidad.
- **Maximizar con binary search**: Pues si te piden maximizar un elemento, puedes hallar una forma creativa, no de saber si el array puede tener **ese** elemento, sino un elemento mayor o igual, y eso es lo mejor, debes de hacer eso en O(n). usualmente reemplazar los valores por 1 y 0 funciona bien.

### Rangos, Existencia y Greedy

- **Problemas de Rangos:**

  - Definir un extremo estático (un `i` fijo) y buscar cómo calcular el `j` de
    forma rápida suele ser la clave. Observa siempre qué pasa si el rango es de
    tamaño 1 para entender el peor escenario de eliminación o alteración.

  - Caso mínimo: Si el problema te pide que algo se cumpla para todos los
    rangos, mira para los rangos de tamaño 2 y 3. Porque esos se podría propagar

  - invariante: si te dan la opción de hacer una operación que afecta un
    rango, a veces el resultado no depende de un `l` o `r` escogido, sino solo
    de cada `a_i`

  - hay pocos algoritmos para poder resolverlos: 
    - sliding window
    - prefix sums
    - kadane
    - segment tree/Fenwick (si hay consultas)
    - sparce table

- **Existencia:**
  - Si te piden un número mayor a cero que no comparta bits con otro, las
    potencias de 2 () son tu salvación. Modelar matemáticamente la condición de
    existencia es el primer paso antes de codear.

  - Si tienes varios casos, como que en un rango se ocupa tales elementos,
    trata de modelar en ecuaciones y le sacas módulo o truquito, a veces funciona.

- **Greedy Incremental:** Ordenar los elementos e iterar uno por uno validando
  la propiedad greedy (desde el más pequeño al más grande) o usar una acumulación
  de elementos para acercarse al óptimo.

### Operaciones e invariantes

- **Invariantes**: Ante problemas que piden hacer una operación cero o más veces, podrías pensar que tus estados dependen de varias variables, pero a veces puede que no, y solo sean pocos los que te interesen, y luego, necesites encontrar una forma de saltar lo que no te interesan

### Algoritmos Constructivos y Reducción (Constructives)

- Si te piden construir algo, digamos bajo una regla tal y condición tal, entonces:
  - Analiza como el valor puede variar según el tamaño de la secuencia, a lo mejor puedes usar eso a tu favor.
  - Evalua qué es necesario que se cumpla en cada transición
    - Para eso puedes evaluar la unidad o el par.

### Números Gigantes y Cadenas de Dígitos (String Math)

- Cuando el número es tan grande que te lo dan como un string de longitud `1e5` o `1e6`.\*
  - **El Colapso de la Suma (The Sum Collapse):** Un número de `1e5` dígitos es inmanejable matemáticamente, pero la suma de sus dígitos es diminuta (en el peor caso, puros nueves: `1e5 * 9 = 900,000`). Usa esta operación para colapsar la complejidad de `O(10^N)` a un rango donde puedas iterar con un simple `for`.
  - **Frecuencias sobre Permutaciones:** Si el problema te permite reordenar los dígitos, borrar caracteres, o la respuesta es independiente del orden, **destruye el string inmediatamente**. Conviértelo en un arreglo de frecuencias `vector<int> frec(10, 0)`. Pasas de procesar una cadena de tamaño `N` a manejar un arreglo constante de tamaño 10.
  - **Las Invariantes del 9 y el 3:** Reordenar los caracteres de un string gigante cambia su valor, pero **nunca** cambia la suma total de sus dígitos.
  - **Reglas de Construcción Greedy:** Si te piden armar el número más grande o más pequeño posible con los dígitos dados:
    - _Máximo:_ Ordena descendente (el mayor dígito posible siempre debe ir primero).
  - _Mínimo:_ Ordena ascendente, pero cuidado con el **Cero a la Izquierda**. Busca el primer dígito mayor a 0, colócalo en la posición más significativa, y luego pon todos los ceros inmediatamente después.

#### Bitwise

- Casi todos se resuelven con el bit más grande o con la longitud de la cadena
  (caso = o != len)

## IV. ALGORITMOS Y ESTRUCTURAS (Core Knowledge)

_Tu armería técnica._

### 1. Programación Dinámica (DP)

- **El Enfoque "Hacia Adelante":** A veces no vas de una cantidad a otra, sino que propones una cantidad y verificas si puedes llegar yendo de pequeño a grande (tipo Knapsack optimizado).
- **Exploración del Estado:** Al final, el DP es un DAG (Grafo Dirigido Acíclico). Si es iterativo, imagínalo como un BFS.
- **Permutaciones:** Imagínalas como líneas que suben y bajan. Quitar un elemento a una permutación te da otra, y reconstruirla toma `O(N)`.
- **DP con Bitmask:** Si buscas emparejar, no calcules los estados `O(N^2)` cruzando todos contra todos. Fija el óptimo del primer elemento disponible (`LSOne`) contra los demás; eso te lleva al mismo estado final.
- **Compresión y Conteo:** Para sumar combinaciones, la sumatoria suele ser "las maneras que hay de llegar al siguiente si realizo este evento". Si te piden cuántos subconjuntos cumplen algo (no solo el max/min), usa ideas de la mochila y compáralo dinámicamente con una constante global.
- **Juegos de fases vs. dp interactivo**: ten mucho cuidado con las desiciones estáticas, porque me pasó una vez que un jugador hacía algo y el otro tenía que reaccionar, pero justo esa desición era fija, o sea no podía alternar en fases y yo me equivoqué.

### 2. Estructuras de Datos Avanzadas

- **Segment Tree / Fenwick:** Si el DP tiene actualizaciones (updates)
  constantes sobre la marcha, necesitas un Segment Tree para guardar la
  información del DP. Recuerda que para que soporte información de rango, debes
  usar sus atributos de `lo` y `hi`.

- **Data Compression:** Comprime coordenadas si buscas alturas menores en
  arreglos gigantes. Ordenas, haces `lower_bound` y usas un Fenwick Max Tree o
  Segment Tree para actualizar el menor en ese rango.

- **Agrupación dispersa + búsqueda binaria**: En el problema _Red Light, Green
  Light (Hard version)_ te pedia hallar si a partir de un val_i había un val_j
  (con j>i) tal que sus valores fueran iguales, entonces, lo que se hizo fue
  agrudar los valores en un mapa de vectores, y en los vectores las posiciones
  donde aparecen, y para encontrar el elemento, solo bastaba con un 2 binary
  search.

### 3. Grafos y Flujos

- **Visión de Aristas:** Cambia el chip: en lugar de nodos, piensa en aristas.
  Si quieres visitar un nodo en un DFS/BFS, comprueba si la _arista_ está
  disponible y es válida, no solo si el nodo está sin visitar.

- **Grafos Clásicos:** Recuerda optimizar Prim con un vector de distancias.
  Valida siempre primero si el grafo de entrada es conexo o es un árbol.

- **Flujo Máximo:** Ten cuidado con los ciclos. Considera usar un `set` de
  aristas visitadas en lugar de vértices visitados para rastrear rutas. El flujo
  te responde a la pregunta de "¿cuánto puedes mandar de manera óptima?".

- **Binary Lifting:** Úsalo cuando te pregunten "cuenta el número de..." o para
  hallar en qué nodo terminas tras `N` pasos en tiempo `O(log N)` para cualquier
  nodo.

#### Árboles

- Topología de estrella: un árbol tiene un padre y k hijos, usa eso como
  estrategia para updates y conteo inteligente.

### 4. Matemáticas, Combinatoria y Bitwise

- **Combinatoria:** El orden de los objetos siempre importa, a menos que el problema indique explícitamente lo contrario.
- **Principio de Inclusión-Exclusión (PIE):** Si contar pares toma `O(N^2)`, usa la técnica de contribución contando uno a uno cuántos coinciden.
- **XOR y Bits:** El inverso del XOR es el mismo, su neutro es el 0, es conmutativo, asociativo y se puede anular. Para contar elementos del 1 al con cierto prefijo binario: si el prefijo es mayor, es 0; si no, es .
- La Regla del Todo o Nada: Si un problema describe un juego de dos jugadores con turnos alternos y los límites son astronómicos. ¡NO uses Minimax ni DP! El árbol de juego es demasiado grande. Hay un patrón matemático oculto.
- Estrellas y baras: puede usarse para $x1 + x2 + x3 = y$. Recuerda que teines que repartir las n+k-1 opciones en n espacios. Tambiés se parece a calcular número de paths o sumatorias
- Separación de Variables (Decoupling) y Expansión: Si en sumatorias anidadas tienes variables atascadas dentro de una operación que te fuerza a una complejidad de $O(N^2)$ (por ejemplo, una base elevada a una potencia como $(P_j - P_i)^K$), busca restricciones inusualmente pequeñas (como $K \le 10$). Usa expansión polinomial (ej. Teorema del Binomio) para romper la expresión en factores que se multiplican. Al separar las variables, puedes factorizar y sacar del bucle interno todo lo que dependa del índice externo. Esto transforma la sumatoria interna en un acumulador de estado en tiempo real, reduciendo la complejidad drásticamente a $O(N \cdot K)$.
- **Regla de la Inversión de Sospecha:** Ante un WA inexplicable, el principal sospechoso es tu bloque de código más simple. Duda primero de tus certezas más absolutas antes de cuestionar tu matemática compleja.
- **Pruebas de Escritorio Extremas (Edge Cases manuales):** Antes de buscar errores en tu lógica principal, evalúa a mano los casos más estúpidamente simples (ej. puros ceros, puros unos). Lee las restricciones del problema palabra por palabra mientras haces el caso a mano; el error suele ser una condición que olvidaste aplicar al caso base.
- **Debugging Aislado (Divide y Vencerás):** No leas todo el código de golpe para encontrar un error. Genera un caso de prueba que fuerce la ejecución exclusiva del bloque `if` y otro exclusivo para el `else`. Aisla qué rama está fallando antes de intentar arreglarla.

## V. TRUCOS DE LENGUAJE Y LIBRERÍAS (Language Arsenal)

- **C++:** \* `max_element(a.begin(), a.end())` devuelve un puntero al mayor. Útil y rápido.
- Cuidado con `accumulate`: El tipo de dato retornado depende del _tercer argumento_. Si pasas `0`, retorna entero de 32 bits y puede hacer overflow. Pasa `0LL`.
- Los punteros se pueden aplicar con `swap` moviendo la referencia. `*` tiene menor precedencia que `[]`.
- Lambda recursiva: requiere `-> type` y pasarse a sí misma como argumento.
- Eliminar iterador en set/map: `it = s.erase(it)`.
- usar `sort(all(x)); x.erase(unique(all(x)), x.end());` para tener un vector
  sin repetidas, usando set es mínimo 33% más lento

- **Python:**
- Tiene un límite de recursión por defecto muy bajo (1000). Modifica el `sys.setrecursionlimit` si harás un DFS profundo o te dará Runtime Error.
- Practicar cómo usar el módulo `heapq` para max-heaps (invirtiendo el signo de los valores) y lambdas en ordenamientos personalizados.

---

### ¿Cómo seguir desde aquí?

Tener este Grimoire ordenado es solo el primer paso. Para mantener la disciplina de un competidor de alto nivel, cada vez que termines un contest, no tires tus conclusiones al azar; ubica la lección en la categoría correspondiente de este documento.

¿Te gustaría que tomemos alguna de estas secciones, por ejemplo la de **Programación Dinámica** o **Binary Search**, y la expandamos con un formato de "checklist de ataque" que puedas leer en los primeros 5 minutos de un contest para estructurar tu mente?

¡Excelente iniciativa! Un buen "Grimorio" de programación competitiva es un documento vivo. Cada vez que un problema te vuela la cabeza o te hace tropezar, debe convertirse en una nueva regla para que tu "yo del futuro" no caiga en la misma trampa.

Basado en este problema y en los patrones clásicos de AtCoder y Codeforces para tratar con "números artificialmente grandes", he redactado esta nueva subsección manteniendo exactamente el formato, tono y estilo de tu guía.

Puedes copiarla y pegarla directamente en tu sección **IV. ALGORITMOS Y ESTRUCTURAS** o en la **III. PARADIGMAS Y TÉCNICAS**:
