#include <stdio.h>
#include <string.h>
#include "inventario.h"


void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos) {
    FILE *file = fopen("inventario.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    *numRepuestos = 0;
    while (fscanf(file, "%s %d %f", nombres[*numRepuestos], &cantidades[*numRepuestos], &precios[*numRepuestos]) != EOF) {
        (*numRepuestos)++;
    }

    fclose(file);
}

void guardarInventario(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos) {
    FILE *file = fopen("inventario.txt", "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    for (int i = 0; i < numRepuestos; i++) {
        fprintf(file, "%s %d %f\n", nombres[i], cantidades[i], precios[i]);
    }

    fclose(file);
}

void ingresarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos) {
    if (*numRepuestos >= MAX_PRODUCTOS) {
        printf("Error: inventario lleno.\n");
        return;
    }

    char nombreNuevo[MAX_NOMBRE];
    int cantidadNueva;
    float precioNuevo;

    printf("Ingrese el nombre del repuesto: ");
    scanf("%s", nombreNuevo);

    // Verificar si el repuesto ya existe
    for (int i = 0; i < *numRepuestos; i++) {
        if (strcmp(nombres[i], nombreNuevo) == 0) {
            while (1) {
                printf("Ingrese la cantidad adicional: ");
                scanf("%d", &cantidadNueva);
                if (cantidadNueva < 0) {
                    printf("Error: la cantidad no puede ser negativa. Intente de nuevo.\n");
                } else {
                    break;
                }
            }
            cantidades[i] += cantidadNueva;
            printf("Cantidad actualizada correctamente.\n");
            guardarInventario(nombres, cantidades, precios, *numRepuestos);
            return;
        }
    }

    // Agregar el nuevo repuesto
    strcpy(nombres[*numRepuestos], nombreNuevo);

    // Verificar la cantidad ingresada
    while (1) {
        printf("Ingrese la cantidad: ");
        scanf("%d", &cantidadNueva);
        if (cantidadNueva < 0) {
            printf("Error: la cantidad no puede ser negativa. Intente de nuevo.\n");
        } else {
            break;
        }
    }

    // Verificar el precio ingresado
    while (1) {
        printf("Ingrese el precio: ");
        scanf("%f", &precioNuevo);
        if (precioNuevo < 0) {
            printf("Error: el precio no puede ser negativo. Intente de nuevo.\n");
        } else {
            break;
        }
    }

    cantidades[*numRepuestos] = cantidadNueva;
    precios[*numRepuestos] = precioNuevo;

    (*numRepuestos)++;
    printf("Repuesto ingresado correctamente.\n");
    guardarInventario(nombres, cantidades, precios, *numRepuestos);
}

void editarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numRepuestos) {
    char nombreEditar[MAX_NOMBRE];
    int nuevaCantidad;

    printf("Ingrese el nombre del repuesto a editar: ");
    scanf("%s", nombreEditar);

    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreEditar) == 0) {
            while (1) {
                printf("Ingrese la nueva cantidad: ");
                scanf("%d", &nuevaCantidad);
                if (nuevaCantidad < 0) {
                    printf("Error: la cantidad no puede ser negativa. Intente de nuevo.\n");
                } else {
                    break;
                }
            }
            cantidades[i] = nuevaCantidad;
            printf("Repuesto editado correctamente.\n");
            guardarInventario(nombres, cantidades, precios, numRepuestos);
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}

void eliminarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos) {
    char nombreEliminar[MAX_NOMBRE];
    printf("Ingrese el nombre del repuesto a eliminar: ");
    scanf("%s", nombreEliminar);

    for (int i = 0; i < *numRepuestos; i++) {
        if (strcmp(nombres[i], nombreEliminar) == 0) {
            for (int j = i; j < *numRepuestos - 1; j++) {
                for (int k = 0; k < MAX_NOMBRE; k++) {
                    nombres[j][k] = nombres[j + 1][k];
                }
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            (*numRepuestos)--;
            printf("Repuesto eliminado correctamente.\n");
            guardarInventario(nombres, cantidades, precios, *numRepuestos);
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}

void listarRepuestos(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos) {
    printf("=======================================================\n");
    printf("| %-25s | %10s | %10s | %10s |\n", "Nombre del Repuesto", "Cantidad", "Precio", "Total");
    printf("=======================================================\n");

    for (int i = 0; i < numRepuestos; i++) {
        float total = cantidades[i] * precios[i];
        printf("| %-25s | %10d | $%9.2f | $%9.2f |\n", nombres[i], cantidades[i], precios[i], total);
    }

    if (numRepuestos == 0) {
        printf("|%-57s|\n", " No hay repuestos en el inventario.");
    }

    printf("=======================================================\n");
}

void buscarRepuesto(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos) {
    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del repuesto a buscar: ");
    scanf("%s", nombreBuscar);

    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("=======================================================\n");
            printf("| %-25s | %10s | %10s | %10s |\n", "Nombre del Repuesto", "Cantidad", "Precio", "Total");
            printf("=======================================================\n");
            float total = cantidades[i] * precios[i];
            printf("| %-25s | %10d | $%9.2f | $%9.2f |\n", nombres[i], cantidades[i], precios[i], total);
            printf("=======================================================\n");
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}
