#ifndef CONFIGURACION_H
#define CONFIGURACION_H

void backupDeArchivoPlatos();
void backupDeArchivoClientes();
void backupDeArchivoPedidos();
void restaurarArchivoPlatos();
void restaurarArchivoClientes();
void restaurarArchivoPedidos();

void backupDeArchivos()
{
    bool seguir=false;
    char n[6];
    int op;
    int c;
    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(33)<<"\t B   A   C   K   U   P   S "<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- REALIZAR BACKUP DE PLATOS        "<<endl;
        cout<<"\t            2.- REALIZAR BACKUP DE CLIENTES     "<<endl;
        cout<<"\t            3.- REALIZAR BACKUP DE PEDIDOS     "<<endl;
        cout<<"\t            0.- SALIR                                             "<<endl;
        cout<<"\t";
        linea();
        cout<<endl;
        cout<<setw(20)<<"\tIngrese una opción: ";
        cin.getline(n,5);
        system("cls");
        if(validarOpcion(n) )
        {
            op=atoi(n);
            switch(op)
            {
                case 1:
                {
                    cout<<"\tCONFIRME LA COPIA DE SEGURIDAD (1: si / 0: no) : ";
                    cin>>c;
                    if(c==1)
                    {
                        backupDeArchivoPlatos();
                        barraDeCarga();
                        cin.ignore();
                    }
                }
                break;
                case 2:
                {
                    cout<<"\tCONFIRME LA COPIA DE SEGURIDAD (1: si / 0: no) : ";
                    cin>>c;
                    if(c==1)
                    {
                        backupDeArchivoClientes();
                        barraDeCarga();
                        cin.ignore();
                    }
                }
                break;
                case 3:
                {
                    cout<<"\tCONFIRME LA COPIA DE SEGURIDAD (1: si / 0: no) : ";
                    cin>>c;
                    if(c==1)
                    {
                        backupDeArchivoPedidos();
                        barraDeCarga();
                        cin.ignore();
                    }
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
             cin.ignore();
            }
        }
    }
}
void restaurarArchivos()
{
    bool seguir=false;
    char n[6];
    int op;
    char c;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(33)<<"\t R   E   S   T   A   U   R   A   C   I   Ó   N "<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- RESTAURAR ARCHIVO PLATOS      "<<endl;
        cout<<"\t            2.- RESTAURAR ARCHIVO CLIENTES "<<endl;
        cout<<"\t            3.- RESTAURAR ARCHIVO PEDIDOS "<<endl;
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
                     cin.ignore();
                    cout<<"\tCONFIRME LA RESTAURACIÓN (S/N) : ";
                    cin>>c;
                    if(c=='s'|| c=='S')
                    {
                        restaurarArchivoPlatos();
                         barraDeCarga1();
                         cin.ignore();
                    }
                }
                break;
                case 2:
                {
                     cin.ignore();
                    cout<<"\tCONFIRME LA RESTAURACIÓN (S/N) : ";
                    cin>>c;
                    if(c=='s'|| c=='S')
                    {
                        restaurarArchivoClientes();
                        barraDeCarga1();
                        cin.ignore();
                    }
                }
                break;
                case 3:
                {
                    cin.ignore();
                    cout<<"\tCONFIRME LA COPIA DE SEGURIDAD (S/N) : ";
                    cin>>c;
                    if(c=='s'|| c=='S')
                    {
                        restaurarArchivoPedidos();
                        barraDeCarga1();
                        cin.ignore();
                    }
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

void backupDeArchivoPlatos()
{
    Platos plt;
    FILE *p,*bkp;
    p=fopen(PLATOS,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    bkp=fopen(PLATOSbkp,"wb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }

    while(fread(&plt,sizeof(Platos),1,p))
        fwrite(&plt,sizeof(Platos),1,bkp);
    fclose(p);
    fclose(bkp);

    return;
}

void backupDeArchivoClientes()
{
    Clientes clt;
    FILE *p,*bkp;
    p=fopen(CLIENTES,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    bkp=fopen(CLIENTESbkp,"wb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }

    while(fread(&clt,sizeof(Clientes),1,p))
        fwrite(&clt,sizeof(Clientes),1,bkp);
    fclose(p);
    fclose(bkp);

    return;
}

void backupDeArchivoPedidos()
{
    Pedidos ped;
    FILE *p,*bkp;
    p=fopen(PEDIDOS,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    bkp=fopen(PEDIDOSbkp,"wb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    while(fread(&ped,sizeof(Pedidos),1,p))
        fwrite(&ped,sizeof(Pedidos),1,bkp);
    fclose(p);
    fclose(bkp);

    return;
}

void restaurarArchivoPlatos()
{
    Platos plt;
    FILE *bkp,*p;
    bkp=fopen(PLATOSbkp,"rb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    p=fopen(PLATOS,"wb");
    if(p=NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    while(fread(&plt,sizeof(Pedidos),1,bkp))
        fwrite(&plt,sizeof(Pedidos),1,p);
    fclose(p);
    fclose(bkp);

    return;
}

void restaurarArchivoClientes()
{
    Clientes clt;
    FILE *bkp,*p;
    bkp=fopen(CLIENTESbkp,"rb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    p=fopen(CLIENTES,"wb");
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    while(fread(&clt,sizeof(Clientes),1,bkp))
        fwrite(&clt,sizeof(Clientes),1,p);
    fclose(p);
    fclose(bkp);

    return;
}

void restaurarArchivoPedidos()
{
    Pedidos ped;
    FILE *bkp,*p;
    bkp=fopen(PEDIDOSbkp,"rb");
    if(bkp==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    p=fopen(PEDIDOS,"wb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return;
    }
    while(fread(&ped,sizeof(Pedidos),1,bkp))
        fwrite(&ped,sizeof(Pedidos),1,p);
    fclose(p);
    fclose(bkp);
    return;
}
void mostrarArchivoBkpPlatos()
{
    Platos plt;
    FILE *p;
    p=fopen(PLATOSbkp,"rb");
    if(p==NULL) return;
     cout<<"\n";
    cout<<"\tID "<<setw(4)<<"|"<<setw(18)<<" NOMBRE "<<setw(2)<<"|"<<" COSTO($)"<<setw(2)<<"|"<<" VENTA($)";
    cout<<setw(4)<<"|"<<" TIEMPO PREPACIÓN(min) "<<setw(2)<<"|"<<" ID RESTAURANTE "<<setw(2)<<"|"<<" COMISIÓN(%)"<<setw(2)<<"|"<<" ID CATEGORÍA "<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&plt,sizeof(Platos),1,p))
    {
        cout<<"\t"<<setw(4)<<left<<plt.id_plato<<" "<<setw(22)<<plt.nombre<<" "<<setw(15)<<plt.costo_preparacion<<" ";
        cout<<setw(15)<<plt.valor_venta<<" "<<setw(20)<<plt.tiempo_preparacion<<"  "<<setw(15)<<plt.id_restaurante<<"   ";
        cout<<setw(7)<<plt.comision_restaurante<<"   "<<setw(2)<<plt.id_categoria<<endl;
        cout<<"\t";
        linea1();
        cout<<endl;
    }
    fclose(p);

}

void mostrarArchivoBkpClientes()
{
    Clientes clt;
    FILE *p;
    p=fopen(CLIENTESbkp,"rb");
    if(p==NULL)return;
    cout<<"\n";
    cout<<"\tID "<<setw(2)<<"| "<<setw(10)<<" NOMBRES "<<setw(10)<<" |"<<setw(8)<<" APELLIDOS "<<setw(8)<<" |"<<setw(15)<<" MAIL";
    cout<<setw(15)<<" |"<<setw(20)<<" DOMICILIO "<<setw(15)<<" |"<<setw(2)<<" COD. POSTAL "<<setw(3)<<" |"<<" FECHA DE NAC. "<<setw(5)<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&clt,sizeof(Clientes),1,p))
    {
        if(clt.estado)
        {
            cout<<"\t"<<setw(3)<<left<<clt.id_cliente<<" "<<setw(20)<<clt.nombre<<" "<<setw(20)<<clt.apellido<<" ";
            cout<<setw(30)<<clt.mail<<" "<<setw(35)<<clt.domicilio<<" "<<setw(10)<<clt.cod_postal<<"   ";
            cout<<clt.fec.dia<<"/"<<clt.fec.mes<<"/"<<clt.fec.anio<<endl;
            cout<<"\t";linea1();
            cout<<endl;
        }
    }
    fclose(p);
}

void mostrarArchivoBkpPedidos()
{
    Pedidos ped;
    FILE *p;
    p=fopen(PEDIDOSbkp,"rb");
    if(p==NULL)return;
     cout<<"\n";
    cout<<"\tID "<<setw(3)<<"| "<<setw(3)<<" ID CLIENTE "<<setw(3)<<" |"<<setw(3)<<" ID PLATO "<<setw(3)<<" |"<<setw(5)<<" CANTIDAD ";
    cout<<setw(3)<<" |"<<setw(5)<<" PRECIO "<<setw(3)<<" |"<<setw(5)<<" FECHA DE NAC. "<<setw(3)<<" | "<<setw(5)<<" VALORACIÓN "<<setw(3)<<" | "<<setw(3)<<" ESTADO "<<setw(3)<<" | "<<endl;
    cout<<"\t";linea2();
    cout<<endl;
    while(fread(&ped,sizeof(Pedidos),1,p))
    {
        if(ped.id_clt>0 && ped.id_pedido>0 && ped.id_plt>0)
        {
            if(ped.estado>=1 || ped.estado <=3 )
            {
                cout<<"\t "<<setw(10)<<left<<ped.id_pedido<<" "<<setw(12)<<ped.id_clt<<" "<<setw(13)<<ped.id_plt<<" ";
                cout<<setw(8)<<ped.cantidad<<" "<<setw(9)<<ped.precio_unitario<<"  "<<ped.fec.dia<<"/";
                cout<<ped.fec.mes<<"/"<<setw(15)<<ped.fec.anio<<" "<<setw(12)<<ped.valoracion<<" "<<ped.estado<<endl;
                cout<<"\t";linea2();
                cout<<endl;
            }
        }
    }
    fclose(p);
}
#endif // CONFIGURACION_H
