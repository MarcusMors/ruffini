#ifndef __APP_H__
#define __APP_H__

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

// User made types
#include "types/Monomial.hpp"
// standard libraries
#include <string>
#include <vector>

namespace ruffini_p
{
	class App
	{
	private:
		std::string m_name{""};
		std::string m_version{""};
		std::string m_description{""};

		void analyze_expression(const std::string &t_polynomial);
		std::vector<Monomial> tokenization(const std::string &t_polynomial);
		// void add_ch(char t_ch,
		// 			const bool &t_reading_coefficient, const bool &t_reading_power,
		// 			std::string &t_coefficient, std::string &t_power);
		// void ruffini_factorization(std::vector<Monomial> t_monomials, int t_terms[]);
		void ruffini_factorization(int t_coefficients[], const std::size_t t_size,
								   int *t_answer_arr);
		void print_ruffini_table(int t_i, int t_coefficients[], std::size_t t_size, int *t_answer_arr);

	public:
		App();
		// App(int argc, char *argv[]);
		void set_app_name(const std::string &t_name);
		// void set_app_name(char t_name[]);
		void set_app_version(const std::string &t_version);
		// void set_app_version(char t_version[]);
		// void set_auto_print_help(bool);
		void set_app_description(const std::string &t_description);
		// void set_app_description(char t_description[]);
		void start();
		void print_monomials(const std::vector<Monomial> &t_monomials);
	};
} // namespace ruffini_p

#endif // __APP_H__
