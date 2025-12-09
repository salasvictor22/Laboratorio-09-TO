# Ejercicio 01 — Singleton de Configuración

Este ejercicio implementa el patrón de diseño **Singleton** para manejar la configuración global de una aplicación.

## Funcionamiento del código

La lógica principal se basa en las siguientes reglas:

- **Atributo estático (`instancia`):** La clase utiliza un atributo estático que almacena el único objeto permitido del tipo `Configuracion`.
- **Constructor privado:** Se define como privado para impedir que se creen objetos desde fuera de la clase utilizando el operador `new`.
- **Método `getInstancia()`:** Es la función encargada de controlar la creación del objeto:
  - Si `instancia` es `nullptr`, se crea una nueva instancia con el idioma y zona horaria inicial.
  - Si la instancia ya existe, simplemente se devuelve la misma sin crear una nueva.
- **Método `mostrarConfiguracion()`:** Imprime el idioma y la zona horaria almacenada en la instancia única.

## Funcionamiento en main()

El flujo de ejecución en el programa principal es el siguiente:

1. Al llamar a `c1 = getInstancia("ES", "GMT-5")`, se crea la **primera y única** instancia del programa.
2. Posteriormente, al ejecutar `c2 = getInstancia("EN", "UTC")`, se intenta crear una nueva instancia. Sin embargo, como ya existe una, el método solo devuelve la instancia creada anteriormente (ignorando los nuevos parámetros).
3. **Verificación:** Ambas variables (`c1` y `c2`) apuntan exactamente al mismo objeto en memoria, lo cual se confirma con la comparación `c1 == c2`.