#ifndef MENUPINCIPAL_H_INCLUDED
#define MENUPINCIPAL_H_INCLUDED

void submenuConfiguracion();

void menuPrincipal()
{
    bool seguir=false;
    char n[6];
    int op;
    char a=92;
    putchar('\n');
    putchar('\n');
    putchar('\n');
    putchar('\t');
    putchar('\t');
    cout<<"  ";linea();
    putchar('\t');
    putchar('\t');
    cout<<endl;
    cout<<endl;
    cout<<"\t\t"<<setw(33)<<"========"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<a<<a<<"   "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<setw(2)<<a<<a<<"  "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<setw(3)<<a<<a<<" "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"======"<<"  "<<" || "<<"  "<<"||"<<setw(4)<<a<<a<<""<<"||"<<endl;
    cout<<"\n\t\t"<<setw(35)<<"\tFACULTAD  REGIONAL  GENERAL  PACHECO"<<endl;
    cout<<"\t\t"<<setw(35)<<"\t TRABAJO PRÁCTICO #1"<<endl;
    putchar('\t');
    putchar('\t');
    cout<<"  ";linea();
    cin.ignore();
    system("cls");
    while(!seguir)
    {
        putchar('\n');
        putchar('\t');
        //linea();
        cout<<setw(26)<<"\tL  A  R  A"<<endl;
        cout<<setw(45)<<"\t  Aplicación de pedidos de comida online"<<endl;
        putchar('\t');
        linea();
        cout<<endl;
        cout<<endl;
        cout <<"\t\t    1.- PLATOS                               "<<endl;
        cout <<"\t\t    2.- CLIENTES                            "<<endl;
        cout <<"\t\t    3.- PEDIDOS                             "<<endl;
        cout <<"\t\t    4.- REPORTES                           "<<endl;
        cout <<"\t\t    5.- CONFIGURACIÓN                 "<<endl;
        cout <<"\t\t    0.- SALIR                                  "<<endl;
        putchar('\t');
        linea();
        putchar('\n');
        cout<<"\tIngrese una opción: ";
        cin.getline(n,5);
        system("cls");
        if(validarOpcion(n))
        {
            op=atoi(n);
            switch(op)
            {
                case 1:
                {
                    submenuPlatos();
                }
                break;
                case 2:
                {
                    submenuClientes();
                }
                break;
                case 3:
                {
                   submenuPedidos();

                }
                break;
                case 4:
                {

                }
                case 5:
                {
                    submenuConfiguracion();

                }
                break;
                case 0:
                {
                    system("cls");
                    seguir=true;
                }
                break;
                default:
                {
                    cout<<"\tOPCIÓN INCORRECTA"<<endl;
                }
            cin.ignore();
            }
        }
    }
}
#endif // MENUPINCIPAL_H_INCLUDED
