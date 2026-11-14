SIMULADOR DE MISIONES ARTEMIS - ESCENARIO 1: ASCENSO Y PROPULSIÓN CON EL SLS

Laboratorio de C - Algoritmos y Estructuras de Datos - Ingeniería en Sistemas de Información UTN FRRe

--------------------------------------------------------------------------------

INTEGRANTES Y COMISIÓN

- Comisión: K1.4
  
- ALARCÓN, Martín Santiago (Cálculos físicos Puntos A y B)
- CIMBARO CANELLA ALCARAZ, Lucas Leonel (Cálculos físicos Puntos C y D)
- MOTTA BITTENCURT, Constanza (main.c, README.md y organización de repositorio)
- MUCHIUT, Ian Mateo (Validaciones e interfaz de consola)
- MUÑOZ CIPETTINI, Sebastián (Edición y producción de video)


--------------------------------------------------------------------------------

DESCRIPCIÓN DEL ESCENARIO ASIGNADO

El sistema simula por consola el lanzamiento vertical rectilíneo del cohete Space Launch System (SLS) transportando a la nave Orion desde el Centro Espacial Kennedy (Escenario 1: MRUV y Desprendimiento), despreciando la resistencia del aire en la alta atmósfera:

1. Primera Fase (Propulsión combinada): La nave parte del reposo ($v_0 = 0{,}0\text{ m/s}$, $y_0 = 0{,}0\text{ m}$) y asciende con aceleración constante $a_1 = 20{,}0\text{ m/s}^2$ impulsada por los motores principales y los dos cohetes de combustible sólido (SRB) durante $t_1 = 120{,}0\text{ s}$.
2. Desacople y Segunda Fase: A los $120{,}0\text{ s}$ los SRB se desacoplan y el motor del núcleo principal continúa acelerando la nave con $a_2 = 12{,}5\text{ m/s}^2$ hasta alcanzar una altitud de apagado de motores de $h = 160.000{,}0\text{ m}$ ($160{,}0\text{ km}$).

Datos Físicos Oficiales del Escenario:
- Velocidad inicial ($v_0$): $0{,}0\text{ m/s}$
- Altura inicial ($y_0$): $0{,}0\text{ m}$
- Aceleración Fase 1 ($a_1$): $20{,}0\text{ m/s}^2$
- Duración Fase 1 ($t_1$): $120{,}0\text{ s}$
- Aceleración Fase 2 ($a_2$): $12{,}5\text{ m/s}^2$
- Altitud de apagado de motores ($h$): $160.000{,}0\text{ m}$
- Aceleración de la gravedad ($g$): $9{,}80\text{ m/s}^2$

--------------------------------------------------------------------------------

OBJETIVOS DE CÁLCULO DEL SIMULADOR

El programa permite calcular los siguientes cuatro puntos analíticos, tanto con los valores oficiales como con parámetros personalizados ingresados por el usuario:

- Punto A: Calcular la rapidez ($v_1$) y la altitud ($y_1$) alcanzadas al finalizar los primeros $120{,}0\text{ s}$ (desacople de los SRB).
- Punto B: Calcular la rapidez máxima ($v_2$) alcanzada al llegar a los $160.000{,}0\text{ m}$ de altitud y apagar los motores.
- Punto C: Calcular la altitud máxima ($h_{\text{máx}}$) respecto de la plataforma de lanzamiento si los motores fallaran repentinamente a los $160.000{,}0\text{ m}$ y la nave continuara en caída libre bajo la acción de la gravedad ($g = 9{,}80\text{ m/s}^2$).
- Punto D: Expresar la aceleración máxima experimentada por la tripulación en la primera fase como múltiplo de la gravedad terrestre ($g$).

--------------------------------------------------------------------------------

FUNCIONAMIENTO DEL PROGRAMA Y ARQUITECTURA MODULAR

El sistema está desarrollado en lenguaje C estándar bajo un diseño modular que separa la interfaz de usuario, las validaciones de entrada y la lógica física mediante el uso de estructuras (struct) y paso por referencia con punteros:

    main.c            Punto de entrada, menú principal interactivo y control de flujo
    simulador.h       Definición de DatosMisionSLS, constantes y prototipos de simulación
    simulador.c       Implementación de las ecuaciones cinemáticas (Puntos A, B, C y D)
    validaciones.h    Prototipos de las funciones de lectura segura por consola
    validaciones.c    Validación de tipos, rangos, buffers y detección de EOF
    README.md         Documentación general del proyecto y registro de uso de IA

Validaciones Implementadas:
El módulo validaciones garantiza que el programa no entre en bucles infinitos ni se cierre inesperadamente ante entradas inválidas:
- Lectura segura mediante buffers de texto (fgets) y conversión controlada (strtol / strtod), evitando problemas con el buffer de entrada estándar (stdin).
- Rechazo de cadenas vacías, caracteres alfabéticos o símbolos cuando se espera un número.
- Verificación estricta de rangos mínimos y máximos permitidos.
- Detección y manejo controlado de fin de entrada (EOF).

--------------------------------------------------------------------------------

INSTRUCCIONES DE COMPILACIÓN Y EJECUCIÓN

Requisitos previos:
- Compilador GCC (MinGW en Windows, o GCC nativo en Linux/macOS).

Compilación desde consola (ubicado en la carpeta raíz del repositorio):

    gcc -Wall -Wextra -std=c11 main.c simulador.c validaciones.c -o simulador_artemis -lm

(Nota: en Windows con MinGW, el parámetro -lm es opcional).

Ejecución en Linux / macOS:

    ./simulador_artemis

Ejecución en Windows (CMD o PowerShell):

    simulador_artemis.exe

--------------------------------------------------------------------------------

CASOS DE PRUEBA RECOMENDADOS (PENDIENTES DE VERIFICACIÓN FINAL)

Antes de la entrega definitiva, el equipo deberá ejecutar y verificar los siguientes escenarios de prueba:

1. Ejecución con datos oficiales (Opción 1): Verificar que los resultados de los puntos A, B, C y D coincidan con los cálculos analíticos realizados manualmente en papel.
2. Validación de menú (Entradas erróneas): Ingresar letras (abc), símbolos (#$%), números fuera de rango (0, 8, -5) o presionar Enter vacío en el menú principal, comprobando que el sistema muestre un mensaje de error claro y vuelva a solicitar la opción.
3. Validación de parámetros personalizados (Opción 2): Intentar ingresar aceleraciones negativas o altitudes fuera del rango permitido y verificar su rechazo.
4. Orden de ejecución: Intentar ejecutar las opciones 3, 4, 5 o 6 antes de haber cargado datos (Opciones 1 o 2), verificando que el programa advierta al usuario en lugar de mostrar valores basura de memoria.

--------------------------------------------------------------------------------

VIDEO DE PRESENTACIÓN

- Enlace al video: 

--------------------------------------------------------------------------------

REGISTRO DE USO DE INTELIGENCIA ARTIFICIAL

En cumplimiento con las pautas de transparencia de la cátedra, se detalla el uso de herramientas de Inteligencia Artificial Generativa durante el desarrollo:

- Herramienta utilizada: Gemini (Google).
  
Usos:
- Controlar si el guion del video estaba completo y cumplía lo pedido.
