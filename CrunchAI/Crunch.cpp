#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <Windows.h>

// librerias locales del sistema
#include "Crunch.h"
#include "Code.h"

void Crunch::input_params(const std::vector<std::string> &params) {
	// en el parametro po defecto hay 6 sin guardar los datos sonn 4
	if (params.size() == 3 || params.size() == 6) {

		int min = atoi(params[0].c_str());
		int max = atoi(params[1].c_str());

		if (params[2] == "s-") {
			std::cout << "entro 1 " << params[2] << std::endl;
			genera_code((int)min, (int)max, content_catacter,"");
		}
		else if (params[2] == "s--") {
			std::cout << "entro 2" << params[2] << std::endl;
			genera_code((int)min, (int)max, const_mayus_caracter,"");
		}
		else if (params[2] == "s---") {
			std::cout << "entro 3 " << params[2] << std::endl;
			genera_code((int)min, (int)max, numbers,"");
		}
		else {
			std::cout << "entro 4 " << params[2] << std::endl;
			std::string cad = params[2];
			//genera_code((int)min, (int)max, cad,"");
		}

		// este parametro es opcional 
		//for (auto it : string_code) {
		//	std::cout << it << std::endl;
		//}
		//////////////////////////////////

		if (params.size() == 5) {
			generate_txt(params[6], string_code);
		}	
	}
	else {
		std::cerr << "error not define" << std::endl;
	}
}

// Esta es la funcion genera un code simple
void Crunch::genera_code(const int &min,const int &max,const std::string &cad,std::string cur) {
	for (int i = min; i <= max; i++) {
		
		std::cout << "termino: " << i << std::endl;
		// este tratamiento lo puedo tratar con hilos
		genericAllCode(i, cad, cur);
		Sleep(10);
		
	}
}


void Crunch::genericAllCode(const int& size_string, const std::string& code, std::string cur) {
	if (cur.length() == size_string) { // el problema esta en la recursion
		return;
	}
	else {
		for (auto it : code) {
			std::string current = cur + it;
			string_code.push_back(current);
			std::cout << current << std::endl;

			genericAllCode(size_string, code, current);
		}
	}
}



void Crunch::generate_txt(std::string name_txt, std::vector<std::string> data) {
	std::ofstream output_data(name_txt,std::ofstream::out);
	// implementacion de txt con los datos
	if (string_code.empty()) {
		std::cout << "Este contenedor esta vacio" << std::endl;
	}
	else {
		for (auto it : string_code) {
			output_data << it;
		}
		output_data.close();
 	}

}

Crunch::~Crunch() {}

