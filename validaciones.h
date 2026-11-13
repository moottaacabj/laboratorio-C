#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* ======================================================================
 * validaciones.h
 * Modulo de Validaciones e Interfaz.
 * Ingreso seguro de enteros, reales y caracteres, y mensajes al usuario.
 *
 * Convencion de retorno de todas las funciones leer*():
 *    1  -> se obtuvo un valor valido (queda guardado en el puntero de salida)
 *    0  -> fin de entrada (EOF, Ctrl+D / Ctrl+Z); el llamador debe cortar
 * La funcion NUNCA devuelve un valor invalido: repite la consulta hasta que
 * el usuario ingrese un dato correcto.
 * ====================================================================== */

/* Tamano maximo (en caracteres) de una linea de entrada que se procesa */
#define MAX_LINEA 128

/* ---------------------------- Entrada segura ---------------------------- */

/* Lee un entero en el rango [min, max]. Rechaza texto, vacio, decimales,
 * basura al final (ej. "5abc") y desbordamientos. */
int leerEnteroRango(const char *mensaje, int min, int max, int *valor);

/* Lee un real en el rango [min, max]. Acepta punto o coma decimal.
 * Rechaza texto, vacio, "nan", "inf", basura al final y desbordamientos. */
int leerRealRango(const char *mensaje, double min, double max, double *valor);

/* Lee un unico caracter que pertenezca al conjunto 'permitidos'
 * (ej. "sn"). No distingue mayusculas de minusculas; devuelve el caracter
 * en minuscula. */
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

#endif /* VALIDACIONES_H */
