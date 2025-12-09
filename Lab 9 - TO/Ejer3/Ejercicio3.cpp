#include <iostream>
using namespace std;

class ConexionBD {
private:
    static ConexionBD* instancia;
    bool conectado;

    ConexionBD() : conectado(false) {} // Constructor privado

public:
    static ConexionBD* getInstancia() {
        if (instancia == nullptr) instancia = new ConexionBD();
        return instancia;
    }

    void conectar() {
        if (!conectado) {
            conectado = true;
            cout << "Conexion a la BD establecida." << endl;
        } else {
            cout << "Ya existe una conexion activa." << endl;
        }
    }

    void desconectar() {
        if (conectado) {
            conectado = false;
            cout << "Conexion cerrada correctamente." << endl;
        } else {
            cout << "No hay conexion que cerrar." << endl;
        }
    }

    void estado() {
        cout << (conectado ? "BD conectada" : "BD desconectada") << endl;
    }
};

ConexionBD* ConexionBD::instancia = nullptr;

//---------- MAIN ----------
int main() {
    ConexionBD* c1 = ConexionBD::getInstancia();
    c1->conectar();
    c1->estado();

    ConexionBD* c2 = ConexionBD::getInstancia(); // Mismo objeto
    c2->estado();
    c2->desconectar();

    return 0;
}
