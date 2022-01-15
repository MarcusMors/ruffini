// Copyright (C) 2022 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
// #include "catch.hpp"
#include <catch2/catch_all.hpp>

// standard libraries
#include <string>

// user made libraries
// #include <ruffini/app.hpp>
#include "../src/ruffini/App.cpp"

using namespace std;

/**
 * TESTS:
 * signed monomials
 * +51x^32
 * -17x^21
 * -x^2
 * +x^9
 * +x
 * -x
 * +86
 * -19
 * +1
 * -1
 * unsigned monomials
 * 123x^17
 * 295x
 * x^7
 * x
 * 5
 * 1
 * signed polynomials
 * -7x^3+2x^2+x-5
 * +2x^3-10x^2+5x
 * unsigned polynomials
 * 7x^3+2x^2+x-5
 * 2x^3-10x^2+5x
 */

TEST_CASE("Console app")
{
	/**
	 * TESTS
	 * x^3+2x^2-x-2
	 * expected
	 * 1
	 */
	string p1{"x^3+2x^2-x-2"};
	string p2{"7x^3+2x^2+x-5"};
	string p3{"+24x^8 -12y^15 +x^2 +5 -x+y^7"};
	string p4{"+2x^3-10x^2+5x"};

	SECTION("a")
	{
		Monomial m1(3);
		Monomial m2(-125);
		Monomial m3('x');
		Monomial m4(-1, 'x');

		// string str = m1.print();
		// REQUIRE(test == true);
		// REQUIRE(test == true);
	}
	// REQUIRE(test == true);
	// REQUIRE( == true);
}
