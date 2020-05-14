#ifndef PEDPROTOTIPOS_H_INCLUDED
#define PEDPROTOTIPOS_H_INCLUDED

void submenuPedidos();

void submenuClientes();//estuve obligado a poner este encabezado en este archivo, ya que en CltPrototipos.h no lo linkea.

Pedidos cargarPedidos();

bool guardarPedidosEnArchivo(Pedidos );

int cantidadPedidos();

int validarIdCliente(int );

int validarIdPlato(int );

float buscarPrecioDelPlato(int );

void modificarRegistroPedidos();

Pedidos leerRegistroPedidos(int);

bool guardarRegistroActualizadoPedidos(int ,Pedidos);

int mostrarPedidosPorId(int );

void validacionDeMuestraPedido(int );

#endif // PEDPROTOTIPOS_H_INCLUDED
