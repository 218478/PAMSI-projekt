#include "Conversion.h"
#include "bitmap_image.hpp"

#include <iostream>
#include <string>

int main() {
	std::cout << "\n\tPoprawna kompilacja\n" << std::endl;
	// ReadBMP object;
	// std::string name("jakas_nazwa.bmp");
	// object.ReadImage(name);


	bitmap_image image("../dataset/ssnpodpisyrecznie/_skany/AndrzejJanota02.bmp");
	bitmap_image image2("../dataset/ssnpodpisyrecznie/_skany/AndrzejJanota02.bmp");

	if (!image || !image2)
		std::cerr << "Nie udalo sie zaladowac pliku: " << std::endl;
}
