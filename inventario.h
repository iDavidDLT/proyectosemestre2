#ifndef INVENTARIO_H
#define INVENTARIO_H


extern int maxProductos;
extern int maxNombre;

extern char nombres[20][50];
extern int cantidades[20];
extern float precios[20];

extern int numRepuestos;

void imprimirMenu();
void ingresarRepuesto();
void editarRepuesto();
void eliminarRepuesto();
void listarRepuestos();


#endif

