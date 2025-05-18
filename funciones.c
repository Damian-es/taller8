#include <stdio.h>
#include <string.h>
#include "funciones.h"
// Variables globales (definidas directamente en el .h como pediste)
int nombres_cantidad = 0;
char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
int tiemposUnitarios[MAX_PRODUCTOS];
int recursosUnitarios[MAX_PRODUCTOS];
int activos[MAX_PRODUCTOS];

int leerEnteroPositivo(const char *mensaje) {
    char entrada[100];
    int numero, valido, i;

    while (1) {
        printf("%s", mensaje);
        scanf(" %[^\n]", entrada);

        valido = 1;
        for (i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] < '0' || entrada[i] > '9') {
                valido = 0;
                break;
            }
        }

        if (valido) {
            sscanf(entrada, "%d", &numero);
            if (numero > 0) return numero;
        }

        printf("ERROR: Solo se permiten numeros enteros mayores que cero.\n");
    }
}

void ingresarProducto() {
    if (nombres_cantidad >= MAX_PRODUCTOS) {
        printf("Limite de productos alcanzado.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombres[nombres_cantidad]);

    cantidades[nombres_cantidad] = leerEnteroPositivo("Cantidad demandada: ");
    tiemposUnitarios[nombres_cantidad] = leerEnteroPositivo("Tiempo por unidad (minutos): ");
    recursosUnitarios[nombres_cantidad] = leerEnteroPositivo("Recursos por unidad: ");
    activos[nombres_cantidad] = 1;
    nombres_cantidad++;
}

void mostrarProductos() {
    printf("\n--- Lista de productos ---\n");
    int encontrados = 0;
    for (int i = 0; i < nombres_cantidad; i++) {
        if (activos[i]) {
            printf("%d. %s - Cantidad: %d, Tiempo/unidad: %d, Recursos/unidad: %d\n",
                   i + 1, nombres[i], cantidades[i], tiemposUnitarios[i], recursosUnitarios[i]);
            encontrados = 1;
        }
    }
    if (!encontrados) {
        printf("No hay productos registrados.\n");
    }
}

void editarProducto() {
    char buscar[MAX_NOMBRE];
    int i, encontrado = 0;

    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %[^\n]", buscar);

    for (i = 0; i < nombres_cantidad; i++) {
        if (activos[i] && strcmp(nombres[i], buscar) == 0) {
            cantidades[i] = leerEnteroPositivo("Nueva cantidad: ");
            tiemposUnitarios[i] = leerEnteroPositivo("Nuevo tiempo por unidad: ");
            recursosUnitarios[i] = leerEnteroPositivo("Nuevos recursos por unidad: ");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto() {
    char buscar[MAX_NOMBRE];
    int i, encontrado = 0;

    printf("Ingrese el nombre del producto a eliminar: ");
    scanf(" %[^\n]", buscar);

    for (i = 0; i < nombres_cantidad; i++) {
        if (activos[i] && strcmp(nombres[i], buscar) == 0) {
            activos[i] = 0;
            printf("Producto eliminado.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void calcularProduccion(int tiempoDisponible, int recursosDisponibles) {
    int totalTiempo = 0, totalRecursos = 0;

    for (int i = 0; i < nombres_cantidad; i++) {
        if (activos[i]) {
            totalTiempo += cantidades[i] * tiemposUnitarios[i];
            totalRecursos += cantidades[i] * recursosUnitarios[i];
        }
    }

    printf("\nTiempo requerido total: %d minutos\n", totalTiempo);
    printf("Recursos requeridos totales: %d\n", totalRecursos);

    if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles) {
        printf("Es posible cumplir con la demanda.\n");
    } else {
        printf("No es posible cumplir con la demanda.\n");
        if (totalTiempo > tiempoDisponible) printf("- Tiempo insuficiente.\n");
        if (totalRecursos > recursosDisponibles) printf("- Recursos insuficientes.\n");
    }
}