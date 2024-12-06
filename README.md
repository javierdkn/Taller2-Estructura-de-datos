# Taller2-Estructura-de-datos


Javier Andrés Dinamarca Fredes, RUT: 21.416.181-8, correo institucional: javier.dinamarca@alumnos.ucn.cl

Ejecución del código: 

Una vez compilado: 

¿Qué es el Algoritmo Minimax?
El algoritmo Minimax es una estrategia de decisión utilizada principalmente en juegos de dos jugadores con información perfecta, como el ajedrez o el tres en raya. Su objetivo es encontrar el mejor movimiento posible para el jugador que lo utiliza, asumiendo que el oponente también jugará de manera óptima.

La idea central:

-Minimizar la máxima pérdida: El algoritmo busca minimizar la pérdida máxima que puede sufrir el jugador, suponiendo que el oponente siempre elegirá la opción que más le perjudique.

-Maximizar la ganancia mínima: De manera equivalente, se puede interpretar como maximizar la ganancia mínima que el jugador puede obtener, independientemente de las acciones del oponente.

-Árbol de juego: El algoritmo construye un árbol donde cada nodo representa un posible estado del juego y cada rama representa un movimiento. Las hojas del árbol corresponden a estados finales del juego.