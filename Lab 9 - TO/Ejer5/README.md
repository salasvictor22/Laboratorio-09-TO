# Ejercicio 05 — Singleton Thread-Safe (Concurrente)

Este ejercicio implementa una versión avanzada del patrón **Singleton** diseñada para funcionar correctamente en entornos multi-hilo, utilizando **Mutex** para garantizar la seguridad de los hilos (*thread-safety*).

## Cómo funciona

Para evitar condiciones de carrera (*race conditions*), la clase implementa los siguientes mecanismos de sincronización:

- **Mutex (`mtx`):** Se utiliza para bloquear el acceso a recursos compartidos y evitar que dos hilos ejecuten secciones críticas simultáneamente.
- **Patrón *Double-Checked Locking* en `getInstancia()`:**
  1. **Primera verificación:** Comprueba si `instancia == nullptr` (rápido, sin bloqueo).
  2. **Bloqueo:** Si parece que no existe, bloquea el proceso con el `mutex`.
  3. **Segunda verificación:** Vuelve a comprobar si es `nullptr` (esta vez dentro del bloqueo) por seguridad.
  4. **Creación:** Solo un hilo logra crear el Singleton, garantizando la unicidad.

### Método `log()` seguro
El método de registro también utiliza el `mutex` para proteger la escritura en el archivo. Esto evita colisiones (que dos hilos escriban a la vez) y asegura que los mensajes no se corrompan.

## Funcionamiento en main()

La simulación de concurrencia se realiza de la siguiente manera:

1. Se lanzan **tres hilos** simultáneamente que intentan escribir en el log.
2. Todos los hilos solicitan y utilizan la **misma instancia thread-safe** del Logger.
3. **Resultado:** El archivo final muestra los mensajes generados en paralelo, pero escritos de forma secuencial y correcta, sin corrupción de datos.