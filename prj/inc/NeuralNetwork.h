#ifndef NERUAL_NETWORK_H
#define NERUAL_NETWORK_H

#include <fstream>
#include <vector>
#include <stdexcept>  // for std::runtime_error
#include <cstdlib>  // for pseudorandomness

#include "Letter.h"

typedef std::vector< std::vector<double> > Output;
typedef std::vector< std::vector< std::vector<double> > > Layer;

/*! \brief	Klasa sieci neuronowej.
*
* \details	Siec sklada sie z jednej warstwy neuronow. Macierz kolumnowa,
*			ktorej ilosc wierszy ustala sie w momencie uruchomienia konstruktora
*			sieci. Ma 128 (16*8  wejsc. Zmienne rows i columns sa zdefiniowane w
*			pliku naglowkowym Letter.h i sa to wymiary wczytywanych liter.
*/
class NeuralNetwork {
private:
	/*! \brief	Warstwa ukryta neuronow.
	*
	* \details	Siec sklada sie z pojedynczej warstwy neuronow, ktora
	*			inicjalizowana jest podczas konstrukcji obiektu.
	*/
	Layer layer;

	/*! \brief	Warstwa wyjsciowa neuronow.
	*
	* \details	Zawiera wyjscia neuronow.
	*/
	Output out;
public:
	/*! \brief	Konstuktor bezparametryczny.
	*
	* \details	Wyswietla ostrzezenie na wyjscie bledu. Nie powinien nigdy sie
	*			uruchomic. Siec neuronowa musi byc tworzona z podanym parametrem ilosci
	*			neuronow w warstwie ukrytej.
	*/
	NeuralNetwork() {
		throw std::runtime_error("Zla konstrukcja. Podaj ilosc neuronow.");
	}


	/*! \brief	Konstruuje siec w oparciu o ilosc neuronow wewnetrznych.
	*
	* \details	Parametr to ilosc neuronow w sieci wewnetrznej. Tutaj odbywa sie
	*			losowy przydzial wag neuronow.
	*/
	NeuralNetwork(int hidden_nuerons_number) {
		layer.resize(hidden_nuerons_number);  // zarezerwuj pamiec dla n neuronow
		for (auto &i: layer) {
			i.resize(rows);  // zarezerwuj pamiec dla kolumn macierzy Liter
			for (auto &j: i)
				j.resize(columns);  // kazdy neuron jest polaczony z kazdym wejsc.
		}

		srand(time(0));  // ziarno i nastepuje zwolnienie maszyny losujacej
		for (auto &i: layer) {
			for (auto &j: i) {
				for (auto &k: j) {
					k = (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
					if (k == 0)
						k = 0.01492;
				}
			}
		}
	}

	/*! \brief	Uczenie sieci neuronowej.
	*
	* \details	Tutaj nastepuje zmian wag sieci ukrytej metoda propagacji
	*			wstecznej.
	*/
	void Learn(const Letter& l) {
		std::cout << l << "\n" << l[3][1] << std::endl;
	}

	/*! \brief	Podaje ile polaczen wystepuje w sieci ukrytej z wejsciem.
	*/
	int HiddenLayerConnectionNumber() {
		int size = 0;
		for (auto &i: layer) {
			for (auto &j: i) {
				size += j.size();
			}
		}
		// Ilosc polaczen warstwy ukrytej sieci
		return size;
	}

	/*! \brief Zwraca litere jaka rozpoznal.
	*
	*  \details LItetra 'a' jest w kodzie ascii 98 znakiem z kolei.
	*/
	char Result(const Letter& l) {
		return {};
	}
};


#endif  // NERUAL_NETWORK_H