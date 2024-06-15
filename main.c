#include <stdio.h>
#include "inventario.h"

#define MAX_PRODUCTOS 20
#define MAX_NOMBRE 50

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int numRepuestos = 0;

    cargarInventario(nombres, cantidades, precios, &numRepuestos);

    int opcion;

    do {
        imprimirMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarRepuesto(nombres, cantidades, precios, &numRepuestos);
                break;
            case 2:
                editarRepuesto(nombres, cantidades, precios, numRepuestos);
                break;
            case 3:
                eliminarRepuesto(nombres, cantidades, precios, &numRepuestos);
                break;
            case 4:
                listarRepuestos(nombres, cantidades, precios, numRepuestos);
                break;
            case 5:
                buscarRepuesto(nombres, cantidades, precios, numRepuestos);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcion != 6);

    return 0;
}
