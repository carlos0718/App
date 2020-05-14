#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
struct Platos
{
    int id_plato=0;
    char nombre[50]={'\0'};
    float costo_preparacion=0;
    float valor_venta=0;
    int tiempo_preparacion=0;
    int id_restaurante=0;
    int comision_restaurante=0;
    int id_categoria=0;
    bool estado=true;
};

struct Fecha
{
    int dia=0, mes=0,anio=0;
};

struct Clientes
{
    int id_cliente=0;
    char nombre[50]={'\0'};
    char apellido[50]{'\0'};
    char mail[50]{'\0'};
    char domicilio[100]{'\0'};
    int cod_postal=0;
    Fecha fec;
    bool estado=true;
};

struct Pedidos
{
    int id_pedido=0;
    int id_clt=0;
    int id_plt=0;
    int cantidad=0;
    float precio_unitario=0;
    Fecha fec;
    float valoracion=0;
    int estado=1; ///indica el estado de preparacion del plato 1: en espera, 2: completado, 3: cancelado.
};
#endif // STRUCT_H_INCLUDED
