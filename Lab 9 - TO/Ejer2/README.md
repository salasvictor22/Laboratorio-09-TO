# Ejercicio 02 — Singleton de Logger

Este ejercicio implementa el patrón **Singleton** para gestionar un sistema de registro (Logger) único para toda la aplicación.

## Cómo funciona

La estructura de la clase garantiza la unicidad del objeto mediante los siguientes mecanismos:

- **Puntero estático (`instancia`):** Almacena la referencia del único objeto Logger existente.
- **Constructor privado:** Se declara privado para impedir que se instancien *loggers* adicionales manualmente.
- **Método `getInstancia()`:**
  - Crea el primer objeto si este aún no existe.
  - Si ya existe, devuelve la referencia al objeto creado previamente.

### El método `log()`
Este método es el encargado de registrar los eventos y realiza lo siguiente:
1. **Apertura:** Abre el archivo configurado (por defecto `bitacora.log`) en modo *añadir* (append).
2. **Tiempo:** Obtiene la fecha y hora actual del sistema.
3. **Escritura:** Escribe dentro del archivo el mensaje proporcionado junto a su marca temporal.

## Funcionamiento en main()

En el bloque principal del programa se demuestra el patrón de la siguiente manera:

1. Las variables `log1` y `log2` llaman al método `getInstancia()`, pero ambas reciben el **mismo objeto**.
2. Ambos punteros utilizan la misma instancia para escribir en el archivo, centralizando así la bitácora.
3. **Verificación:** La comparación `log1 == log2` confirma que solo existe un único Logger en todo el programa.