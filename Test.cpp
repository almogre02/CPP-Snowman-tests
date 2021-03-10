
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;
#include <iostream>
#include <stdexcept>

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )\n"));
    CHECK(snowman(22212211) == "\n  ___  \n ..... \n\\(o..)/\n ( : ) \n ( : ) \n");
    CHECK(snowman(33313411) == "\n   _   \n  /_\\  \n (O_.) \n/( : ) \n ( : ) \n");
    CHECK(snowman(41114411) == "\n  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) \n");
    CHECK(snowman(12441143) == "\n _===_ \n (-.-) \n (> <) \n (___) \n");
    CHECK(snowman(22224411) == "\n  ___  \n ..... \n (o.o) \n ( : ) \n ( : ) \n");
    CHECK(snowman(41442221) == "\n  ___  \n (_*_) \n\\(-,-)/\n (] [) \n ( : ) \n");

}

TEST_CASE("Above 8 digits") {
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(123412341));
    CHECK_THROWS(snowman(444444444));
    CHECK_THROWS(snowman(131313131));
    CHECK_THROWS(snowman(234432234));
}
TEST_CASE("Less than 8 digits") {
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(12341));
    CHECK_THROWS(snowman(444444));
    CHECK_THROWS(snowman(1313131));
    CHECK_THROWS(snowman(2));
}
TEST_CASE("Invalid digit") {
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(12341834));
    CHECK_THROWS(snowman(-46544444));
    CHECK_THROWS(snowman(12741314));
    CHECK_THROWS(snowman(19241314));
    CHECK_THROWS(snowman(19285914));
    CHECK_THROWS(snowman(19241714));
}
