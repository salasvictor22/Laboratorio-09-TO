#include <iostream>
using namespace std;

class ControlJuego {
private:
    static ControlJuego* instancia;
    int nivel;
    int puntaje;
    int vidas;

    ControlJuego() : nivel(1), puntaje(0), vidas(3) {} // Estado inicial

public:
    static ControlJuego* getInstancia() {
        if (instancia == nullptr) instancia = new ControlJuego();
        return instancia;
    }

    void sumarPuntaje(int p) { puntaje += p; }
    void perderVida() { if (vidas > 0) vidas--; }
    void pasarNivel() { nivel++; }

    void mostrarEstado() {
        cout << "Nivel: " << nivel << " | Puntaje: " << puntaje << " | Vidas: " << vidas << endl;
    }
};

ControlJuego* ControlJuego::instancia = nullptr;

//---------- MAIN ----------
int main() {
    ControlJuego* jugador = ControlJuego::getInstancia();
    jugador->sumarPuntaje(150);
    jugador->mostrarEstado();

    ControlJuego* enemigo = ControlJuego::getInstancia();
    enemigo->perderVida();
    enemigo->mostrarEstado();

    ControlJuego* interfaz = ControlJuego::getInstancia();
    interfaz->pasarNivel();
    interfaz->mostrarEstado();

    return 0;
}
