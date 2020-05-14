#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

Pedidos cargarPedidos()
{
    Pedidos ped;
    int c,id;
    bool existe=true;

    cout<<"\n\tINGRESE EL ID DE CLIENTE: ";
    cin>>id;
    while(id<=0)
    {
        cout<<"\t [ ID tiene que ser mayor a 0 ]"<<endl;
        cin.get();
        cin.ignore();
        system("cls");
        cout<<"\tINGRESE EL ID DE CLIENTE: ";
        cin>>id;
    }
    c=validarIdCliente(id);
     if(c==-2)
    {
            cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE"<<endl;
            ped.id_clt=-2;
            cin.ignore();
            return ped;
    }
    if(c==-1)
    {
            cout<<"\n\tCLIENTE FUE DADO DE BAJA O NO EXISTE"<<endl;
            ped.id_clt=0;
            cin.ignore();
            return ped;
    }
    if(c==1) ped.id_clt=id;

    int p, cod;
    cout<<"\tINGRESE EL ID DEL PLATO: ";
    cin>>cod;

    while(cod<=0)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ ID tiene que ser mayor a 0 ]"<<endl;
        cout<<"\tINGRESE EL ID DEL PLATO: ";
        cin>>cod;
    }
    p=validarIdPlato(cod);
    if(p==-2)
    {
        cout<<"\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE"<<endl;
        ped.id_plt=-2;
        cin.ignore();
        return ped;
    }
    if(p==-1)
    {
        cout<<"\tID DE PLATO FUE DADO DE BAJA O NO EXISTE"<<endl;
        ped.id_plt=0;
        cin.ignore();
        return ped;
    }
    if(p==1)ped.id_plt=cod;

    cout<<"\tCANTIDAD DE PEDIDO: ";
    cin>>ped.cantidad;
    while(ped.cantidad<0)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ CANTIDAD tiene que ser mayor a 0 ]"<<endl;
        cout<<"\tCANTIDAD DE PEDIDOS: ";
        cin>>ped.cantidad;
    }

    ped.precio_unitario=buscarPrecioDelPlato(ped.id_plt);

    cout<<"\tDÍA DEL PEDIDO: ";
    cin>>ped.fec.dia;
     while(ped.fec.dia<=0 || ped.fec.dia>=32)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ DÍA tiene que estar desde 1 - 31 ]"<<endl;
        cout<<"\tDIA DE PEDIDO : ";
        cin>>ped.fec.dia;
    }
    cout<<"\tMES DEL PEDIDO: ";
    cin>>ped.fec.mes;
     while(ped.fec.mes<=0 || ped.fec.mes>=13)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ MES tiene que estar desde 1 - 12 ]"<<endl;
        cout<<"\tMES DE PEDIDO : ";
        cin>>ped.fec.mes;
    }
    cout<<"\tAÑO DEL PEDIDO: ";
    cin>>ped.fec.anio;
     while(ped.fec.anio>2020)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ AÑO tiene que ser igual a 2020 ]"<<endl;
        cout<<"\tAÑO DE PEDIDO : ";
        cin>>ped.fec.anio;
    }

    cout<<"\tVALORACIÓN :";
    cin>>ped.valoracion;
    while(ped.valoracion<0 || ped.valoracion>10)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ VALORACIÓN tiene que estar desde 1 - 10 ]"<<endl;
        cout<<"\tVALORACIÓN :";
        cin>>ped.valoracion;
    }

    cout<<"\tESTADO DE PREPARACIÓN : ";
    cout<<ped.estado;
    while(ped.estado>3)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
        cout<<"\t [ ESTADO tiene que estar desde 1 - 3 ]"<<endl;
        cout<<"\tESTADO DE PREPARACIÓN : ";
        cout<<ped.estado;
    }
    cin.ignore();
    return ped;
}
bool guardarPedidosEnArchivo(Pedidos ped)
{
    FILE *p;
    p=fopen(PEDIDOS,"ab");
    if(p==NULL) return false;
    ///Este if () filtra lo valores de los variables que son distintos a los que están asignados por default. Asi no se guarda un regristro vacío.
    if(ped.cantidad>0) ped.id_pedido=cantidadPedidos()+1;
    fwrite(&ped,sizeof(Pedidos),1,p);
    fclose(p);

    return true;
}
int cantidadPedidos()
{
    int pos, tam, id;
    FILE *p;
    p=fopen(PEDIDOS,"ab");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return -1;
    }
    fseek(p,0,SEEK_END);
    pos=ftell(p);
    tam=sizeof(Pedidos);
    id=(pos/tam);
    fclose(p);
    return id;
}
void modificarRegistroPedidos()
{
    Pedidos ped;
    int id,pos;
    cout<<"\n\tINGRESE EL ID DE PEDIDO: ";
    cin>>id;
    pos=mostrarPedidosPorId(id);
    if(pos==-2)
    {
        cout<<"ERROR : ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.ignore();
        return;
    }
    else
    {
        cout<<"\n\tID DE PEDIDO NO EXISTE"<<endl;
        cin.ignore();
        return;
    }
    ped=leerRegistroPedidos(pos);
    mostrarPedidosPorId(id);
    cin.ignore();
    cout<<"\n\tESTADO DE PEDIDO : ";
    cin>>ped.estado;
    if(guardarRegistroActualizadoPedidos(pos,ped))
        cout<<"\n\tREGISTRO ACTUALIZADO CORRECTAMENTE"<<endl;
    else
        cout<<"ERROR : NO SE PUDO GUARDAR CAMBIOS. ARCHIVO NO EXITE "<<endl;
}

Pedidos leerRegistroPedidos(int pos)
{
    Pedidos ped;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if(p==NULL)
    {
        ped.cantidad=-1;
        return ped;
    }
    fseek(p,pos*sizeof(Pedidos),SEEK_SET);
    fread(&ped,sizeof(Pedidos),1,p);
    fclose(p);
    return ped;
}

bool guardarRegistroActualizadoPedidos(int pos,Pedidos ped)
{
    FILE *p;
    p=fopen(PEDIDOS,"rb+");
    if(p==NULL)
        return false;
    fseek(p,pos*sizeof(Pedidos),SEEK_SET);
    fwrite(&ped,sizeof(Pedidos),1,p);
    fclose(p);

    return true;
}

int mostrarPedidosPorId(int id)
{
    int i=0;
    Pedidos ped;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if(p==NULL)
        return -2;
     cout<<"\n";
    cout<<"\tID "<<setw(3)<<"| "<<setw(5)<<" ID CLIENTE "<<setw(3)<<" |"<<setw(5)<<" ID PLATO "<<setw(3)<<" |"<<setw(5)<<" CANTIDAD ";
    cout<<setw(3)<<" |"<<setw(5)<<" PRECIO "<<setw(3)<<" |"<<setw(5)<<" FECHA DE NAC. "<<setw(3)<<" | "<<setw(5)<<" VALORACIÓN "<<setw(3)<<" | "<<setw(3)<<" ESTADO "<<setw(3)<<" | "<<endl;
    cout<<"\t";linea2();
    cout<<endl;
    while(fread(&ped,sizeof(Pedidos),1,p))
    {
        if(id==ped.id_pedido &&(ped.estado>=1 || ped.estado <=3))
        {
            cout<<"\t "<<setw(10)<<left<<ped.id_pedido<<" "<<setw(12)<<ped.id_clt<<" "<<setw(13)<<ped.id_plt<<" ";
            cout<<setw(8)<<ped.cantidad<<" "<<setw(9)<<ped.precio_unitario<<"  "<<ped.fec.dia<<"/";
            cout<<ped.fec.mes<<"/"<<ped.fec.anio<<" "<<setw(12)<<ped.valoracion<<" "<<ped.estado<<endl;
            cout<<"\t";linea2();
            cout<<endl;
            fclose(p);
            cin.get();
            return i; ///retorna la posicion del registro para ser usado en la funcion de modificar o dar de baja registro.
        }
        i++;
    }
    fclose(p);
    system("cls");
    return -1;
}

void mostrarArchivoPedidos()
{
    Pedidos ped;
    FILE *p;
    p=fopen(PEDIDOS,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR : ARCHIVO NO ENCONTRADO O NO EXISTE "<<endl;
        return ;
    }
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
    return;
}

#endif // PEDIDOS_H_INCLUDED
