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

#include <string>
#include <iostream>
#include <vector>
#include "types/Monomial.hpp"
// #include "types/Binomial.hpp"
// #include "types/Factor.hpp"

class App
{
private:
	std::string m_name{""};
	std::string m_version{""};
	std::string m_description{""};

	void analyze_expression(const std::string &t_polynomial);
	std::vector<Monomial> tokenizationn(const std::string &t_polynomial);
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
	void print_monomials(std::vector<Monomial> &t_monomials);
};

void App::set_app_name(const std::string &t_name)
{
	m_name = t_name;
}
void App::set_app_version(const std::string &t_version)
{
	m_version = t_version;
}
void App::set_app_description(const std::string &t_description)
{
	m_description = t_description;
}

App::App() {}

// App::App(int argc, char *argv[])
// {
// }

void App::start()
{
	using std::cin;
	using std::cout;
	using std::getline;
	using std::string;

	cout << "Write 'END' to terminate the program\n";
	cout << "Introduce the polynomial to decompose:\n";
	string raw_polynomial;
	while (getline(cin, raw_polynomial) && raw_polynomial != "END")
	{
		std::vector<Monomial> monomials = tokenizationn(raw_polynomial);
		// parse_monomials(monomials); is it sorted and complete?
		print_monomials(monomials);

		std::size_t s = monomials.size();

		int coefficients[s];

		for (size_t i = 0; i < s; i++)
		{
			coefficients[i] = monomials[i].m_coefficient;
		}

		int independent_factors[s];

		for (size_t i = 0; i < s; i++)
		{
			independent_factors[i] = 0;
		}

		/**
		 * TESTS
		 * x^3+2x^2-x-2
		 * expected
		 * 1
		 */

		ruffini_factorization(coefficients, s, independent_factors);
		// void ruffini_factorization(int t_coefficients[], std::size_t t_size,
		// 						   int *t_answer_arr);
		std::cout << "-- ANSWERS --" << std::endl;
		for (size_t i = 0; i < monomials.size(); i++)
		{
			std::cout << independent_factors[i] << " ";
		}
		std::cout << std::endl;

		// Binomial factors[monomials.size() - 1] = ruffini_factorization(monomials);
	}
	// parsing(polynomial);
}

void print_line(int t_arr[], std::size_t t_size)
{
	std::cout << "\n";
	std::cout << " \t| ";
	for (size_t i = 0; i < t_size; i++)
	{
		const auto c = t_arr[i];
		if (c > -1)
		{
			std::cout << '+';
		}
		std::cout << c << " ";
	}
	std::cout << "\n";
}

void App::ruffini_factorization(int *t_coefficients, const std::size_t t_size, int *t_answer_arr)
{
	if (t_size <= 2)
	{
		std::cout << "I can't reduce more this expression" << std::endl;
		return;
	}

	// const int highest_order = t_size;

	const int i_minimum = -1;
	const int i_maximum = 5;

	for (int i = i_minimum; i <= i_maximum; i++)
	{
		if (i == 0)
		{
			continue;
		}

		int a_coefficients[t_size - 1];
		a_coefficients[0] = t_coefficients[0];
		print_line(t_coefficients, t_size);

		// x^3+2x^2-x-2
		std::cout << "----------------------\n";
		std::cout << " ";
		if (i > 0)
		{
			std::cout << "+";
		}
		std::cout << i << "\t|    ";

		for (size_t j = 1; j < t_size; j++)
		{
			// std::cout << "\n/* t_c:" << t_coefficients[j - 1] << " i:" << i << "*/";
			const int sum_up = a_coefficients[j - 1] * i;
			a_coefficients[j] = t_coefficients[j] + sum_up;
			if (sum_up == 0)
			{
				std::cout << ' ';
			}
			else if (sum_up > 0)
			{
				std::cout << "+";
			}
			std::cout << sum_up << " ";
		}
		std::cout << "\n";
		std::cout << "----------------------";
		print_line(a_coefficients, t_size);
		if (a_coefficients[t_size - 1] == 0)
		{
			t_answer_arr[t_size - 1] = i;
			std::cout << "\n====> CERO POINT FOUND : " << i << " <====" << std::endl;

			ruffini_factorization(a_coefficients, (t_size - 1), t_answer_arr);
			return;
		}

		// print_ruffini_table(i, t_coefficients, t_size, t_answer_arr);
	}
	std::cout << "---- NO CERO POINT FOUND -- END PROGRAM" << std::endl;
}

void App::print_ruffini_table(int t_i, int t_coefficients[], std::size_t t_size, int *t_answer_arr)
{
	std::cout << "\n";
	std::cout << " \t| ";
	for (size_t i = 0; i < t_size; i++)
	{
		const auto c = t_coefficients[i];
		if (c > -1)
		{
			std::cout << '+';
		}
		std::cout << c << " ";
	}
	std::cout << "\n";

	std::cout << "----------------------\n";
	std::cout << " ";
	if (t_i == 0)
	{
		std::cout << ' ';
	}
	else if (t_i > 0)
	{
		std::cout << "+";
	}
	std::cout << t_i << "\t|\n";
	std::cout << "----------------------\n";

	std::cout << " \t| ";
	for (size_t i = t_size; i > 0; i--)
	{
		const auto c = t_answer_arr[i];
		if (c == 0)
		{
			std::cout << ' ';
		}
		else if (c > 0)
		{
			std::cout << '+';
		}
		std::cout << c << " ";
	}
	std::cout << "\n";
	std::cout << "\n";
}

std::vector<Monomial> App::tokenizationn(const std::string &t_polynomial)
{
	int sign = (t_polynomial[0] == '-') ? -1 : 1;
	std::vector<Monomial> monomials;
	std::string coefficient{""};
	std::string power{""};

	char base{'_'};

	bool reading_coefficient{true};
	bool reading_power{false};
	bool first_is_signed = (t_polynomial[0] == '-' || t_polynomial[0] == '+');

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
	 * signed polinomials
	 * -7x^3+2x^2+x-5
	 * +2x^3-10x^2+5x
	 * unsigned polinomials
	 * 7x^3+2x^2+x-5
	 * 2x^3-10x^2+5x
	 */

	// for (size_t i = 0; i < t_polynomial.size(); i++)
	// {
	// const char ch = t_polynomial[i];
	for (auto ch : t_polynomial)
	{
		// std::cout << ch << std::endl;
		if (first_is_signed)
		{
			first_is_signed = false;
			continue;
		}

		const bool is_a_letter = ((ch >= 'a') && (ch <= 'z')) ||
								 ((ch >= 'A') && (ch <= 'Z'));
		const bool is_a_number = (ch >= '0') && (ch <= '9');

		// add_ch();
		// switch_part();

		if (ch == '+')
		{
			if (power.empty() && reading_power)
			{
				power = "1";
			}

			reading_coefficient = true;
			reading_power = false;

			Monomial monomial(std::stoi(coefficient) * sign, base, std::stoi(power));
			monomials.push_back(monomial);

			sign = 1;
			base = '_';
			coefficient = "";
			power = "";
		}
		else if (ch == '-')
		{
			if (power.empty() && reading_power)
			{
				power = "1";
			}

			reading_coefficient = true;
			reading_power = false;

			Monomial monomial(std::stoi(coefficient) * sign, base, std::stoi(power));
			monomials.push_back(monomial);

			sign = -1;
			base = '_';
			coefficient = "";
			power = "";
		}
		else if (is_a_number)
		{
			if (reading_coefficient)
			{
				coefficient += ch;
			}
			else
			{
				power += ch;
			}
		}
		else if (is_a_letter)
		{
			if (coefficient.empty() && reading_coefficient)
			{
				coefficient = "1";
			}
			base = ch;
			// the coefficient is 1
			reading_coefficient = false;
			reading_power = true;
		}
		else if (ch == '^')
		{
			reading_coefficient = false;
			reading_power = true;
		}
		// else // error
		// {
		// }
		// std::cout << "----------- STATE --------- : " << ch << std::endl;
		// std::cout << "reading coeff : " << reading_coefficient << std::endl;
		// std::cout << "reading power : " << reading_power << std::endl;
		// std::cout << "sign  : " << sign << std::endl;
		// std::cout << "coeff : " << coefficient << std::endl;
		// std::cout << "base : " << base << std::endl;
		// std::cout << "power : " << power << std::endl;
	}

	if (power.empty())
	{
		power = "1";
	}
	if (coefficient.empty() && reading_coefficient)
	{
		coefficient = "1";
	}
	// std::cout << "----------- LAST STATE --------- : " << std::endl;
	// std::cout << "reading coeff : " << reading_coefficient << std::endl;
	// std::cout << "reading power : " << reading_power << std::endl;
	// std::cout << "sign  : " << sign << std::endl;
	// std::cout << "coeff : " << coefficient << std::endl;
	// std::cout << "base  : " << base << std::endl;
	// std::cout << "power : " << power << std::endl;

	Monomial monomial(std::stoi(coefficient) * sign, base, std::stoi(power));
	monomials.push_back(monomial);

	// print_monomials(monomials);

	// create the last monomial.
	return monomials;
}

void App::print_monomials(std::vector<Monomial> &t_monomials)
{
	std::cout << "PRINTING MONOMIALS" << std::endl;
	for (const auto &[m_coefficient, m_base, m_power] : t_monomials)
	{
		std::cout << m_coefficient << m_base << '^' << m_power << std::endl;
	}
}

#endif // __APP_H__
