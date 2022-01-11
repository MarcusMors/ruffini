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

// #include <iostream>
#include "src/ruffini/App.hpp"
// #include <configuration.h>

using namespace std;

// int main(int argc, char *argv[])
int main()
{
	// cout << "The number of arguments is:" << argc << endl;
	// cout << "The arguments are:";

	// for (unsigned i = 1; i < argc; i++)
	// {
	// 	cout << argv[i];
	// }
	// cout << endl;

	App app;
	// App app(argc, argv);

	app.set_app_name("ruffini");
	app.set_app_version("1.0.0");
	// app.set_auto_print_help(true);

	app.set_app_description("Decompose polynomials through the ruffini method");
	app.start();
	// app.print_monomials();

	return 0;
}
