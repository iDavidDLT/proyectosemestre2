#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100
#define MAX_NOMBRE 100
#define MAX_CEDULA 11

// Funciones de inventario (productos)
void cargarInventario(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void guardarInventario(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);
void ingresarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void editarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numRepuestos);
void eliminarRepuesto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *numRepuestos);
void listarRepuestos(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);
void buscarRepuesto(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int numRepuestos);

// Funciones de clientes
void cargarClientes(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int *numClientes);
void guardarClientes(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes);
int validarCedula(const char *cedula);
void ingresarCliente(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int *numClientes);
void editarCliente(char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], int numClientes);
void consultarCliente(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes);
void listarClientes(const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], int numClientes);

// Funciones de facturas
void cargarFacturas(char fechas[][20], char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], float valoresPagados[], int cantidadesCompradas[], int *numFacturas);
void guardarFacturas(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);
void crearFactura(char fechas[][20], char cedulas[][MAX_CEDULA], char nombresClientes[][MAX_NOMBRE], float valoresPagados[], int cantidadesCompradas[], int *numFacturas, const char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int numRepuestos, const char cedulasClientes[][MAX_CEDULA], const char nombresClientesFactura[][MAX_NOMBRE], int numClientes);
void listarFacturas(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);
void buscarFactura(const char fechas[][20], const char cedulas[][MAX_CEDULA], const char nombresClientes[][MAX_NOMBRE], const float valoresPagados[], const int cantidadesCompradas[], int numFacturas);
