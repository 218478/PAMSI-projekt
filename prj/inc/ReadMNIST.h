#ifndef READ_MNIST_H
#define READ_MNIST_H

#include <string>
#include <fstream>
#include <vector>

class ReadMNIST {
private:
	/*! \brief Odwraca magiczne cyfry.
	*
	* \details	Poniewaz MNIST jest napisany w big-endian nalezy odwrocic
	*			kolejnosc bitow, bo procesory Intela  to architektura Little Endian.
	*/
	uint32_t ReverseInt (uint32_t i);

public:
	/*! \brief	Wczytuje zawartosc pliku MNIST i zwraca ja w formie vectora.
	*
	* \details	Korzysta z metody ReverseInt(). Wektor korzysta z char, poniewaz
	*			tak domyslnie czyta sie pliki binarne.
	*/
	std::vector<char> Read(const std::string& path_to_file);
};

#endif  // READ_MNIST_H