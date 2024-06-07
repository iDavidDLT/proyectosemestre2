#include <stdio.h>
#include <string.h>
#include "inventario.h"

int maxProductos = 20;
int maxNombre = 50;

char nombres[20][50];
int cantidades[20];
float precios[20];

int numRepuestos = 0;

void imprimirMenu() {
    printf("\n=====================================\n");
    printf("|              Menu                 |\n");
    printf("=====================================\n");
    printf("| 1. Ingresar nuevo repuesto        |\n");
    printf("| 2. Editar repuesto                |\n");
    printf("| 3. Eliminar repuesto              |\n");
    printf("| 4. Listar repuestos               |\n");
    printf("| 5. Salir                          |\n");
    printf("=====================================\n");
}

void ingresarRepuesto() {
    if (numRepuestos >= maxProductos) {
        printf("Error: inventario lleno.\n");
        return;
    }

    char nombreNuevo[50];
    int cantidadNueva;
    float precioNuevo;

    printf("Ingrese el nombre del repuesto: ");
    scanf("%s", nombreNuevo);

    // Verificar si el repuesto ya existe
    for (int i = 0; i < numRepuestos; i++) {
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
            return;
        }
    }

    // Agregar el nuevo repuesto
    strcpy(nombres[numRepuestos], nombreNuevo);
    
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

    cantidades[numRepuestos] = cantidadNueva;
    precios[numRepuestos] = precioNuevo;

    numRepuestos++;
    printf("Repuesto ingresado correctamente.\n");
}


void editarRepuesto() {
    char nombreEditar[50];
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
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}


void eliminarRepuesto() {
    char nombreEliminar[50];
    printf("Ingrese el nombre del repuesto a eliminar: ");
    scanf("%s", nombreEliminar);

    for (int i = 0; i < numRepuestos; i++) {
        if (strcmp(nombres[i], nombreEliminar) == 0) {
            for (int j = i; j < numRepuestos - 1; j++) {
                for (int k = 0; k < maxNombre; k++) {
                    nombres[j][k] = nombres[j + 1][k];
                }
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            numRepuestos--;
            printf("Repuesto eliminado correctamente.\n");
            return;
        }
    }

    printf("Repuesto no encontrado.\n");
}

void listarRepuestos() {
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


