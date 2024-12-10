# Taller2-Estructura-de-datos


Javier Andrés Dinamarca Fredes, RUT: 21.416.181-8, correo institucional: javier.dinamarca@alumnos.ucn.cl

Ejecución del código: g++ Tablero.cpp main.cpp -o Main

Una vez compilado:./Main.exe
 

¿Qué es el Algoritmo Minimax?
El algoritmo Minimax es una estrategia de decisión utilizada principalmente en juegos de dos jugadores con información perfecta, como el ajedrez o el tres en raya. Su objetivo es encontrar el mejor movimiento posible para el jugador que lo utiliza, asumiendo que el oponente también jugará de manera óptima.

La idea central:

-Minimizar la máxima pérdida: El algoritmo busca minimizar la pérdida máxima que puede sufrir el jugador, suponiendo que el oponente siempre elegirá la opción que más le perjudique.

-Maximizar la ganancia mínima: De manera equivalente, se puede interpretar como maximizar la ganancia mínima que el jugador puede obtener, independientemente de las acciones del oponente.

-Árbol de juego: El algoritmo construye un árbol donde cada nodo representa un posible estado del juego y cada rama representa un movimiento. Las hojas del árbol corresponden a estados finales del juego.

- Búsqueda α-β busca primero en profundidad
- La poda α-β se basa en la idea de disponer de dos valores que conforman una ventana a la cual deben pertenecer  - los valores de f(n) para que sean considerados
- En los nodos MAX se utiliza el parámetro α que determina el máximo de los valores de los  nodos sucesores encontrados hasta el momento
- En los nodos MIN se utiliza el parámetro β que va a ser, en cada momento, el mínimo de los valores encontrados. 

-REGLAS DE FINALIZACIÓN 
-En los nodos MAX la condición de poda es αp ≥βp-1 
(Se puede podar por debajo de un nodo MAX si su valor alfa es mayor o igual que al menos un beta antecesor) 

-En los nodos MIN la condición de poda es βp ≤αp-1 
(Se puede podar por debajo de un nodo MIN si su valor beta es menor o igual que al menos un alfa antecesor) 

PROCEDIMIENTO 

1º Descender primero en profundidad hasta la profundidad total del ply 
2º Aplicar la evaluación heurística a un nodo y a todos sus hermanos 
3º Asignar valores al padre: el valor se oferta al abuelo como valor potencial 
4º Descender a otro nieto y terminar la exploración del padre si alguno de sus valores cumple el criterio de parada