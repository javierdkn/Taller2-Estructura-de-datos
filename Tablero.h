#ifndef TABLERO_H
#define TABLERO_H


class Tablero {

private:
    char tabla[3][3]; // Tablero de juego
    int espaciosLibres; // Espacios disponibles en el tablero
    char letraJugador; // Ficha del jugador
    char letraCPU; // Ficha de la CPU

    bool estadoTerminal();
    bool fueraDeRango(int fila, int columna);
    int minimax(bool turnoCPU);

public:
    Tablero();
    void mostrarTabla();
    void insertarFichaHumano();
    void insertarFichaCPU();
    void elegirFicha(char jugadorFicha);
};

#endif