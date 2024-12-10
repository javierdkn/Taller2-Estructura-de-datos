#ifndef TABLERO_H
#define TABLERO_H


class Tablero {

private:
    char tabla[3][3]; 
    int espaciosLibres,alfa,beta; 
    char letraJugador; 
    char letraCPU; 

    bool estadoTerminal();
    bool fueraDeRango(int fila, int columna);
    int minimax(bool turnoCPU, int alfa, int beta);

public:
    Tablero();
    void mostrarTabla();
    void insertarFichaHumano();
    void insertarFichaCPU();
    void elegirFicha(char jugadorFicha);
    void reiniciarTablero();
    char getLetraJugador();

};

#endif