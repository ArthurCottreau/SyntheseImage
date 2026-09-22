#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "vecteur.h"

TEST_CASE("Vecteur dot product unit tests", "[math]") {
    Vecteur var1 {1,2,3};
    Vecteur var2 {4,5,6};
	Vecteur var3 {-4,-5,-6};
	Vecteur var4 {-7,-8,-9};

	REQUIRE(var1.dot(var2) == 32);
	REQUIRE(var2.dot(var1) == 32);
	REQUIRE(var4.dot(var2) == -122);
	REQUIRE(var1.dot(var3) == -32);
	REQUIRE(var3.dot(var1) == -32);
}

TEST_CASE("Vecteur normalization unit tests", "[math]") {
    Vecteur test1 {0,0,0};
    std::optional<Vecteur> test2 = test1.normalize();
	REQUIRE(test2.has_value() == false);

	Vecteur test3 {-1,1,0};
	std::optional<Vecteur> test4 = test3.normalize();
	REQUIRE(test4.has_value() == true);
	REQUIRE(test4.value().z == 0);
}