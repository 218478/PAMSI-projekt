#include "ReadMNIST.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

int ReadMNIST::ReverseInt(int i) {
	unsigned char c1, c2, c3, c4;

	c1 = i & 255;
	c2 = (i >> 8) & 255;
	c3 = (i >> 16) & 255;
	c4 = (i >> 24) & 255;

	return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

std::vector<int> ReadMNIST::Read(std::string filename) {

	// // My old code
	// std::fstream file(filename.c_str(), std::ios::in);

	// std::cout << file << std::endl;

	// if (std::ios::failbit == true)
	// 	std::cerr << "Blad przy wczytywaniu pliku: " << filename << std::endl;
	//____________________________________________________________________

	file.open(filename.c_str());
	if (std::ios::failbit == true)
		std::cerr << "Blad przy wczytywaniu pliku: " << filename << std::endl;
	if (file.is_open())
	{
		int magic_number=0;
		int number_of_images=0;
		int n_rows=0;
		int n_cols=0;
		file.read((char*)&magic_number,sizeof(magic_number));
		magic_number= ReverseInt(magic_number);
		file.read((char*)&number_of_images,sizeof(number_of_images));
		number_of_images= ReverseInt(number_of_images);
		file.read((char*)&n_rows,sizeof(n_rows));
		n_rows= ReverseInt(n_rows);
		file.read((char*)&n_cols,sizeof(n_cols));
		n_cols= ReverseInt(n_cols);
		for(int i=0;i<number_of_images;++i)
		{
			for(int r=0;r<n_rows;++r)
			{
				for(int c=0;c<n_cols;++c)
				{
					unsigned char temp=0;
					file.read((char*)&temp,sizeof(temp));

				}
			}
		}
	}

}