#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

int cantidadClientes();
Clientes leerRegistroClientes(int );

bool guardarRegistroActualizadoCliente(int ,Clientes);

Clientes cargarClientes()
{
    Clientes clt;
    cout<<"\n\tNOMBRES : ";
    cin.getline(clt.nombre,50);
    while(*clt.nombre=='\0')
    {
        system("cls");
        cout<<"\tNOMBRE : ";
        cin.getline(clt.nombre,50);
    }

    cout<<"\tAPELLIDOS : ";
    cin.getline(clt.apellido,50);
    while(*clt.nombre=='\0')
    {
        cout<<"\e[A";
        cout<<"\tAPELLIDOS : ";
        cin.getline(clt.apellido,50);
    }

    cout<<"\tMAIL : ";
    cin.getline(clt.mail,50);
    while(*clt.mail=='\0' || !validarMail(clt.mail))
    {
        cout<<"\e[A"; ///Esta líinea de codigo la reemplacé por el system("cls"), ya que al ingresar al while hace que se quede en la misma posicion hasta ingresar un valor válido, y no borrarme todo lo anterior.
        cout<<"\tMAIL : ";
        cin.getline(clt.mail,50);
    }

    cout<<"\tDOMICILIO : ";
    cin.getline(clt.domicilio,100);
    while(*clt.domicilio=='\0')
    {
        cout<<"\e[A";
        cout<<"\tDOMICILIO : ";
        cin.getline(clt.domicilio,100);
    }

    cout<<"\tCÓDIGO POSTAL : ";
    cin>>clt.cod_postal;
    while(clt.cod_postal<1000 || clt.cod_postal>9999)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ CP tiene que estar desde 1000 - 9999 ]"<<endl;
        cout<<"\tCÓDIGO POSTAL : ";
        cin>>clt.cod_postal;
    }

    cout<<"\tDIA DE NACIMIENTO : ";
    cin>>clt.fec.dia;
    while(clt.fec.dia<=0 || clt.fec.dia>=32)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ DÍA tiene que estar desde 1 - 31 ]"<<endl;
        cout<<"\tDIA DE NACIMIENTO : ";
        cin>>clt.fec.dia;
    }

    cout<<"\tMES DE NACIMIENTO : ";
    cin>>clt.fec.mes;
    while( clt.fec.mes<=0 || clt.fec.mes>=13)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ MES tiene que estar desde 1 - 12 ]"<<endl;
        cout<<"\tMES DE NACIMIENTO : ";
        cin>>clt.fec.mes;
    }

    cout<<"\tAÑO DE NACIMIENTO: ";
    cin>>clt.fec.anio;
    while(clt.fec.anio>=2020)
    {
        cin.get();
        cin.ignore();
        cout<<"\e[A";
        cout<<"\e[A";
         cout<<"\t [ AÑO NAC. tiene que ser menor a 2020 ]"<<endl;
        cout<<"\tAÑO DE NACIMIENTO: ";
        cin>>clt.fec.anio;
    }
    clt.estado;
    cin.ignore();
    return clt;
}

int cantidadClientes()
{
    int pos, tam,id;
    Clientes clt;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return -1;
    }
    fseek(p,0,SEEK_END);
    pos= ftell(p);
    tam=sizeof(Clientes);
    id= (pos/tam);
    fclose(p);
    return id;
}

bool guardarClientesEnArchivo(Clientes clt)
{
    FILE *p;
    p=fopen(CLIENTES,"ab");

    if(p==NULL)
        return false;
    clt.id_cliente=cantidadClientes()+1;
    fwrite(&clt,sizeof(Clientes),1,p);
    fclose(p);
    return true;
}

int mostrarClientesPorId(int id)
{
    Clientes clt;
    int i=0;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if(p==NULL)
        return -1;
    cout<<"\n";
    cout<<"\tID "<<setw(3)<<"| "<<setw(15)<<" NOMBRES "<<setw(10)<<" |"<<setw(15)<<" APELLIDOS "<<setw(10)<<" |"<<setw(15)<<" MAIL";
    cout<<setw(15)<<" |"<<setw(15)<<" DOMICILIO "<<setw(15)<<" |"<<setw(5)<<" COD. POSTAL "<<setw(5)<<" |"<<setw(5)<<" FECHA DE NAC. "<<setw(5)<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&clt,sizeof(Clientes),1,p))
    {
        if(clt.id_cliente==id&&clt.estado)
        {
            cout<<"\t"<<setw(8)<<left<<clt.id_cliente<<" "<<setw(25)<<clt.nombre<<" "<<setw(25)<<clt.apellido<<" ";
            cout<<setw(30)<<clt.mail<<" "<<setw(30)<<clt.domicilio<<"  "<<setw(12)<<clt.cod_postal<<"   ";
            cout<<clt.fec.dia<<"/"<<clt.fec.mes<<"/"<<clt.fec.anio<<endl;
            cout<<"\t";linea1();
            cout<<endl;
            fclose(p);
            cin.get();
            return i; ///retorna la posicion del registro para ser usado en la funcion de modificar o dar de baja registro.
        }
        i++;
    }
    fclose(p);
    system("cls");
    return -2;
}

void modificarRegistroClientes()
{
    Clientes clt;
    int id;
    cout<<"\n\t======== ACTUALIZACIÓN DE DATOS  ========"<<endl;
    cout<<"\n\tINGRESE EL ID DE CLIENTE : ";
    cin>>id;
    int pos=mostrarClientesPorId(id);
    if(pos==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        return;
    }
    else if(pos==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        return;
    }

    clt=leerRegistroClientes(pos);

    cout<<"\n\t*El único dato que puede MODIFICAR es el de DOMICILIO "<<endl;
    cout<<"\n\tNUEVO DOMICILIO : ";
    cin.getline(clt.domicilio,100);
    while(*clt.domicilio=='\0')
    {
        cout<<"\e[A";
        cout<<"\tDOMICILIO : ";
        cin.getline(clt.domicilio,100);
    }

    if(guardarRegistroActualizadoCliente(pos,clt))
        cout<<"\n\tCAMBIOS GUARDADOS"<<endl;
    else
        cout<<"\n\tERROR AL GUARDAR CAMBIOS"<<endl;
    cin.ignore();
}

Clientes leerRegistroClientes(int pos)
{
    Clientes clt;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        clt.id_cliente=-1;
        return clt;
    }
    fseek(p,pos*sizeof(Clientes),SEEK_SET);
    fread(&clt,sizeof(Clientes),1,p);
    fclose(p);

    return clt;
}

bool guardarRegistroActualizadoCliente(int pos,Clientes clt)
{
    FILE *p;
    p=fopen(CLIENTES,"rb+");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return false;
    }
    fseek(p,pos*sizeof(Clientes),SEEK_SET);
    fwrite(&clt,sizeof(Clientes),1,p);
    fclose(p);

    return true;
}

void mostrarArchivoClientes()
{
    Clientes clt;
    FILE *p;
    p=fopen(CLIENTES,"rb");
    if(p==NULL)
        return;
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

void bajaLogicoDeRegistroClientes()
{
    Clientes clt;
    int id;
    cout<<"\n\t======== DAR DE BAJA REGISTRO ========"<<endl;
    cout<<"\n\tINGRESE EL ID DE CLIENTE : ";
    cin>>id;
    int pos=mostrarClientesPorId(id);
    if(pos==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
    else if(pos==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        cin.ignore();
    }

    clt=leerRegistroClientes(pos);
    clt.estado=false;
    if(guardarRegistroActualizadoCliente(pos,clt))
        cout<<"\n\tCLIENTE DADO DE BAJA CORRECTAMENTE"<<endl;
    else
        cout<<"\n\tERROR AL DAR LA BAJA AL CLIENTE"<<endl;
}
#endif // CLIENTES_H
