#ifndef SUBMENUPEDIDOS_H_INCLUDED
#define SUBMENUPEDIDOS_H_INCLUDED

void submenuPedidos()
{
    Pedidos ped;
    bool seguir=false;
    char n[6];
    int op;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(10)<<" "<<"\t P  E   D   I   D   O   S"<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- NUEVO PEDIDO                    "<<endl;
        cout<<"\t            2.- MODIFICAR PEDIDO              "<<endl;
        cout<<"\t            3.- LISTAR PEDIDO POR ID             "<<endl;
        cout<<"\t            4.- LISTAR TODOS LOS PEDIDOS  "<<endl;
        cout<<"\t            0.- SALIR                                     "<<endl;
        cout<<"\t";
        linea();
        cout<<endl;
        cout<<setw(20)<<"\tIngrese una opción: ";
        cin.getline(n,5);
        system("cls");
        if(validarOpcion(n))
        {
            op=atoi(n);
            switch(op)
            {
                case 1:
                {
                    ped=cargarPedidos();
                    if(guardarPedidosEnArchivo(ped)&&ped.cantidad!=0)
                        cout<<"\n\t\tPEDIDO REGISTRADO CORRECTAMENTE"<<endl;
                    else
                        cout<<"\n\t\tERROR AL GUARDAR REGISTRO"<<endl;
                    cin.ignore();
                }
                break;
                case 2:
                {
                    modificarRegistroPedidos();
                    cin.ignore();
                }
                break;
                case 3:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE PEDIDO : ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestraPedido(id);
                }
                break;
                case 4:
                {
                    mostrarArchivoPedidos();
                    cin.ignore();
                }
                break;
                case 0:
                {
                    seguir=true;
                }
                break;
                default:
                {
                    cout<<"\tOPCIÓN INCORRECTA"<<endl;
                }
             cin.get();
             system("cls");
            }
        }
    }
}



#endif // SUBMENUPEDIDOS_H_INCLUDED
