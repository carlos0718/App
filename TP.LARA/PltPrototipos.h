#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct Platos cargarPlatos();

struct Platos leerRegistroPlatos(int);

bool guardarPlatosEnArchivo(Platos);

int mostrarPlatosPorId(int );

int cantidadPlatos();

void modificarRegistroPlatos();

bool guardarRegistroActualizado(int,Platos);

void validacionDeMuestra(int );

void mostrarArchivoPlatos();

void validacionDeMuestraRestaurante(int );

int mostrarPlatosPorRestaurante(int );

void bajaLogicoDeRegistroPlatos();

bool validarNombrePlatos(char *);

void menuPrincipal();

void submenuPlatos();

void linea();

void linea1();

#endif // PROTOTIPOS_H_INCLUDED
