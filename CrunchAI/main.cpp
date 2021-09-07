#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "Crunch.h"

// Este es el menu de ayuda para el programa
void help_crunch() {
	std::cout << std::endl;
	std::cout << "Ayuda de Crunch" << std::endl;
	std::cout << "paramtros: <min-lenght-> requerido> <max-lenght-> requerido> <string_code -> requerido> <guardar -> opcional> " << std::endl;
	
	std::cout << "min  : minimo numero de caracteres" << std::endl;
	std::cout << "max  : maximo numero de caracteres" << std::endl;
	std::cout << "s-   : genera solo un string aleatorio con las letras en minuscula" << std::endl;
	std::cout << "s--  : genera solo un string aleatorio con las letras en mayuscula" << std::endl;
	std::cout << "s--- : genera solo un string aleatorio de numeros" << std::endl;
	std::cout << "-o   : guarda el archivo con la extension .txt" << std::endl;
	std::cout << std::endl;
	system("pause");
}

void program(const std::vector<std::string> &commandLine) {
	Crunch crunch;
	crunch.input_params(commandLine);
	std::cout << "termino del programa" << std::endl;
	system("pause");
}


void menuOption(const std::vector<std::string>& command_line) {
	int op;
	do {
		std::cout << std::endl;
		std::cout << "1.help" << std::endl;
		std::cout << "2. activate application" << std::endl;
		std::cout << "3. exit" << std::endl;
		std::cout << "opction: "; std::cin >> op;
		switch (op) {
		case 1:
			help_crunch();
			break;
		case 2:			
			program(command_line);
			break;
		case 3:
			std::cout << "exit" << std::endl;
			break;
		default:
			std::cout << "bad answer" << std::endl;
		}
		//system("cls");
	} while (op != 3);
}

void visit(std::string const& chars, size_t max_len, std::string const& cur);

int main(int argc,char **argv) {

	std::vector<std::string> vect_command_line;
	// enumeracion de los parametros de command line
	for (int i = 1; i < argc; i++) {
		vect_command_line.push_back(argv[i]);
		std::cout << argv[i] << " -> "<< i << std::endl;
	}
	system("pause");
	std::cout << argc << std::endl;
	std::cout << "Iniciando el Programa" << std::endl;
	menuOption(vect_command_line);
	


	std::cin.get();
	return 0;
}



// este es un algoritmo muy bueno en el procesop de fuerza bruta
void visit(std::string const& chars, size_t max_len, std::string const& cur) {
	if (cur.length() == max_len) {
		return;
	}
	else {
		// estes es un proceso de varios for
		for (auto c : chars) {
			std::string next = cur + c;
			std::cout << next << std::endl;

			visit(chars, max_len, next);
		}
	}
}




