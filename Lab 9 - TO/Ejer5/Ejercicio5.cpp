#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>
#include <thread>
using namespace std;

class Logger {
private:
    static Logger* instancia;
    static mutex mtx;            // Protege el acceso en multihilos
    string archivo;

    Logger(string nombre) : archivo(nombre) {} // Constructor privado

public:
    static Logger* getInstancia(string nombre = "bitacora.log") {
        if (instancia == nullptr) {           // Primera comprobación (rápida)
            lock_guard<mutex> lock(mtx);      // Bloqueo para hilos
            if (instancia == nullptr) {       // Doble verificación
                instancia = new Logger(nombre);
            }
        }
        return instancia;
    }

    void log(string mensaje) {
        lock_guard<mutex> lock(mtx); // Control de escritura concurrente

        ofstream file(archivo, ios::app);
        time_t now = time(nullptr);
        file << "[" << ctime(&now) << "] " << mensaje << endl;
    }
};

Logger* Logger::instancia = nullptr;
mutex Logger::mtx;

// ---------- MAIN ----------
void tarea(string usuario) {
    Logger::getInstancia()->log("Acceso concurrente desde -> " + usuario);
}

int main() {
    thread t1(tarea, "Hilo 1");
    thread t2(tarea, "Hilo 2");
    thread t3(tarea, "Hilo 3");

    t1.join();
    t2.join();
    t3.join();

    cout << "Registro completado en bitacora.log (Thread-Safe)" << endl;
    return 0;
}