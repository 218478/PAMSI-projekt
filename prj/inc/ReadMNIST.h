#ifndef READ_MNIST_H
#define READ_MNIST_H

#include <string>
#include <fstream>
#include <vector>

class ReadMNIST {
private:
	/*! \brief Zmienna przechowujaca wczytane dane.
	*/
	std::ifstream file;

	/*! \brief Odwraca magiczne cyfry.
	*
	* \details	Poniewaz MNIST jest napisany w big-endian nalezy odwrocic
	*			kolejnosc bitow, bo procesory Intela  to architektura Little Endian.
	*/
	int ReverseInt (int i);

public:
	/*! \brief	Wczytuje zawartosc pliku MNIST i zwraca ja w formie vectora.
	*
	* \details	Korzysta z metody ReverseInt();
	*/
	std::vector<int> Read(std::string filename);
};

#endif  // READ_MNIST_H