#include <stdio.h>
#include <string.h>
#include "inventario.h"

void imprimirMenuPrincipal() {
    printf("\n=====================================\n");
    printf("|              Menu                 |\n");
    printf("=====================================\n");
    printf("| 1. Ingresar nuevo producto        |\n");
    printf("| 2. Editar producto                |\n");
    printf("| 3. Eliminar producto              |\n");
    printf("| 4. Listar productos               |\n");
    printf("| 5. Buscar producto                |\n");
    printf("| 6. Ingresar nuevo cliente         |\n");
    printf("| 7. Editar cliente                 |\n");
    printf("| 8. Consultar cliente              |\n");
    printf("| 9. Listar clientes                |\n");
    printf("| 10. Crear factura                 |\n");
    printf("| 11. Buscar factura                |\n");
    printf("| 12. Listar facturas               |\n");
    printf("| 13. Salir                         |\n");
    printf("=====================================\n");
}

int main() {
    // Variables para el inventario de productos
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int numRepuestos = 0;

    // Variables para los clientes
    char cedulas[MAX_CLIENTES][MAX_CEDULA];
    char nombresClientes[MAX_CLIENTES][MAX_NOMBRE];
    int numClientes = 0;

    // Variables para las facturas
    char fechas[MAX_FACTURAS][20];
    char cedulasFacturas[MAX_CLIENTES][MAX_CEDULA];
    char nombresFacturas[MAX_FACTURAS][MAX_NOMBRE];
    float valoresPagados[MAX_FACTURAS];
    int cantidadesCompradas[MAX_FACTURAS];
    int numFacturas = 0;

    cargarInventario(nombres, cantidades, precios, &numRepuestos);
    cargarClientes(cedulas, nombresClientes, &numClientes);
    cargarFacturas(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, &numFacturas);

    int opcion;
    do {
        imprimirMenuPrincipal();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
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
                ingresarCliente(cedulas, nombresClientes, &numClientes);
                break;
            case 7:
                editarCliente(cedulas, nombresClientes, numClientes);
                break;
            case 8:
                consultarCliente(cedulas, nombresClientes, numClientes);
                break;
            case 9:
                listarClientes(cedulas, nombresClientes, numClientes);
                break;
            case 10:
                crearFactura(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, &numFacturas, nombres, cantidades, precios, numRepuestos, cedulas, nombresClientes, numClientes);
                break;
            case 11:
                buscarFactura(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, numFacturas);
                break;
            case 12:
                listarFacturas(fechas, cedulasFacturas, nombresFacturas, valoresPagados, cantidadesCompradas, numFacturas);
                break;
            case 13:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente de nuevo.\n");
        }
    } while (opcion != 13);

    return 0;
}
