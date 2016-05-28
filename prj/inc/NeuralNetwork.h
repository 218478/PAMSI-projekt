#ifndef NERUAL_NETWORK_H
#define NERUAL_NETWORK_H

#include <fstream>
#include <vector>
#include <stdexcept>  // for std::runtime_error
#include <cstdlib>  	// for pseudorandomness
#include <cmath>  	// for sigmoid function

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

	/*! \brief	Bledy na wyjsciu.
	*/
	Output errors;

	// parametry sieci neuronowej.
	double alpha, beta, eta;

	/*! \brief	Funkcja aktywacji.
	*
	* \details	Przerabia wektor podany jako argument funkcji. Dziala na
	*			referencji.
	*/
	void Sigmoid (std::vector<double> &wektor) {
		for (auto& i: wektor)
			i = 1.0 / (1.0 + exp(beta * (-i)));
	}
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
		alpha = beta = eta = 1.0;  // ustawienie parametrow sieci

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
					k = (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;  // jak w necie
					if (k == 0)
						k = 0.01492;
				}
			}
		}

		// reserve memory for output layer
		out.resize(26);  // bo tyle jest liter
		errors.resize(26);
		for (auto &a: out) {
			a.resize(hidden_nuerons_number);
			errors.resize(hidden_nuerons_number);
		}

		for (auto &i: out)
			for (auto &j: i) {
				j = (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;  // jak w necie
				if (j == 0)
					j = 0.01492;
			}
	}

	/*! \brief	Uczenie sieci neuronowej.
	*
	* \details	Tutaj nastepuje zmian wag sieci ukrytej metoda propagacji
	*			wstecznej. Funkcja aktywacji to sigmoida.
	*/
	void Learn(const Letter& l) {
		std::vector<double> signal1(8);
		std::vector<double> signal2(26);
		// pojedyncze przetworzenie pierwszej warstwy
		for (int i = 0; i < layer.size(); i++) {
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < columns; k++) {
					signal1[i] += layer[i][j][k]*l[j][k];
				}
			}
		}

		Sigmoid(signal1);

		for (int i = 0; i < out.size(); i++) {
			for (int j = 0; j < signal1.size(); j++)
				signal2[i] += out[i][j]*signal1[j];
		}

		Sigmoid(signal2);


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

	/*! \brief	Zwraca litere jaka rozpoznal.
	*
	*  \details	LItera 'a' jest w kodzie ascii 98 znakiem z kolei. Metoda
	*			powinna byc wywolywana po nauczeniu siecie metoda Learn().
	*/
	char Result(const Letter& l) {
		return {};
	}
};


#endif  // NERUAL_NETWORK_H