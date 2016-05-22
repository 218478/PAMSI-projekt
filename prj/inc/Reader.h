#ifndef READER_H
#define READER_H

#include <string>
#include <fstream>
#include <vector>

#include "Letter.h"

class Reader {
private:
	/*! \brief Odwraca magiczne cyfry.
	*
	* \details	Poniewaz MNIST jest napisany w big-endian nalezy odwrocic
	*			kolejnosc bitow, bo procesory Intela  to architektura Little Endian.
	*/
	int ReverseInt (int i);

public:
	/*! \brief	Wczytuje zawartosc pliku MNIST i zwraca ja w formie vectora.
	*
	* \details	Korzysta z metody ReverseInt(). Wektor korzysta z char, poniewaz
	*			tak domyslnie czyta sie pliki binarne.
	*/
	std::vector<int> ReadDigits(const std::string& path_to_file);

	/*! \brief	Wczytuje zawartosc pliku letter.data.
	*
	* \details Poniewaz mamy zajac sie literami.
	*/
	std::vector<Letter> ReadLetters(const std::string& path_to_file);
};

#endif  // READER_H