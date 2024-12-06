#ifndef TABLERO_H
#define TABLERO_H


class Tablero {
private:
    char tablero[3][3];

public:
    Tablero();
    void mostrarTablero();
    bool colocar(int fila, int columna, char simbolo);
    bool verificarGanador();

};

#endif 