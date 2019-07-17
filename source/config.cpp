#include "../headers/config.hpp"

#include <fstream>
#include <sstream>

void Config::load() {
	std::ifstream file(configFileName, std::ios::in);

	uint8 propertiesRead = 0;

	std::string line;
	while (std::getline(file, line)) {
		std::string propName, propValue;
		std::istringstream iss(line);

		if (!(iss >> propName >> propValue)) { break; }

		if (propName == "Format") {
			this->format = static_cast<Format>(std::stoi(propValue));
			propertiesRead++;
		} else if (propName == "Port") {
			this->port = static_cast<uint16>(std::stoi(propValue));
			propertiesRead++;
		}
	}

	if (propertiesRead != propertiesNum) { reset(); }

	file.close();
}

void Config::reset() {
	this->format = FORMAT_2019;
	this->port = 20777;

	this->save();
}

void Config::save() {
	std::ofstream file(configFileName, std::ios::out | std::ios::trunc);

	file << "Format " << this->format << '\n';
	file << "Port " << this->port << '\n';

	file.close();
}