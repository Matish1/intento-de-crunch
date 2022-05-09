#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Crunch.h"

// Este es el menu de ayuda para el programa
void help_crunch() {
	std::cout << std::endl;
	std::cout << "Ayuda de Crunch" << std::endl;
	std::cout << "paramtros: <min-lenght-> requerido> <max-lenght-> requerido> <string_code -> requerido> <guardar -> opcional> " << std::endl;
	
	std::cout << "min  : minimo numero de caracteres" << std::endl;
	std::cout << "max  : maximo numero de caracteres" << std::endl;
	std::cout << "-s   : genera solo un string aleatorio con las letras en minuscula" << std::endl;
	std::cout << "--s  : genera solo un string aleatorio con las letras en mayuscula" << std::endl;
	std::cout << "---s : genera solo un string aleatorio de numeros" << std::endl;
	std::cout << "-o   : guarda el archivo con la extension .txt" << std::endl;
	std::cout << "<name file> nombre del documento" << std::endl;
	std::cout << std::endl;
	system("pause");
}

void program(const std::vector<std::string> &commandLine) {
	Crunch crunch;
	crunch.input_params(commandLine);
}



// Debemos eliminar el caracter de salto de linea de la cadena
void removeZero(std::string &str) {
	int i = 0;
	while (str[i] == '\n')
		i++;
	str.erase(0, i);
}



void menuOption() {
	int op;
	do {
		std::cout << std::endl;
		std::cout << "1. help" << std::endl;
		std::cout << "2. activate application" << std::endl;
		std::cout << "3. exit" << std::endl;
		std::cout << "opction: "; std::cin >> op;
		switch (op) {
		case 1:
			help_crunch();
			break;
		case 2 : {
				std::string command_line_string;
				std::string concat_string = "";
				std::vector<std::string> command_line;
				
				std::cout << "Parametro: "; std::cin.ignore(); getline(std::cin, command_line_string);
				for (int i = 0; i < command_line_string.size(); i++) {
					concat_string += command_line_string[i];
					if (command_line_string[i] == ' ' || i == command_line_string.size()-1) {
						removeZero(concat_string);
						command_line.push_back(concat_string);
						concat_string = "";
					}
				}
				for (std::string ite : command_line) {
					std::cout << ite << std::setw(2);
				}
				std::cout << std::endl;
				program(command_line);
				break;
			}
		case 3:
			std::cout << "exit" << std::endl;
			break;
		default:
			std::cout << "bad answer" << std::endl;
		}
		//system("cls");
	} while (op != 3);
}


int main(int argc,char *argv[]) {
	std::vector<std::string> vect_command_line;

	std::cout << "Programa: " << argv[0] << std::endl;	
	help_crunch();
	if (argc > 1) {
		// enumeracion de los parametros de command line
		for (int i = 1; i < argc; i++) {
			vect_command_line.push_back(argv[i]);
			std::cout << argv[i] << " -> " << i << std::endl;
		}
		program(vect_command_line);
	}
	else {
		menuOption();
	}

	std::cin.get();
	return 0;
}





