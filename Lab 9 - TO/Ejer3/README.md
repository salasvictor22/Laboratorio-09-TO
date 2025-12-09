# Ejercicio 03 — Singleton de Conexión a Base de Datos

Este ejercicio simula una conexión a una base de datos utilizando el patrón **Singleton** para garantizar que solo exista una conexión activa en toda la aplicación.

## Cómo funciona

La clase asegura el control de la conexión mediante los siguientes elementos:

- **Puntero estático (`instancia`):** Se utiliza para almacenar la referencia de la única conexión permitida.
- **Constructor privado:** Impide la creación de objetos directamente fuera de la clase.
- **Método `getInstancia()`:** Verifica el estado del puntero:
  - Si *no existe*, crea la primera y única instancia.
  - Si *ya existe*, devuelve la misma referencia sin generar una nueva.

### Métodos principales

- **`conectar()`**: Activa la conexión únicamente si esta no existía previamente.
- **`desconectar()`**: Cierra la conexión solo si hay una activa actualmente.
- **`estado()`**: Muestra en consola si la base de datos se encuentra conectada o desconectada.

## Funcionamiento en main()

El flujo de ejecución demuestra el comportamiento del patrón:

1. La variable `c1` obtiene la instancia a través de `getInstancia()` y establece la conexión.
2. La variable `c2` solicita otra conexión, pero recibe la **misma instancia** que `c1`.
3. **Estado compartido:** Dado que `c1` y `c2` comparten el mismo objeto, la conexión solo se abre y se cierra una vez en todo el ciclo de vida del programa.