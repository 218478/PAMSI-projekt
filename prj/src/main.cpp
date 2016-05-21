#include <iostream>
#include <string>

#include "ReadMNIST.h"

int main() {
	ReadMNIST reader;
	reader.Read(std::string("../dataset/train-images.idx3-ubyte"));
}
