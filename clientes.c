#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "inventario.h"

void cargarClientes(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int *numClientes) {
    FILE *file = fopen("clientes.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de clientes.\n");
        return;
    }

    *numClientes = 0;
    while (fscanf(file, "%s %s", cedulas[*numClientes], nombresClientes[*numClientes]) != EOF) {
        (*numClientes)++;
    }

    fclose(file);
}

void guardarClientes(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes) {
    FILE *file = fopen("clientes.txt", "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de clientes.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(file, "%s %s\n", cedulas[i], nombresClientes[i]);
    }

    fclose(file);
}

int validarCedula(const char *cedula) {
    
    if (strlen(cedula) != 10) {
        return 0; 
    }
    for (int i = 0; i < 10; i++) {
        if (!isdigit(cedula[i])) {
            return 0; 
        }
    }

    
    int verificador = cedula[9] - '0';
    int sumaPonderada = 0;

    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) { 
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        sumaPonderada += digito;
    }

    int digitoCalculado = 10 - (sumaPonderada % 10);
    if (digitoCalculado == 10) {
        digitoCalculado = 0;
    }

    if (verificador == digitoCalculado) {
        return 1; 
    } else {
        return 0;
    }
}

void ingresarCliente(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int *numClientes) {
    if (*numClientes >= MAX_CLIENTES) {
        printf("Error: lista de clientes llena.\n");
        return;
    }

    char cedulaNueva[MAX_CEDULA];
    char nombreNuevo[MAX_NOMBRE];

    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedulaNueva);

    if (!validarCedula(cedulaNueva)) {
        printf("Error: cédula no válida.\n");
        return;
    }

    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(cedulas[i], cedulaNueva) == 0) {
            printf("Error: cédula ya registrada.\n");
            return;
        }
    }

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombreNuevo);

    strcpy(cedulas[*numClientes], cedulaNueva);
    strcpy(nombresClientes[*numClientes], nombreNuevo);

    (*numClientes)++;
    printf("Cliente ingresado correctamente.\n");
    guardarClientes(cedulas, nombresClientes, *numClientes);
}

void editarCliente(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int numClientes) {
    char cedulaEditar[MAX_CEDULA];
    char nuevoNombre[MAX_NOMBRE];

    printf("Ingrese la cédula del cliente a editar: ");
    scanf("%s", cedulaEditar);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedulaEditar) == 0) {
            printf("Ingrese el nuevo nombre del cliente: ");
            scanf("%s", nuevoNombre);

            strcpy(nombresClientes[i], nuevoNombre);
            printf("Cliente editado correctamente.\n");
            guardarClientes(cedulas, nombresClientes, numClientes);
            return;
        }
    }

    printf("Cliente no encontrado.\n");
}

void consultarCliente(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes) {
    char cedulaBuscar[MAX_CEDULA];

    printf("Ingrese la cédula del cliente a consultar: ");
    scanf("%s", cedulaBuscar);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(cedulas[i], cedulaBuscar) == 0) {
            printf("Cliente encontrado:\n");
            printf("Cédula: %s\n", cedulas[i]);
            printf("Nombre: %s\n", nombresClientes[i]);
            return;
        }
    }

    printf("Cliente no encontrado.\n");
}

void listarClientes(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes) {
    printf("====================================\n");
    printf("| %-10s | %-25s |\n", "Cédula", "Nombre");
    printf("====================================\n");

    for (int i = 0; i < numClientes; i++) {
        printf("| %-10s | %-25s |\n", cedulas[i], nombresClientes[i]);
    }

    if (numClientes == 0) {
        printf("|%-37s|\n", " No hay clientes en la lista.");
    }

    printf("====================================\n");
}
