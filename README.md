# Preguntas Teóricas sobre Singleton

A continuación se detallan las respuestas sobre las desventajas, contraindicaciones y diferencias del patrón Singleton respecto a las clases estáticas.

## 1. ¿Qué desventajas tiene el patrón Singleton en pruebas unitarias?

El patrón Singleton dificulta las pruebas unitarias por los siguientes motivos principales:

- **Alta dependencia global:** Un Singleton actúa como una variable global. Esto provoca un acoplamiento fuerte, impidiendo aislar componentes durante las pruebas.
- **Persistencia del estado (No reiniciable):** Como solo existe una instancia, el estado persiste entre pruebas. Para testear distintos escenarios, se necesitaría destruir o reiniciar manualmente la instancia, lo cual no suele estar contemplado en el diseño original.
- **Dificultad con Mocks:** Las herramientas de prueba reemplazan objetos por versiones simuladas. Con Singleton, el acceso es controlado internamente y no mediante interfaces, haciendo que "mockearlo" sea complejo o imposible sin refactorizar.

> *Nota:* Autores como Martin Fowler consideran que el Singleton rompe los principios de diseño para testeo debido a que introduce estado global compartido no controlable.

## 2. ¿Cuándo no es recomendable usar Singleton?

No es recomendable utilizar Singleton en los siguientes casos:

- **Cuando el recurso no es realmente único:** Si la lógica permite múltiples instancias sin conflicto, Singleton agrega restricciones innecesarias y reduce flexibilidad.
- **Cuando la aplicación puede escalar:** En arquitecturas distribuidas o microservicios, un punto global puede generar cuellos de botella y problemas de concurrencia.
- **Cuando se desea bajo acoplamiento:** Es preferible usar patrones como Inyección de Dependencias (DI), donde las instancias son administradas externamente.
- **En sistemas que requieren fácil testeo:** Debido a las dificultades mencionadas anteriormente, no debe usarse por defecto.

## 3. ¿Cómo se diferencia de una clase estática?

Aunque ambos proporcionan un único punto de acceso, cumplen propósitos distintos:

| Criterio | Singleton | Clase Estática |
| :--- | :--- | :--- |
| **¿Requiere instancia?** | Sí, una única instancia. | No, acceso directo por nombre de clase. |
| **Ciclo de vida** | Controlado por el desarrollador (creación/destrucción). | Automático (inicio a fin del programa). |
| **Memoria** | Heap. | Memoria estática. |
| **Estado interno** | Persistente, accesible mediante la instancia. | Global, siempre activo tras la carga. |
| **Constructores** | Privado (ejecutado una vez). | No tiene (o deshabilitado). |
| **Herencia** | Puede heredarse e implementar interfaces. | No permite herencia. |
| **Polimorfismo** | Soportado. | No soportado. |
| **Uso en pruebas** | Más testeable (se puede simular/reiniciar). | Difícil de testear por estado global. |
| **Ejemplos** | Logger, Conexión BD, Configuración. | Math, Herramientas (Helpers), Constantes. |

### Conclusión
El **Singleton** opera como un objeto con identidad propia capaz de almacenar estado dinámico, mientras que la **clase estática** actúa como un contenedor funcional.
*   Elige **Singleton** cuando necesites un objeto global controlado.
*   Elige **Clase Estática** para utilidades generales sin comportamiento dinámico.
