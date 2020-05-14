#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED


void submenuClientes();

struct Clientes cargarClientes();

struct Clientes leerRegistroClientes(int );

bool guardarClientesEnArchivo( Clientes);

int mostrarClientesPorId(int );

void modificarRegistroClientes();

bool guardarRegistroActualizadoCliente(int ,Clientes);

void mostrarArchivoClientes();

void bajaLogicoDeRegistroClientes();

bool validarMail(char *);

void validacionDeMuestraCliente(int );

int cantidadClientes();



#endif // PROTOTIPOS_H_INCLUDED
