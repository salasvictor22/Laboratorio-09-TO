#include <iostream>
using namespace std;

class Configuracion {
private:
    static Configuracion* instancia;
    string idioma;
    string zonaHoraria;

    Configuracion(string id, string zona) : idioma(id), zonaHoraria(zona) {} // Constructor privado

public:
    static Configuracion* getInstancia(string id = "ES", string zona = "GMT-5") {
        if (instancia == nullptr) {
            instancia = new Configuracion(id, zona);
        }
        return instancia;
    }

    void mostrarConfiguracion() {
        cout << "Idioma: " << idioma << ", Zona horaria: " << zonaHoraria << endl;
    }
};

Configuracion* Configuracion::instancia = nullptr;

// ----------- MAIN -------------
int main() {
    Configuracion* c1 = Configuracion::getInstancia("ES", "GMT-5");
    Configuracion* c2 = Configuracion::getInstancia("EN", "UTC");

    c1->mostrarConfiguracion();
    c2->mostrarConfiguracion();

    cout << (c1 == c2) << endl; // Ambas referencias son iguales

    return 0;
}
