// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "NeuralNetwork.h"
#include "Reader.h"
#include "Letter.h"

// for testing class Letter
#include <vector>
#include <string>

TEST_CASE("READING LETTERS", "[letters]" ) {
	std::vector<Letter> temp;
	Reader reader;
	char *name = "/home/kkuczaj/PAMSI-projekt/dataset/letter.data";
	temp = reader.ReadLetters(std::string(name));
    	REQUIRE( temp.size() == 52152);
}

TEST_CASE("CONNECTIONS OF HIDDEN LAYER", "[connections]") {
	// mozna by to ladniej napisac

	int rows = 16;
	int columns = 8;
	NeuralNetwork siec1(8);
	NeuralNetwork siec2(16);
	NeuralNetwork siec3(24);
	REQUIRE( siec1.HiddenLayerConnectionNumber() == rows*columns*8);
	REQUIRE( siec2.HiddenLayerConnectionNumber() == rows*columns*16);
	REQUIRE( siec3.HiddenLayerConnectionNumber() == rows*columns*24);
}