#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;


string nospaces(string input) {
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\r'), input.end());
	return input;
}


// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }


TEST_CASE("Hat types check") {
    SUBCASE("valid")
    {
        CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
        CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )")); 
        CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
        CHECK(nospaces(snowman(41114411)) == nospaces ("___\n(_*_)\n(.,.)\n( : )\n( : )"));
    }
    
    SUBCASE("invalid")
    {
        CHECK_THROWS(snowman(51114411));
        CHECK_THROWS(snowman(61114411));
        CHECK_THROWS(snowman(71114411));
        CHECK_THROWS(snowman(81114411));
        CHECK_THROWS(snowman(91114411));
        CHECK_THROWS(snowman(01114411));
    }
}


TEST_CASE("Nose/Mouth types check") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )")); 
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces ("_===_\n(. .)\n( : )\n( : )"));
    // CHECK_THROWS(snowman(16114411));
}


TEST_CASE("Left Eye types check") {
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )")); 
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces ("_===_\n(-,.)\n( : )\n( : )"));
    // CHECK_THROWS(snowman(16114411));
}


TEST_CASE("Right Eye types check") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )")); 
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144411)) == nospaces ("_===_\n(.,-)\n( : )\n( : )"));
    // CHECK_THROWS(snowman(16114411));
}


TEST_CASE("Left Arm types check") {
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )")); 
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces ("_===_\n(.,.)\n( : )\n( : )"));
    // CHECK_THROWS(snowman(16114411));
}


TEST_CASE("Right Arm types check"){
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )")); 
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces ("_===_\n(.,.)\n( : )\n( : )"));
}



TEST_CASE("Torso types check"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )")); 
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114441)) == nospaces ("_===_\n(.,.)\n(   )\n( : )"));
}



TEST_CASE("Base types check"){
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(\" \")")); 
    CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces ("_===_\n(.,.)\n( : )\n(   )"));
}


TEST_CASE("input validation") {
    CHECK_THROWS(snowman(555));  // length of input - invalid
    //CHECK_THROWS(snowman("?538P4"));  //length of input & string- invalid  // HNRLXYTB
    //CHECK_THROWS(snowman(null));
    CHECK_THROWS(snowman('5'));
    CHECK_THROWS(snowman(true));  
    //CHECK_THROWS(snowman(5.3)); 
    CHECK_THROWS(snowman(1111111)); 
    CHECK_THROWS(snowman(111111111)); 
    CHECK_THROWS(snowman(-11111111)); 

}

