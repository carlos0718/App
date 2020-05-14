#ifndef SUBMENUPLATOS_H_INCLUDED
#define SUBMENUPLATOS_H_INCLUDED

void submenuPlatos()
{
    Platos plt;
    bool seguir=false;
    char n[6];
    int op;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(33)<<"\t P  L  A  T  O  S"<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- NUEVO PLATO                      "<<endl;
        cout<<"\t            2.- MODIFICAR PLATO                "<<endl;
        cout<<"\t            3.- LISTAR PLATO POR ID            "<<endl;
        cout<<"\t            4.- PLATOS POR RESTAURANT    "<<endl;
        cout<<"\t            5.- LISTAR TODOS LOS PLATOS   "<<endl;
        cout<<"\t            6.- ELIMINAR PLATO                  "<<endl;
        cout<<"\t            0.- SALIR                                    "<<endl;
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
                    plt=cargarPlatos();
                    if(guardarPlatosEnArchivo(plt))
                        cout<<"\n\tPLATO REGISTRADO CORRECTAMENTE"<<endl;
                    else
                        cout<<"\n\tERROR AL GUARDAR REGISTRO"<<endl;
                    cin.ignore();
                }
                break;
                case 2:
                {
                    modificarRegistroPlatos();
                    cin.ignore();
                }
                break;
                case 3:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE PLATO : ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestra(id);
                }
                break;
                case 4:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE RESTAURANTE: ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestraRestaurante(id);
                }
                break;
                 case 5:
                {
                    mostrarArchivoPlatos();
                    cin.ignore();

                }
                break;
                case 6:
                {
                    bajaLogicoDeRegistroPlatos();
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



#endif // SUBMENUPLATOS_H_INCLUDED
