#include <vector>
#include <string>
#pragma once

class Crunch {
public:
	Crunch() =	default;
	void input_params(const std::vector<std::string> &params);
	void generate_txt(std::string name_txt, std::vector<std::string> data);
	void genera_code(const int &min,const int &max,const std::string &cad,std::string cur);

	// esta funcion se va a llamar mucho
	void genericAllCode(const int& rize_string, const std::string& code, std::string cur);

	~Crunch();
private:
	// el string code va a tener el valor
	std::vector<std::string> string_code;
	std::string  current_string = "";
};
