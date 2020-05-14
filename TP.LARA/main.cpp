#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>>
#include <iomanip>
#include <windows.h>
#include <clocale>//LIBRERIA PARA CARACTERES CON TILDE

using namespace std;

const char *PLATOS = "PLATOS.dat";
const char *CLIENTES  = "CLEINTES.dat";
const char *PEDIDOS = "PEDIDOS.dat";

const char *PLATOSbkp ="PLATOS.bkp";
const char *CLIENTESbkp ="CLIENTES.bkp";
const char *PEDIDOSbkp ="PEDIDOS.bkp";

#include "Struct.h"
#include "PltPrototipos.h"
#include "CltPrototipos.h"
#include "PedPrototipos.h"
#include "CnfPrototipos.h"


#include "Validaciones.h"
#include "Clientes.h"
#include "Platos.h"
#include "Pedidos.h"
#include "Configuracion.h"

#include "MenuPincipal.h"
#include "SubMenuPlatos.h"
#include "SubMenuClientes.h"
#include "SubMenuPedidos.h"
#include "SubMenuConfiguracion.h"


int main()
{
    setlocale(LC_ALL,"spanish");//PERMITE IMPRIMIR CARACTARES CON TILDE
    menuPrincipal();
    return 0;
}
