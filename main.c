#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "simulador.h"

/* Prototipo de funcion auxiliar interna de main para imprimir el menu */
void mostrarMenuPrincipal(void);

int main(void) {
    /* Variable estructurada que guarda los parametros y resultados de la mision.
     * Esta estructura (DatosMisionSLS) debera estar definida en simulador.h */
    DatosMisionSLS mision;
    int opcion = 0;
    int datosCargados = 0; /* Bandera: 0 = sin datos, 1 = datos listos para simular */

    printf("=================================================================\n");
    printf("   SIMULADOR MISION ARTEMIS - ESCENARIO 1: ASCENSO DEL SLS\n");
    printf("   UTN - Facultad Regional Resistencia | Algoritmos y Est. Datos\n");
    printf("=================================================================\n");

    do {
        mostrarMenuPrincipal();

        /* Se utiliza la funcion de validacion para leer un entero entre 1 y 7.
         * Si devuelve 0, significa que ocurrio un fin de entrada (EOF). */
        if (!leerEnteroRango("\nSeleccione una opcion (1-7): ", 1, 7, &opcion)) {
            printf("\n[AVISO] Fin de entrada detectado. Cerrando el simulador...\n");
            break;
        }

        switch (opcion) {
            case 1:
                /* Carga los valores oficiales de la consigna (a1=20, t1=120, a2=12.5, h=160000) */
                inicializarDatosPorDefecto(&mision);
                datosCargados = 1;
                printf("\n[OK] Datos oficiales del escenario cargados correctamente.\n");
                mostrarParametrosActuales(&mision);
                break;

            case 2:
                /* Permite al usuario ingresar sus propios valores usando tus validaciones */
                printf("\n--- CONFIGURACION PERSONALIZADA DE LA MISION ---\n");
                if (!leerRealRango("Ingrese aceleracion Fase 1 a1 (m/s^2) [1.0 - 100.0]: ", 1.0, 100.0, &mision.a1) ||
                    !leerRealRango("Ingrese duracion Fase 1 t1 (segundos) [1.0 - 600.0]: ", 1.0, 600.0, &mision.t1) ||
                    !leerRealRango("Ingrese aceleracion Fase 2 a2 (m/s^2) [1.0 - 100.0]: ", 1.0, 100.0, &mision.a2) ||
                    !leerRealRango("Ingrese altitud de apagado h (metros) [1000.0 - 500000.0]: ", 1000.0, 500000.0, &mision.hApagado)) {
                    printf("\n[AVISO] Carga cancelada por fin de entrada (EOF).\n");
                    opcion = 7; /* Fuerza la salida limpia del programa */
                } else {
                    mision.v0 = 0.0;
                    mision.y0 = 0.0;
                    mision.g = 9.80;
                    datosCargados = 1;
                    printf("\n[OK] Parametros personalizados guardados.\n");
                }
                break;

            case 3:
                /* Punto A: Velocidad y altura al desacople de los SRB (t = 120 s) */
                if (!datosCargados) {
                    printf("\n[ERROR] Primero debe cargar los datos (Opcion 1 o 2).\n");
                } else {
                    calcularPuntoA(&mision);
                    printf("\n--- RESULTADO PUNTO A (Desacople SRB) ---\n");
                    printf("Rapidez alcanzada (v1): %.2f m/s\n", mision.v1);
                    printf("Altitud alcanzada (y1): %.2f m\n", mision.y1);
                }
                break;

            case 4:
                /* Punto B: Velocidad maxima al apagar motores a los 160.000 m */
                if (!datosCargados) {
                    printf("\n[ERROR] Primero debe cargar los datos (Opcion 1 o 2).\n");
                } else {
                    calcularPuntoA(&mision); /* Se asegura de tener v1 y y1 previos */
                    calcularPuntoB(&mision);
                    printf("\n--- RESULTADO PUNTO B (Apagado de motores) ---\n");
                    printf("Rapidez maxima alcanzada (v2): %.2f m/s\n", mision.v2);
                }
                break;

            case 5:
                /* Punto C: Altura maxima alcanzada si fallan los motores */
                if (!datosCargados) {
                    printf("\n[ERROR] Primero debe cargar los datos (Opcion 1 o 2).\n");
                } else {
                    calcularPuntoA(&mision);
                    calcularPuntoB(&mision);
                    calcularPuntoC(&mision);
                    printf("\n--- RESULTADO PUNTO C (Falla de motores y caida libre) ---\n");
                    printf("Altitud maxima alcanzada (h_max): %.2f m\n", mision.hMax);
                }
                break;

            case 6:
                /* Punto D: Aceleracion de la Fase 1 como multiplo de la gravedad (g) */
                if (!datosCargados) {
                    printf("\n[ERROR] Primero debe cargar los datos (Opcion 1 o 2).\n");
                } else {
                    calcularPuntoD(&mision);
                    printf("\n--- RESULTADO PUNTO D (Fuerza G en Fase 1) ---\n");
                    printf("Aceleracion experimentada: %.2f g\n", mision.multiploG);
                }
                break;

            case 7:
                printf("\nSaliendo del simulador Artemis. Hasta luego!\n");
                break;
        }

    } while (opcion != 7);

    return 0;
}

void mostrarMenuPrincipal(void) {
    printf("\n==================== MENU PRINCIPAL ====================\n");
    printf("1. Cargar datos oficiales del escenario SLS (por defecto)\n");
    printf("2. Ingresar parametros personalizados de vuelo\n");
    printf("3. Calcular Punto A: Rapidez y altitud al desacople SRB\n");
    printf("4. Calcular Punto B: Rapidez maxima al apagar motores\n");
    printf("5. Calcular Punto C: Altitud maxima ante falla de motores\n");
    printf("6. Calcular Punto D: Aceleracion Fase 1 en multiplos de g\n");
    printf("7. Salir del programa\n");
    printf("========================================================\n");
}
