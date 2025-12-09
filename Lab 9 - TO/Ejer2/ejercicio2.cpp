#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Logger {
private:
    static Logger* instancia;
    string archivo;

    Logger(string nombre) : archivo(nombre) {}

public:
    static Logger* getInstancia(string nombre = "bitacora.log") {
        if (instancia == nullptr) {
            instancia = new Logger(nombre);
        }
        return instancia;
    }

    void log(string mensaje) {
        ofstream file(archivo, ios::app);
        time_t now = time(nullptr);
        file << "[" << ctime(&now) << "] " << mensaje << endl;
    }
};

Logger* Logger::instancia = nullptr;

// ----------- MAIN -------------
int main() {
    Logger* log1 = Logger::getInstancia();
    Logger* log2 = Logger::getInstancia();

    log1->log("Inicio del programa");
    log2->log("Usuario autenticado");
    log1->log("Sistema finalizado");

    cout << (log1 == log2) << endl;

    return 0;
}
