#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int mostrarClientesPorId(int );

bool validarNombrePlatos(char n[50])
{
    Platos plt;
    FILE *p;
    p=fopen(PLATOS,"rb");
    if(p==NULL)
        return false;
    while(fread(&plt,sizeof(Platos),1,p))
    {
        if(strcmp(n,plt.nombre)==0)
        {
            cout<<"\n\tNOMBRE DE PLATO YA EXISTE"<<endl;
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

void linea()
{
    for(int i=0;i<50;i++)
        putchar('_');
}

void linea1()
{
    for(int i=0;i<122;i++)
        putchar('_');
}

void linea2()
{
    for(int i=0;i<100;i++)
        putchar('_');
}

void barraDeCarga()
{
    for(int i=1;i<=100;i++)
    {
        cout<<"\n\tCargando . . . ";
        cout<<"[ "<<i<<"%  ]"<<endl;
        Sleep(100);
        system("cls");
    }
    cout<<"\n\tCOPIA DE SEGURIDAD REALIZADA"<<endl;
    cin.ignore();
}

void barraDeCarga1()
{
    for(int i=1;i<=100;i++)
    {
        cout<<"\n\tCargando . . . ";
        cout<<"[ "<<i<<"%  ]"<<endl;
        Sleep(100);
        system("cls");
    }
    cout<<"\tRESTAURACIÓN REALIZADA"<<endl;
    cin.ignore();
}
bool validarOpcion(char *numero)
{
    bool esNum=false;
    for(int i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            cout<<"\tINGRESE SOLO NUMEROS"<<endl;
            cin.ignore();
            return esNum;
        }
    }
    esNum=true;
    return esNum;
}

void validacionDeMuestraRestaurante(int id)
{
    int r=mostrarPlatosPorRestaurante(id);
    if(r==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
}

void validacionDeMuestra(int id)
{
    int r=mostrarPlatosPorId(id);
    if(r==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
    else if(r==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        cin.ignore();
    }
}

void validacionDeMuestraCliente(int id)
{
    int r=mostrarClientesPorId(id);
    if(r==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
    }
    else if(r==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
    }
}

void validacionDeMuestraPedido(int id)
{
    int r=mostrarPedidosPorId(id);
    if(r==-2)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
    }
    else if(r==-1)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
    }
}

bool validarMail(char mail[50])
{
    int arroba=0,punto=0;
    if(mail[0]=='.' || mail[0]=='@')
            return false;
    for(int i=1;i<50;i++)
    {
        if(mail[i]=='.')
            punto++;
        if(mail[i] =='.' && mail[i+1]=='.')
            return false;
        if((mail[i]=='@' && mail[i+1]=='.')||(mail[i]=='.' && mail[i+1]=='@'))
            return false;
        if(mail[i]=='@')
            arroba++;
    }
    if(arroba == 0  || arroba>1)
            return false;
    if(punto== 0)
            return false;
    return true;
}

int  validarIdCliente(int id)
{
    Clientes clt;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if(p==NULL) return -2;

    while(fread(&clt,sizeof(Clientes),1,p))
    {
        if(id==clt.id_cliente && clt.estado)
        {
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return -1;
}

int validarIdPlato(int id)
{
    Platos plt;
    FILE *p;
    p=fopen(PLATOS,"rb");
     if(p==NULL) return -2;

     while(fread(&plt,sizeof(Platos),1,p))
     {
        if(id==plt.id_plato && plt.estado)
        {
            fclose(p);
            return 1;
        }
     }
     fclose(p);
     return -1;
}

float buscarPrecioDelPlato(int id)
{
    Platos plt;
    FILE *p;
    p=fopen(PLATOS,"rb");
     if(p==NULL) return -2;

     while(fread(&plt,sizeof(Platos),1,p))
     {
         if(id==plt.id_plato)
         {
             fclose(p);
             return plt.valor_venta;
         }
     }
     fclose(p);
     return -1;
}
#endif // VALIDACIONES_H_INCLUDED
