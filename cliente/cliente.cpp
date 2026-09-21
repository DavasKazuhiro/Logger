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
	int tipo;
	cout << "Digite 0 para DEBUG, 1 para WARNING, 2 para ERROR, 3 para CRITICAL e 4 para LOCATE: ";
	cin >> tipo;

	if (tipo == 4) {
		int severidade;
		cout << "Digite a severidade para consultar (0=DEBUG, 1=WARNING, 2=ERROR, 3=CRITICAL): ";
		cin >> severidade;

		try {
			switch (severidade) {
				case 0:
					cout << "locate = " << logger->locate(DEBUG) << '\n';
					break;
				case 1:
					cout << "locate = " << logger->locate(WARNING) << '\n';
					break;
				case 2:
					cout << "locate = " << logger->locate(ERROR) << '\n';
					break;
				case 3:
					cout << "locate = " << logger->locate(CRITICAL) << '\n';
					break;
				default:
					cerr << "Severidade invalida\n";
					return 1;
			}
		} catch (const NenhumEventoCadastrado&) {
			cerr << "Nenhum evento cadastrado para essa severidade\n";
			return 1;
		}
	}
	else{
		string descricao;
		cout << "Digite a descricao do evento: ";
		cin.ignore();
		getline(cin, descricao);

		switch (tipo) {
			case 0:
				logger->log(DEBUG, "192.168.1.1:1500", 123, 1700000000, descricao);
				break;
			case 1:
				logger->log(WARNING, "192.168.1.1:1500", 123, 1700000000, descricao);
				break;
			case 2:
				logger->log(ERROR, "192.168.1.1:1500", 123, 1700000000, descricao);
				break;
			case 3:
				logger->log(CRITICAL, "192.168.1.1:1500", 123, 1700000000, descricao);
				break;
			default:
				cerr << "Tipo invalido\n";
				return 1;
		}
	}

	// 4. Finalizacoes
	orb->destroy();
    return 0;
}