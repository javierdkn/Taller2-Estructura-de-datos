#include <iostream>
#include <vector>

class Tablero {
private:
    char tablero[3][3];

public:
    Tablero();
    void mostrarTablero();
    bool colocar(int fila, int columna, char simbolo);
    char verificarGanador();

};