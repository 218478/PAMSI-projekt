#include "ReadMNIST.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>

uint32_t ReadMNIST::ReverseInt(uint32_t i) {
	// unsigned char temp[4];
	// int result = 0;
	// temp[0] = (i & 0xff000000) >> 24;
	// temp[1] = (i & 0x00ff0000) >> 8;
	// temp[2] = (i & 0x0000ff00) << 8;
	// temp[3] = (i & 0x000000ff) << 24;

	// result = temp[0] | temp[1]  | temp[2]  | temp[3];
	uint32_t swapped;
	swapped = ((i>>24)&0xff) | // move byte 3 to byte 0
				((i<<8)&0xff0000) | // move byte 1 to byte 2
				((i>>8)&0xff00) | // move byte 2 to byte 1
				((i<<24)&0xff000000); // byte 0 to byte 3

	return swapped;

	// uint8_t lolo = (i >> 0) & 0xFF;
	// uint8_t lohi = (i >> 8) & 0xFF;
	// uint8_t hilo = (i >> 16) & 0xFF;
	// uint8_t hihi = (i >> 24) & 0xFF;

	// uint32_t value = (hihi << 24)
 //               | (hilo << 16)
 //               | (lohi << 8)
 //               | (lolo << 0);

	// return value;


}

std::vector<char> ReadMNIST::Read(const std::string& path_to_file) {
	int temphaha = 7;
	std::bitset<32> a(temphaha);
	std::cout << "Przed zamiana: " << temphaha << std::endl;
	std::bitset<32> b(ReverseInt(temphaha));
	std::cout << "Po zamianie: " << ReverseInt(temphaha) << std::endl;
	std::ifstream input( path_to_file.c_str(), std::ios::binary );

	if (input.fail())
		throw std::runtime_error("Blad przy wczytywaniu pliku: "+ path_to_file);

	if (input.is_open()) {
	// // copies all data into buffer
	// 	std::vector<char> buffer((
	// 		std::istreambuf_iterator<char>(input)),
	// 	(std::istreambuf_iterator<char>()));
					std::vector<char> buffer;
		buffer.reserve(60000);  // size of training set
		char temp;


		input >> temp;
		buffer.push_back(temp);
		return buffer;
	} else {
		throw std::runtime_error("Plik: " + path_to_file + " nie jest otwarty.");
		return {};
	}
}
