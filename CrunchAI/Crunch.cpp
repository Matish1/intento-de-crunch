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
	if (true) {

		int min = atoi(params[0].c_str());
		int max = atoi(params[1].c_str());
	
		// TODO: entrada sin comando de linea tiene un bug
		if (params[2] == "-s") {
			genera_code((int)min, (int)max, content_catacter,"");
		}
		else if (params[2] == "--s") {
			genera_code((int)min, (int)max, const_mayus_caracter,"");
		}
		else if (params[2] == "---s") {
			genera_code((int)min, (int)max, numbers,"");
		}
		else {
			std::cout << "Genear los codigo de manera general " << params[2] << std::endl;
			std::string cad = params[2];
			//genera_code((int)min, (int)max, cad,"");
		}
		if (params[3] == "-o") {
			std::string name_txt = params[4];
			generate_txt(name_txt, string_code);
		}
	}
	else {
		std::cerr << "rando de los comandos de linea no coincide" << std::endl;
	}
}

void Crunch::genericAllCode(const int& size_string, const std::string& code, std::string cur) {
	if (cur.size() != size_string) {
		for (auto it : code) {
			std::string current = cur + it;
			if (current.size() == size_string) {
				string_code.push_back(current);
			}
			genericAllCode(size_string, code, current);
		}
	}
}

void Crunch::genera_code(const int &min,const int &max,const std::string &cad,std::string cur) {
	for (int i = min; i <= max; i++) {
		genericAllCode(i, cad, cur);
		Sleep(10);
	}
}

void Crunch::generate_txt(std::string &name_txt,const std::vector<std::string> &data) {
	if (name_txt.find(".txt") > name_txt.size()) name_txt = name_txt + ".txt"; 

	std::ofstream output_data(name_txt,std::ofstream::out);
	if (!string_code.empty()) {
		for (auto it : string_code) {
			output_data << it;
			output_data << '\n';
		}
		output_data.close();
	}
	else {
		std::cerr << "Error el contenido de codigo esta vacio!!" << std::endl;
 	}

}

Crunch::~Crunch() {}

