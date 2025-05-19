#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 50

int leerEnteroPositivo(const char *mensaje);
void ingresarProducto();
void mostrarProductos();
void editarProducto();
void eliminarProducto();
void calcularProduccion(int tiempoDisponible, int recursosDisponibles);