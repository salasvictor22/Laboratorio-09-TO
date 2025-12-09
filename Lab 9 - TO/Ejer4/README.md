# Ejercicio 04 — Singleton de Control de Juego

Este ejercicio aplica el patrón **Singleton** para gestionar el estado global de un juego (puntaje, vidas, nivel) desde un único controlador centralizado.

## Cómo funciona

El diseño de la clase asegura que todo el juego se administre desde un solo punto:

- **Puntero estático (`instancia`):** Se utiliza para almacenar el único controlador del juego existente.
- **Constructor privado:** Define el estado inicial del juego (vidas, nivel, puntaje) y evita la creación externa de objetos.
- **Método `getInstancia()`:** Garantiza que solo exista un objeto `ControlJuego`:
  - Crea el primer objeto si este aún no existe.
  - Devuelve siempre la misma referencia si ya fue creada anteriormente.

### Métodos del sistema

- **`sumarPuntaje()`**: Aumenta el acumulador del puntaje global.
- **`perderVida()`**: Reduce el contador de vidas únicamente si aún quedan disponibles.
- **`pasarNivel()`**: Avanza el nivel actual del juego.
- **`mostrarEstado()`**: Imprime en consola el estado actual compartido (vidas, puntaje y nivel).

## Funcionamiento en main()

La simulación en el programa principal demuestra cómo diferentes actores interactúan con el mismo estado:

1. Las variables `jugador`, `enemigo` e `interfaz` obtienen la **misma instancia** mediante `getInstancia()`.
2. Cada uno de estos actores modifica el estado global del juego (el jugador suma puntos, el enemigo quita vidas, etc.).
3. **Estado compartido:** Todos los cambios son visibles entre sí inmediatamente, confirmando que comparten la misma instancia Singleton.