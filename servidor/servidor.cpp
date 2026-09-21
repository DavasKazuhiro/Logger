//
// SERVIDOR DO LOGGER
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// Lucas Pelanda, Pedro Favero, Eduardo Teodoro e Davi Kazuhiro
//

#include <iostream>
#include <string>

#include "LoggerI.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;
using namespace PortableServer;
using namespace CosNaming;

int main(int argc, char* argv[])
{
    try {
        // 1. Inicia ORB
        ORB_var orb = ORB_init(argc, argv, "ORB");

        // 2. Ativa RootPOA
        Object_ptr obj;
        obj = orb->resolve_initial_references("RootPOA");
        POA_var poa = POA::_narrow(obj);
        POAManager_var ger = poa->the_POAManager();
        ger->activate();

        // 3. Instancia "servants"
        Logger_i li;

        // 4. Registra servos no POA, criando objetos distribuidos
        Logger_var logger = li._this();

        // 5. Publica IOR 
        obj = orb->resolve_initial_references("NameService");
        NamingContext_var serv_nomes = NamingContext::_narrow(obj);
        Name name(1);
        name.length(1);
        name[0].id = string_dup("Logger");
        serv_nomes->rebind(name, logger.in());

        // 6. Aguarda requisicoes
        cout << "aguardando eventos\n";
        orb->run();

        // 7. Finalizacoes
        poa->destroy(true,true);
        orb->destroy();
    } catch (const Exception& e) {
        cerr << "ERRO CORBA: " << e << '\n';
        return 1;
    }
    return 0;
}