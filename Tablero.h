#ifndef TABLERO_H
#define TABLERO_H


class Tablero {

private:
    char tabla[3][3]; 
    int espaciosLibres; 
    char letraJugador; 
    char letraCPU; 

    bool estadoTerminal();
    bool fueraDeRango(int fila, int columna);
    int minimax(bool turnoCPU);

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