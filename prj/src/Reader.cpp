#include "Reader.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>

int Reader::ReverseInt(int i) {
	int swapped;
	swapped = ((i>>24)&0xff) | // move byte 3 to byte 0
				((i<<8)&0xff0000) | // move byte 1 to byte 2
				((i>>8)&0xff00) | // move byte 2 to byte 1
				((i<<24)&0xff000000); // byte 0 to byte 3

				return swapped;
			}

	std::vector<int> Reader::ReadDigits(const std::string& path_to_file) {
		std::ifstream input( path_to_file.c_str(), std::ios::binary );

		if (input.fail())
			throw std::runtime_error("Blad przy wczytywaniu pliku: "+ path_to_file);

		if (input.is_open()) {
			std::vector<int> buffer;
			buffer.reserve(60000);  // size of training set
			unsigned char temp;
			while (input >> temp) {
				input >> temp;
				std::cout << temp;
		}

		buffer.push_back(ReverseInt(temp));
		std::bitset<32> a(temp);

		std::cout << "Cala zmienna: " << a << std::endl;
		std::cout << "Trzeci bajt: " << a[2] << std::endl;

		if(a[2] != 0x0c)
			throw std::runtime_error("Plik: " + path_to_file
				+ " nie sklada sie tylko i wylacznie z intow");

		return buffer;
	} else {
		throw std::runtime_error("Plik: " + path_to_file + " nie jest otwarty.");
		return {};
	}
}

std::vector<Letter> Reader::ReadLetters(const std::string& path_to_file) {
	std::ifstream input( path_to_file.c_str());
	Letter temp;
	std::vector<Letter> collected;

	if (input.fail())
		throw std::runtime_error("Nie moge dostac sie do pliku: " + path_to_file);

	if (input.is_open()) {
		while(input >> temp) {
			collected.push_back(temp);
			temp.clear();
		}
	}

	return collected;
}