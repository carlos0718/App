#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void submenuConfiguracion()
{
    bool seguir=false;
    char n[6];
    int op;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(33)<<"\t C   O   N   F   I   G   U   R   A   C   I   Ó   N  "<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- REALIZAR COPIA DE SEGURIDAD    "<<endl;
        cout<<"\t            2.- RESTAURAR COPIA DE SEGURIDAD "<<endl;
        cout<<"\t            0.- SALIR                                              "<<endl;
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
                    backupDeArchivos();
                    cin.ignore();
                }
                break;
                case 2:
                {
                    restaurarArchivos();
                    cin.ignore();
                }
                break;
                 case 3:
                {
                    mostrarArchivoBkpPlatos();
                    cin.ignore();
                    system("cls");
                    mostrarArchivoBkpClientes();
                    cin.ignore();
                    system("cls");
                    mostrarArchivoBkpPedidos();
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
            }
        }
    }
}

#endif // SUBMENUCONFIGURACION_H_INCLUDED
