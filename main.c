#include <stdio.h>
#include "inventario.h"

int main() {
    char predefinidos[5][50] = {"Aceite", "Filtro_de_Aire", "Bujia", "Amortiguador", "Llantas"};
    int cantidadesPredefinidos[5] = {0, 0, 0, 0, 0};
    float preciosPredefinidos[5] = {20.0, 10.0, 5.0, 50.0, 100.0};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < maxNombre; j++) {
            nombres[i][j] = predefinidos[i][j];
        }
        cantidades[i] = cantidadesPredefinidos[i];
        precios[i] = preciosPredefinidos[i];
        numRepuestos++;
    }

    int opcion;

    do {
        imprimirMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarRepuesto();
                break;
            case 2:
                editarRepuesto();
                break;
            case 3:
                eliminarRepuesto();
                break;
            case 4:
                listarRepuestos();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcion != 5);

    return 0;
}



