// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

int simpleFunction() { return 1; }

TEST_CASE("READING LETTERS", "[letters]" ) {
    REQUIRE(simpleFunction() == 0);
}