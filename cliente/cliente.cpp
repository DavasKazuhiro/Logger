//
// CLIENTE DO LOGGER
// Sistemas Distribuídos
// Escola Politécnica -- PUCPR
// Lucas Pelanda, Pedro Favero, Eduardo Teodoro e Davi Kazuhiro
//

#include <iostream>

#include "LoggerC.h"
#include <orbsvcs/CosNamingC.h>

using namespace std;
using namespace CORBA;

int main(int argc, char* argv[])
{

	// 1. Inicializa ORB
	ORB_var orb = ORB_init(argc, argv, "ORB");
	// 2. Obtem referencia para objeto distirbuido (do servidor de nomes)
	Object_ptr obj = orb->string_to_object("corbaname:rir:#Logger");
	Logger_var logger = Logger::_narrow(obj);

	// 3. Usa objeto (chama metodos)
	logger->log(ERROR, "192.168.1.1:1500", 123, 1700000000, "deu ruim");

	cout << "locate = " << logger->locate(ERROR) << '\n';

	// 4. Finalizacoes
	orb->destroy();
    

    return 0;
}