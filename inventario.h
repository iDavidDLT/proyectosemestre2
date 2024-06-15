#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 20
#define MAX_NOMBRE 50

// Declaración de funciones
void imprimirMenu();
void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void guardarInventario(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);
void ingresarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void editarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numRepuestos);
void eliminarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void listarRepuestos(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);
void buscarRepuesto(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);

#endif
