#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Reader.h"
#include "Letter.h"
#include "NeuralNetwork.h"

int main(int argc, char **argv) {
	if (argc < 2)
		std::cerr << "Syntax: ./program <path_to_file>" << std::endl;
	else {
		try {
			Reader reader;
			std::vector<Letter> temp;
			// temp = reader.ReadDigits(std::string("../dataset/train-images.idx3-ubyte"));
			// std::cout << "Rozmiar vectora: " << temp.size() << std::endl;
			// for (auto it = temp.begin(); it != temp.end(); it++)
			// 	std::cout << *it << std::endl;
			temp = reader.ReadLetters(std::string(argv[1]));

			std::cout << "Wczytano: " << temp.size() << " liter" << std::endl;

			NeuralNetwork siec(8);
			std::cout << "Ilosc polaczen: " << siec.HiddenLayerConnectionNumber()
				<< std::endl;

			// eksperymentujemy na literce 'o'
			siec.Learn(temp[0]);
		}
		catch (std::runtime_error& msg) {
			std::cerr << msg.what() << std::endl;
		}
	}
}
