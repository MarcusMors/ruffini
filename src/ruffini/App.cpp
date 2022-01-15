

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

// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"			  /* Black */
#define RED "\033[31m"				  /* Red */
#define GREEN "\033[32m"			  /* Green */
#define YELLOW "\033[33m"			  /* Yellow */
#define BLUE "\033[34m"				  /* Blue */
#define MAGENTA "\033[35m"			  /* Magenta */
#define CYAN "\033[36m"				  /* Cyan */
#define WHITE "\033[37m"			  /* White */
#define BOLDBLACK "\033[1m\033[30m"	  /* Bold Black */
#define BOLDRED "\033[1m\033[31m"	  /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"	  /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"	  /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"	  /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"	  /* Bold White */

// library header
#include <ruffini/App.hpp>

// standard libraries
#include <iostream>

using namespace std;

void ruffini_p::App::set_app_name(const string &t_name)
{
	m_name = t_name;
}
void ruffini_p::App::set_app_version(const string &t_version)
{
	m_version = t_version;
}
void ruffini_p::App::set_app_description(const string &t_description)
{
	m_description = t_description;
}

ruffini_p::App::App() {}

// ruffini_p::App::App(int argc, char *argv[])
// {
// }

void ruffini_p::App::start()
{
	cout << "Write " << RED << "'END'" << RESET << " to terminate the program\n";
	cout << "Introduce the polynomial to decompose:\n";

	string raw_polynomial;
	while (getline(cin, raw_polynomial) && raw_polynomial != "END")
	{
		vector<Monomial> monomials = tokenization(raw_polynomial);
		// parse_monomials(monomials); is it sorted and complete?
		print_monomials(monomials);

		size_t s = monomials.size();

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

		ruffini_factorization(coefficients, s, independent_factors);
		// void ruffini_factorization(int t_coefficients[], size_t t_size,
		// 						   int *t_answer_arr);
		cout << "-- ANSWERS --" << endl;
		for (size_t i = 0; i < monomials.size(); i++)
		{
			cout << independent_factors[i] << " ";
		}
		cout << endl;

		// Binomial factors[monomials.size() - 1] = ruffini_factorization(monomials);
	}
	// parsing(polynomial);
}

void print_line(int t_arr[], size_t t_size)
{
	cout << "\n";
	cout << " \t| ";
	for (size_t i = 0; i < t_size; i++)
	{
		const auto c = t_arr[i];
		if (c > -1)
		{
			cout << '+';
		}
		cout << c << " ";
	}
	cout << "\n";
}

template <typename T>
void print_signed_n(const T &t_number)
{
	if (t_number == 0)
	{
		cout << " ";
	}
	else if (t_number > 0)
	{
		cout << "+";
	}
	cout << t_number;
}

void ruffini_p::App::ruffini_factorization(int *t_coefficients, const size_t t_size, int *t_answer_arr)
{
	if (t_size <= 2)
	{
		cout << "I can't reduce any more this expression" << endl;
		return;
	}

	// const int highest_order = t_size;

	const int i_minimum = -10;
	const int i_maximum = 10;

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
		cout << "----------------------\n";
		print_signed_n(i);
		cout << "\t|    ";

		for (size_t j = 1; j < t_size; j++)
		{
			const int sum_up = a_coefficients[j - 1] * i;
			a_coefficients[j] = t_coefficients[j] + sum_up;
			print_signed_n(sum_up);
			cout << " ";
		}
		cout << "\n";
		cout << "----------------------";
		print_line(a_coefficients, t_size);
		if (a_coefficients[t_size - 1] == 0)
		{
			t_answer_arr[t_size - 1] = i;
			cout << "\n====> " << YELLOW << "CERO POINT FOUND : " << MAGENTA << i << RESET << " <====" << endl;

			ruffini_factorization(a_coefficients, (t_size - 1), t_answer_arr);
			return;
		}

		// print_ruffini_table(i, t_coefficients, t_size, t_answer_arr);
	}
	cout << "---- NO CERO POINT FOUND -- END PROGRAM" << endl;
}

vector<Monomial> ruffini_p::App::tokenization(const string &t_polynomial)
{
	int sign = (t_polynomial[0] == '-') ? -1 : 1;
	vector<Monomial> monomials;
	string coefficient{""};
	string power{""};

	char base{'_'};

	bool reading_coefficient{true};
	bool reading_power{false};
	bool no_vars{true};
	bool first_is_signed = (t_polynomial[0] == '-' || t_polynomial[0] == '+');

	// for (size_t i = 0; i < t_polynomial.size(); i++)
	// {
	// const char ch = t_polynomial[i];
	for (auto ch : t_polynomial)
	{
		// cout << ch << endl;
		if (first_is_signed)
		{
			first_is_signed = false;
			continue;
		}

		if (ch == '^')
		{
			// reading_coefficient = false;
			// reading_power = true;
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

			Monomial monomial(stoi(coefficient) * sign, base, stoi(power));
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

			Monomial monomial(stoi(coefficient) * sign, base, stoi(power));
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
			no_vars = false;

			if (coefficient.empty() && reading_coefficient)
			{
				coefficient = "1";
			}
			base = ch;
			// the coefficient is 1
			reading_coefficient = false;
			reading_power = true;
		}
	}

	if (power.empty())
	{
		power = "1";
	}
	if (coefficient.empty() && reading_coefficient)
	{
		coefficient = "1";
	}
	// cout << "----------- LAST STATE --------- : " << endl;
	// cout << "reading coeff : " << reading_coefficient << endl;
	// cout << "reading power : " << reading_power << endl;
	// cout << "sign  : " << sign << endl;
	// cout << "coeff : " << coefficient << endl;
	// cout << "base  : " << base << endl;
	// cout << "power : " << power << endl;

	Monomial monomial(stoi(coefficient) * sign, base, stoi(power));
	monomials.push_back(monomial);

	// print_monomials(monomials);

	// create the last monomial.
	return monomials;
}

void ruffini_p::App::print_monomials(const vector<Monomial> &t_monomials)
{
	cout << "PRINTING MONOMIALS" << endl;
	for (const auto &[m_coefficient, m_base, m_power] : t_monomials)
	{
		cout << m_coefficient << m_base << '^' << m_power << endl;
	}
}
