# Simulador de Misiones Artemis — Escenario 1: Ascenso y Propulsión con el SLS

Trabajo Práctico Integrador Final de la asignatura **Algoritmos y Estructuras de Datos** — Ingeniería en Sistemas de Información, **Universidad Tecnológica Nacional (UTN) - Facultad Regional Resistencia**.

---

## 👥 Integrantes y Comisión

* **Comisión:** `[Completar con tu comisión, ej: 2K1]`
* **Integrante 1 (Edición y producción de video):** `[Apellido, Nombre]`
* **Integrante 2 (Validaciones e interfaz de consola):** `[Apellido, Nombre]`
* **Integrante 3 (Cálculos físicos Puntos A y B):** `[Apellido, Nombre]`
* **Integrante 4 (Cálculos físicos Puntos C y D):** `[Apellido, Nombre]`
* **Integrante 5 (Documentación y organización de repositorio):** `[Apellido, Nombre]`

---

## 🚀 Descripción del Escenario Asignado

El sistema simula por consola el lanzamiento vertical rectilíneo del cohete **Space Launch System (SLS)** transportando a la nave **Orion** desde el Centro Espacial Kennedy (Escenario 1: *MRUV y Desprendimiento*), despreciando la resistencia del aire en la alta atmósfera:

1. **Primera Fase (Propulsión combinada):** La nave parte del reposo ($v_0 = 0{,}0\text{ m/s}$, $y_0 = 0{,}0\text{ m}$) y asciende con aceleración constante $a_1 = 20{,}0\text{ m/s}^2$ impulsada por los motores principales y los dos cohetes de combustible sólido (SRB) durante $t_1 = 120{,}0\text{ s}$.
2. **Desacople y Segunda Fase:** A los $120{,}0\text{ s}$ los SRB se desacoplan y el motor del núcleo principal continúa acelerando la nave con $a_2 = 12{,}5\text{ m/s}^2$ hasta alcanzar una altitud de apagado de motores de $h = 160.000{,}0\text{ m}$ ($160{,}0\text{ km}$).

### Datos Físicos Oficiales del Escenario
* **Velocidad inicial ($v_0$):** $0{,}0\text{ m/s}$
* **Altura inicial ($y_0$):** $0{,}0\text{ m}$
* **Aceleración Fase 1 ($a_1$):** $20{,}0\text{ m/s}^2$
* **Duración Fase 1 ($t_1$):** $120{,}0\text{ s}$
* **Aceleración Fase 2 ($a_2$):** $12{,}5\text{ m/s}^2$
* **Altitud de apagado de motores ($h$):** $160.000{,}0\text{ m}$
* **Aceleración de la gravedad ($g$):** $9{,}80\text{ m/s}^2$

---

## 🎯 Objetivos de Cálculo del Simulador

El programa permite calcular los siguientes cuatro puntos analíticos, tanto con los valores oficiales como con parámetros personalizados ingresados por el usuario:

* **Punto A:** Calcular la rapidez ($v_1$) y la altitud ($y_1$) alcanzadas al finalizar los primeros $120{,}0\text{ s}$ (desacople de los SRB).
* **Punto B:** Calcular la rapidez máxima ($v_2$) alcanzada al llegar a los $160.000{,}0\text{ m}$ de altitud y apagar los motores.
* **Punto C:** Calcular la altitud máxima ($h_{\text{máx}}$) respecto de la plataforma de lanzamiento si los motores fallaran repentinamente a los $160.000{,}0\text{ m}$ y la nave continuara en caída libre bajo la acción de la gravedad ($g = 9{,}80\text{ m/s}^2$).
* **Punto D:** Expresar la aceleración máxima experimentada por la tripulación en la primera fase como múltiplo de la gravedad terrestre ($g$).

---

## ⚙️ Funcionamiento del Programa y Arquitectura Modular

El sistema está desarrollado en **lenguaje C** estándar bajo un diseño modular que separa la interfaz de usuario, las validaciones de entrada y la lógica física mediante el uso de estructuras (`struct`) y paso por referencia con punteros:

```text
├── main.c            # Punto de entrada, menú principal interactivo y control de flujo
├── simulador.h       # Definición de DatosMisionSLS, constantes y prototipos de simulación
├── simulador.c       # Implementación de las ecuaciones cinemáticas (Puntos A, B, C y D)
├── validaciones.h    # Prototipos de las funciones de lectura segura por consola
├── validaciones.c    # Validación de tipos, rangos, buffers y detección de EOF
└── README.md         # Documentación general del proyecto y registro de uso de IA
```

### Validaciones Implementadas
El módulo `validaciones` garantiza que el programa no entre en bucles infinitos ni se cierre inesperadamente ante entradas inválidas:
* Lectura segura mediante buffers de texto (`fgets`) y conversión controlada (`strtol` / `strtod`), evitando problemas con el buffer de entrada estándar (`stdin`).
* Rechazo de cadenas vacías, caracteres alfabéticos o símbolos cuando se espera un número.
* Verificación estricta de rangos mínimos y máximos permitidos.
* Detección y manejo controlado de fin de entrada (`EOF`).

---

## 🛠️ Instrucciones de Compilación y Ejecución

### Requisitos previos
* Compilador **GCC** (MinGW en Windows, o GCC nativo en Linux/macOS).

### Compilación desde consola
Ubicado en la carpeta raíz del repositorio, ejecutar:

```bash
gcc -Wall -Wextra -std=c11 main.c simulador.c validaciones.c -o simulador_artemis -lm
```

*(Nota: en Windows con MinGW, el parámetro `-lm` es opcional).*

### Ejecución
* **En Linux / macOS:**
  ```bash
  ./simulador_artemis
  ```
* **En Windows (CMD o PowerShell):**
  ```cmd
  simulador_artemis.exe
  ```

---

## 🧪 Casos de Prueba Recomendados (Pendientes de Verificación Final)

Antes de la entrega definitiva, el equipo deberá ejecutar y verificar los siguientes escenarios de prueba:

1. **Ejecución con datos oficiales (Opción 1):** Verificar que los resultados de los puntos A, B, C y D coincidan con los cálculos analíticos realizados manualmente en papel.
2. **Validación de menú (Entradas erróneas):** Ingresar letras (`abc`), símbolos (`#$%`), números fuera de rango (`0`, `8`, `-5`) o presionar `Enter` vacío en el menú principal, comprobando que el sistema muestre un mensaje de error claro y vuelva a solicitar la opción.
3. **Validación de parámetros personalizados (Opción 2):** Intentar ingresar aceleraciones negativas o altitudes fuera del rango permitido y verificar su rechazo.
4. **Orden de ejecución:** Intentar ejecutar las opciones 3, 4, 5 o 6 antes de haber cargado datos (Opciones 1 o 2), verificando que el programa advierta al usuario en lugar de mostrar valores basura de memoria.

---

## 🎥 Video de Presentación

* **Enlace al video (máx. 5 minutos):** `[Pegar aquí el enlace de YouTube / Google Drive / Loom]`

---

## 🤖 Registro de Uso de Inteligencia Artificial

En cumplimiento con las pautas de transparencia de la cátedra, se detalla el uso de herramientas de Inteligencia Artificial Generativa durante el desarrollo:

* **Herramienta utilizada:** Gemini (Google).
* **Tareas asistidas:**
  * Diseño de la arquitectura modular del proyecto (`main.c`, `simulador.h/.c`, `validaciones.h/.c`).
  * Estructuración del menú principal y paso de estructuras por puntero en `main.c`.
  * Redacción de la plantilla base de documentación en `README.md`.
* **Consultas realizadas:** Se solicitó asistencia para estructurar `main.c` respetando la separación de responsabilidades exigida por la cátedra y definir los contratos de funciones entre los módulos de validaciones y simulación física.
* **Verificación y adaptación:** El equipo revisó los prototipos de funciones para asegurar la compatibilidad con los módulos individuales de cada integrante, y ejecutará las pruebas de compilación y validación por consola una vez integradas todas las ramas en el repositorio.