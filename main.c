#include <stdio.h>
#include <string.h>
#include "funciones.h"



int main() {
    int opcion;
    int tiempoDisponible = leerEnteroPositivo("Ingrese el tiempo total disponible (minutos): ");
    int recursosDisponibles = leerEnteroPositivo("Ingrese los recursos totales disponibles: ");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ingresarProducto(); break;
            case 2: mostrarProductos(); break;
            case 3: editarProducto(); break;
            case 4: eliminarProducto(); break;
            case 5: calcularProduccion(tiempoDisponible, recursosDisponibles); break;
            case 0: printf("Saliendo del programa.\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}