#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED

void submenuClientes()
{
    Clientes clt;
    bool seguir=false;
    char n[6];
    int op;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(10)<<" "<<"\t C   L   I   E   N   T   E   S"<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- NUEVO CLIENTE                     "<<endl;
        cout<<"\t            2.- MODIFICAR CLIENTE              "<<endl;
        cout<<"\t            3.- LISTAR CLIENTE POR ID             "<<endl;
        cout<<"\t            4.- LISTAR TODOS LOS CLIENTES  "<<endl;
        cout<<"\t            5.- ELIMINAR CLIENTE                 "<<endl;
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
                    clt=cargarClientes();
                    if(guardarClientesEnArchivo(clt))
                        cout<<"\n\tCLIENTE REGISTRADO CORRECTAMENTE"<<endl;
                    else
                        cout<<"\n\tERROR AL GUARDAR REGISTRO"<<endl;
                    cin.ignore();
                }
                break;
                case 2:
                {
                    modificarRegistroClientes();
                    cin.ignore();
                }
                break;
                case 3:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE CLIENTE : ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestraCliente(id);
                }
                break;
                case 4:
                {
                    mostrarArchivoClientes();
                    cin.ignore();
                }
                break;
                 case 5:
                {
                    bajaLogicoDeRegistroClientes ();
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


#endif // SUBMENUCLIENTES_H_INCLUDED
