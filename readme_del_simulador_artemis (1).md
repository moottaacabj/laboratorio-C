SIMULADOR DE MISIONES ARTEMIS - ESCENARIO 1: ASCENSO Y PROPULSION CON EL SLS

Trabajo Practico Integrador Final de la asignatura Algoritmos y Estructuras de Datos - Ingenieria en Sistemas de Informacion, Universidad Tecnologica Nacional (UTN) - Facultad Regional Resistencia.

--------------------------------------------------------------------------------

INTEGRANTES Y COMISION

- Comision: [Completar con tu comision, ej: 2K1]
- Integrante 1 (Edicion y produccion de video): [Apellido, Nombre]
- Integrante 2 (Validaciones e interfaz de consola): [Apellido, Nombre]
- Integrante 3 (Calculos fisicos Puntos A y B): [Apellido, Nombre]
- Integrante 4 (Calculos fisicos Puntos C y D): [Apellido, Nombre]
- Integrante 5 (Documentacion y organizacion de repositorio): [Apellido, Nombre]

--------------------------------------------------------------------------------

DESCRIPCION DEL ESCENARIO ASIGNADO

El sistema simula por consola el lanzamiento vertical rectilineo del cohete Space Launch System (SLS) transportando a la nave Orion desde el Centro Espacial Kennedy (Escenario 1: MRUV y Desprendimiento), despreciando la resistencia del aire en la alta atmosfera:

1. Primera Fase (Propulsion combinada): La nave parte del reposo ($v_0 = 0{,}0\text{ m/s}$, $y_0 = 0{,}0\text{ m}$) y asciende con aceleracion constante $a_1 = 20{,}0\text{ m/s}^2$ impulsada por los motores principales y los dos cohetes de combustible solido (SRB) durante $t_1 = 120{,}0\text{ s}$.
2. Desacople y Segunda Fase: A los $120{,}0\text{ s}$ los SRB se desacoplan y el motor del nucleo principal continua acelerando la nave con $a_2 = 12{,}5\text{ m/s}^2$ hasta alcanzar una altitud de apagado de motores de $h = 160.000{,}0\text{ m}$ ($160{,}0\text{ km}$).

Datos Fisicos Oficiales del Escenario:
- Velocidad inicial ($v_0$): $0{,}0\text{ m/s}$
- Altura inicial ($y_0$): $0{,}0\text{ m}$
- Aceleracion Fase 1 ($a_1$): $20{,}0\text{ m/s}^2$
- Duracion Fase 1 ($t_1$): $120{,}0\text{ s}$
- Aceleracion Fase 2 ($a_2$): $12{,}5\text{ m/s}^2$
- Altitud de apagado de motores ($h$): $160.000{,}0\text{ m}$
- Aceleracion de la gravedad ($g$): $9{,}80\text{ m/s}^2$

--------------------------------------------------------------------------------

OBJETIVOS DE CALCULO DEL SIMULADOR

El programa permite calcular los siguientes cuatro puntos analiticos, tanto con los valores oficiales como con parametros personalizados ingresados por el usuario:

- Punto A: Calcular la rapidez ($v_1$) y la altitud ($y_1$) alcanzadas al finalizar los primeros $120{,}0\text{ s}$ (desacople de los SRB).
- Punto B: Calcular la rapidez maxima ($v_2$) alcanzada al llegar a los $160.000{,}0\text{ m}$ de altitud y apagar los motores.
- Punto C: Calcular la altitud maxima ($h_{\text{max}}$) respecto de la plataforma de lanzamiento si los motores fallaran repentinamente a los $160.000{,}0\text{ m}$ y la nave continuara en caida libre bajo la accion de la gravedad ($g = 9{,}80\text{ m/s}^2$).
- Punto D: Expresar la aceleracion maxima experimentada por la tripulacion en la primera fase como multiplo de la gravedad terrestre ($g$).

--------------------------------------------------------------------------------

FUNCIONAMIENTO DEL PROGRAMA Y ARQUITECTURA MODULAR

El sistema esta desarrollado en lenguaje C estandar bajo un diseno modular que separa la interfaz de usuario, las validaciones de entrada y la logica fisica mediante el uso de estructuras (struct) y paso por referencia con punteros:

    main.c            Punto de entrada, menu principal interactivo y control de flujo
    simulador.h       Definicion de DatosMisionSLS, constantes y prototipos de simulacion
    simulador.c       Implementacion de las ecuaciones cinematicas (Puntos A, B, C y D)
    validaciones.h    Prototipos de las funciones de lectura segura por consola
    validaciones.c    Validacion de tipos, rangos, buffers y deteccion de EOF
    README.md         Documentacion general del proyecto y registro de uso de IA

Validaciones Implementadas:
El modulo validaciones garantiza que el programa no entre en bucles infinitos ni se cierre inesperadamente ante entradas invalidas:
- Lectura segura mediante buffers de texto (fgets) y conversion controlada (strtol / strtod), evitando problemas con el buffer de entrada estandar (stdin).
- Rechazo de cadenas vacias, caracteres alfabeticos o simbolos cuando se espera un numero.
- Verificacion estricta de rangos minimos y maximos permitidos.
- Deteccion y manejo controlado de fin de entrada (EOF).

--------------------------------------------------------------------------------

INSTRUCCIONES DE COMPILACION Y EJECUCION

Requisitos previos:
- Compilador GCC (MinGW en Windows, o GCC nativo en Linux/macOS).

Compilacion desde consola (ubicado en la carpeta raiz del repositorio):

    gcc -Wall -Wextra -std=c11 main.c simulador.c validaciones.c -o simulador_artemis -lm

(Nota: en Windows con MinGW, el parametro -lm es opcional).

Ejecucion en Linux / macOS:

    ./simulador_artemis

Ejecucion en Windows (CMD o PowerShell):

    simulador_artemis.exe

--------------------------------------------------------------------------------

CASOS DE PRUEBA RECOMENDADOS (PENDIENTES DE VERIFICACION FINAL)

Antes de la entrega definitiva, el equipo debera ejecutar y verificar los siguientes escenarios de prueba:

1. Ejecucion con datos oficiales (Opcion 1): Verificar que los resultados de los puntos A, B, C y D coincidan con los calculos analiticos realizados manualmente en papel.
2. Validacion de menu (Entradas erroneas): Ingresar letras (abc), simbolos (#$%), numeros fuera de rango (0, 8, -5) o presionar Enter vacio en el menu principal, comprobando que el sistema muestre un mensaje de error claro y vuelva a solicitar la opcion.
3. Validacion de parametros personalizados (Opcion 2): Intentar ingresar aceleraciones negativas o altitudes fuera del rango permitido y verificar su rechazo.
4. Orden de ejecucion: Intentar ejecutar las opciones 3, 4, 5 o 6 antes de haber cargado datos (Opciones 1 o 2), verificando que el programa advierta al usuario en lugar de mostrar valores basura de memoria.

--------------------------------------------------------------------------------

VIDEO DE PRESENTACION

- Enlace al video (max. 5 minutos): [Pegar aqui el enlace de YouTube / Google Drive / Loom]

--------------------------------------------------------------------------------

REGISTRO DE USO DE INTELIGENCIA ARTIFICIAL

En cumplimiento con las pautas de transparencia de la catedra, se detalla el uso de herramientas de Inteligencia Artificial Generativa durante el desarrollo:

- Herramienta utilizada: Gemini (Google).
- Tareas asistidas:
  1. Diseno de la arquitectura modular del proyecto (main.c, simulador.h/.c, validaciones.h/.c).
  2. Estructuracion del menu principal y paso de estructuras por puntero en main.c.
  3. Redaccion de la plantilla base de documentacion en README.md.
- Consultas realizadas: Se solicito asistencia para estructurar main.c respetando la separacion de responsabilidades exigida por la catedra y definir los contratos de funciones entre los modulos de validaciones y simulacion fisica.
- Verificacion y adaptacion: El equipo reviso los prototipos de funciones para asegurar la compatibilidad con los modulos individuales de cada integrante, y ejecutara las pruebas de compilacion y validacion por consola una vez integradas todas las ramas en el repositorio.