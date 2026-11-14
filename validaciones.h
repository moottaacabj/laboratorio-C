#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* Modulo de validaciones: lectura segura de datos y mensajes al usuario.
 *
 * Las funciones leer...() devuelven:
 *   1 -> el dato es valido y quedo guardado
 *   0 -> se termino la entrada (EOF), hay que salir del programa
 * Si el usuario se equivoca, la funcion vuelve a preguntar. */

/* Maximo de caracteres que se leen por linea */
#define MAX_LINEA 128

/* ---------------------------- Entrada segura ---------------------------- */

/* Lee un entero entre min y max */
int leerEnteroRango(const char *mensaje, int min, int max, int *valor);

/* Lee un numero real entre min y max (acepta punto o coma) */
int leerRealRango(const char *mensaje, double min, double max, double *valor);

/* Lee un caracter que este dentro de 'permitidos' (ej: "sn") */
int leerCaracter(const char *mensaje, const char *permitidos, char *valor);

/* Pregunta de si/no. Devuelve 1 (si), 0 (no) o -1 si hay fin de entrada. */
int leerConfirmacion(const char *mensaje);

/* ------------------------- Utilidades de entrada ------------------------- */

/* Descarta lo que quede pendiente en stdin hasta el proximo '\n' o EOF. */
void limpiarBuffer(void);

/* ------------------------- Mensajes al usuario ------------------------- */

void mostrarAdvertencia(const char *texto); /* imprime "[AVISO] ..."  */
void mostrarError(const char *texto);       /* imprime "[ERROR] ..."  */
void mostrarExito(const char *texto);       /* imprime "[OK] ..."     */

#endif 
