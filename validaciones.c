#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include "validaciones.h"

/*------Funciones internas (solo se usan en este archivo)------ */
/*Lee una lines del teclado y le saca el salto de linea final.
Devuelve: 1 = ok, 0 = fin de entrada, -1 = linea demasiado larga */
static int leerLinea(char *buffer, size_t tam) {
    size_t len;

    if (fgets(buffer, (int)tam, stdin) == NULL) {
        return 0; /* EOF o error de lectura */
    }

    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        return 1;
    }

/* Si no hay salto de linea y el buffer esta lleno, la linea era muy larga */
    if (len == tam - 1) {
        limpiarBuffer(); /* descarta el resto de la linea */
        return -1;
    }
    return 1;
}

/* Devuelve 1 si el texto tiene solo espacios (o nada) */
static int soloEspacios(const char *p) {
    while (*p != '\0') {
        if (!isspace((unsigned char)*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

static int esVacia(const char *s) {
    return soloEspacios(s);
}

/* --------Limpieza de entrada-------- */

void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta caracteres */
    }
}

/* --------Mensajes al usuario--------- */

void mostrarAdvertencia(const char *texto) {
    printf("[AVISO] %s\n", texto);
}

void mostrarError(const char *texto) {
    printf("[ERROR] %s\n", texto);
}

void mostrarExito(const char *texto) {
    printf("[OK] %s\n", texto);
}

/* --------Entrada segura-------- */

int leerEnteroRango(const char *mensaje, int min, int max, int *valor) {
    char linea[MAX_LINEA];
    char *fin;
    long numero;
    int estado;

    for (;;) {
        printf("%s", mensaje);
        fflush(stdout);

        estado = leerLinea(linea, sizeof(linea));
        if (estado == 0) {
            return 0; 
        }
        if (estado == -1) {
            mostrarError("La entrada es demasiado larga. Intente nuevamente.");
            continue;
        }
        if (esVacia(linea)) {
            mostrarError("No ingreso ningun valor. Intente nuevamente.");
            continue;
        }

        errno = 0;
        numero = strtol(linea, &fin, 10);

        if (fin == linea || !soloEspacios(fin)) {
            mostrarError("Entrada invalida: debe ingresar un numero entero.");
            continue;
        }
        if (errno == ERANGE || numero < INT_MIN || numero > INT_MAX) {
            mostrarError("El numero ingresado es demasiado grande.");
            continue;
        }
        if (numero < min || numero > max) {
            printf("[ERROR] El valor debe estar entre %d y %d.\n", min, max);
            continue;
        }

        *valor = (int)numero;
        return 1;
    }
}

int leerRealRango(const char *mensaje, double min, double max, double *valor) {
    char linea[MAX_LINEA];
    char *fin;
    char *coma;
    double numero;
    int estado;

    for (;;) {
        printf("%s", mensaje);
        fflush(stdout);

        estado = leerLinea(linea, sizeof(linea));
        if (estado == 0) {
            return 0; 
        }
        if (estado == -1) {
            mostrarError("La entrada es demasiado larga. Intente nuevamente.");
            continue;
        }
        if (esVacia(linea)) {
            mostrarError("No ingreso ningun valor. Intente nuevamente.");
            continue;
        }

        /* Se acepta la coma como separador decimal */
        coma = strchr(linea, ',');
        if (coma != NULL) {
            *coma = '.';
        }

        errno = 0;
        numero = strtod(linea, &fin);

        if (fin == linea || !soloEspacios(fin)) {
            mostrarError("Entrada invalida: debe ingresar un numero real.");
            continue;
        }

        if (errno == ERANGE || !isfinite(numero)) {
            mostrarError("El numero ingresado esta fuera del rango representable.");
            continue;
        }
        if (numero < min || numero > max) {
            printf("[ERROR] El valor debe estar entre %.2f y %.2f.\n", min, max);
            continue;
        }

        *valor = numero;
        return 1;
    }
}

int leerCaracter(const char *mensaje, const char *permitidos, char *valor) {
    char linea[MAX_LINEA];
    char *inicio;
    char c;
    int estado;

    for (;;) {
        printf("%s", mensaje);
        fflush(stdout);

        estado = leerLinea(linea, sizeof(linea));
        if (estado == 0) {
            return 0; 
        }
        if (estado == -1) {
            mostrarError("La entrada es demasiado larga. Intente de nuevo.");
            continue;
        }

        /* Saltea espacios iniciales y exige exactamente un caracter */
        inicio = linea;
        while (isspace((unsigned char)*inicio)) {
            inicio++;
        }
        if (*inicio == '\0') {
            mostrarError("No ingreso ningun caracter. Intente de nuevo.");
            continue;
        }
        if (!soloEspacios(inicio + 1)) {
            mostrarError("Ingrese un unico caracter.");
            continue;
        }

        c = (char)tolower((unsigned char)*inicio);
        if (strchr(permitidos, c) == NULL) {
            printf("[ERROR] Opcion invalida. Opciones permitidas: %s\n", permitidos);
            continue;
        }

        *valor = c;
        return 1;
    }
}

int leerConfirmacion(const char *mensaje) {
    char respuesta;

    if (!leerCaracter(mensaje, "sn", &respuesta)) {
        return -1;
    }
    return (respuesta == 's') ? 1 : 0;
}
