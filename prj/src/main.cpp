#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "ReadMNIST.h"

int main() {
	try {
		ReadMNIST reader;
		std::vector<char> temp;
		temp = reader.Read(std::string("../dataset/train-images.idx3-ubyte"));
		std::cout << "Rozmiar vectora: " << temp.size() << std::endl;
		for (auto it = temp.begin(); it != temp.end(); it++)
			std::cout << *it << std::endl;
	}
	catch (std::runtime_error& msg) {
		std::cerr << msg.what() << std::endl;
	}
}
