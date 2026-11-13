#include <math.h>

// Definición de la estructura para empaquetar v1 e y1
typedef struct {
    double v1;
    double y1;
} ResultadoFase1;

// Función que resuelve el Punto A (Rapidez y altitud al desacople de los SRB)
ResultadoFase1 calcularPuntoA(double a1, double t1) {
    ResultadoFase1 res;
    res.v1 = a1 * t1;            // v1 = a1 * t1
    res.y1 = 0.5 * a1 * t1 * t1; // y1 = 1/2 * a1 * t1^2
    return res;
}

// Función que resuelve el Punto B (Rapidez máxima al apagar motores a la altura h)
double calcularPuntoB(double v1, double y1, double a2, double h) {
    double delta_y = h - y1;
    // Ecuación de Torricelli: v2^2 = v1^2 + 2 * a2 * delta_y
    double v2 = sqrt(v1 * v1 + 2.0 * a2 * delta_y);
    return v2;
}
