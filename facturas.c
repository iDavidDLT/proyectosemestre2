#include <stdio.h>
#include <string.h>
#include <time.h>
#include "inventario.h"

void cargarFacturas(char fechas[][20], char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], float valoresPagados[], int cantidadesCompradas[], int *numFacturas) {
    FILE *file = fopen("facturas.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de facturas.\n");
        return;
    }

    *numFacturas = 0;
    while (*numFacturas < MAX_FACTURAS && fscanf(file, "%19s %10s %99s %f %d", fechas[*numFacturas], cedulas[*numFacturas], nombresClientes[*numFacturas], &valoresPagados[*numFacturas], &cantidadesCompradas[*numFacturas]) == 5) {
        (*numFacturas)++;
    }

    fclose(file);
}

void guardarFacturas(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    FILE *file = fopen("facturas.txt", "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de facturas para escritura.\n");
        return;
    }

    for (int i = 0; i < numFacturas; i++) {
        fprintf(file, "%s %s %s %.2f %d\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
    }

    fclose(file);
}

void obtenerFechaActual(char fecha[]) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(fecha, 20, "%Y-%m-%d", tm);
}

void crearFactura(char fechas[][20], char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], float valoresPagados[], int cantidadesCompradas[], int *numFacturas, const char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numRepuestos, const char cedulasClientes[][MAX_CEDULA], const char nombresClientesInventario[][MAX_NOMBRE], int numClientes) {
    if (*numFacturas >= MAX_FACTURAS) {
        printf("Error: lista de facturas llena.\n");
        return;
    }

    char cedulaCliente[MAX_CEDULA];
    char nombreProducto[MAX_NOMBRE];
    int cantidadComprar;

    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedulaCliente);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulasClientes[i], cedulaCliente) == 0) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente no encontrado.\n");
        return;
    }

    printf("Ingrese el nombre del producto a comprar: ");
    scanf("%s", nombreProducto);

    int indiceProducto = -1;
    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            indiceProducto = i;
            break;
        }
    }

    if (indiceProducto == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    while (1) {
        printf("Ingrese la cantidad a comprar: ");
        scanf("%d", &cantidadComprar);
        if (cantidadComprar > cantidades[indiceProducto]) {
            printf("Error: no hay suficiente stock. Disponible: %d\n", cantidades[indiceProducto]);
        } else {
            break;
        }
    }

    cantidades[indiceProducto] -= cantidadComprar;
    guardarInventario(nombres, cantidades, precios, numRepuestos);

    obtenerFechaActual(fechas[*numFacturas]);
    strncpy(cedulas[*numFacturas], cedulaCliente, MAX_CEDULA - 1);
    strncpy(nombresClientes[*numFacturas], nombresClientesInventario[indiceProducto], MAX_NOMBRE - 1);
    valoresPagados[*numFacturas] = precios[indiceProducto] * cantidadComprar;
    cantidadesCompradas[*numFacturas] = cantidadComprar;

    (*numFacturas)++;
    printf("Factura creada correctamente.\n");
    guardarFacturas(fechas, cedulas, nombresClientes, valoresPagados, cantidadesCompradas, *numFacturas);
}

void listarFacturas(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    printf("=========================================\n");
    printf("| %-10s | %-10s | %-25s | %-10s | %-10s |\n", "Fecha", "Cédula", "Nombre Cliente", "Valor", "Cantidad");
    printf("=========================================\n");

    for (int i = 0; i < numFacturas; i++) {
        printf("| %-10s | %-10s | %-25s | $%9.2f | %9d |\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
    }

    if (numFacturas == 0) {
        printf("|%-61s|\n", " No hay facturas en la lista.");
    }

    printf("=========================================\n");
}

void buscarFactura(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas) {
    char cedulaBuscar[MAX_CEDULA];

    printf("Ingrese la cédula del cliente para buscar facturas: ");
    scanf("%s", cedulaBuscar);

    printf("=========================================\n");
    printf("| %-10s | %-10s | %-25s | %-10s | %-10s |\n", "Fecha", "Cédula", "Nombre Cliente", "Valor", "Cantidad");
    printf("=========================================\n");

    int facturasEncontradas = 0;
    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(cedulas[i], cedulaBuscar) == 0) {
            printf("| %-10s | %-10s | %-25s | $%9.2f | %9d |\n", fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesCompradas[i]);
            facturasEncontradas++;
        }
    }

    if (facturasEncontradas == 0) {
        printf("|%-61s|\n", " No hay facturas para esta cédula.");
    }

    printf("=========================================\n");
}
