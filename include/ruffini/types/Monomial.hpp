#ifndef __MONOMIAL_H__
#define __MONOMIAL_H__

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

#include <iostream>
#include <string>

class Monomial
{
private:
	void set_member_vars(const int &t_coefficient,
						 const char &t_base, const int &t_power);
	// evaluate_str_number(int &t_sign, std::string &t_str_number);
public:
	int m_coefficient{};
	char m_base{};
	int m_power{};
	// int &m_order{m_power};

	Monomial() {}
	Monomial(const int &t_coefficient);
	Monomial(const char &t_base);
	Monomial(const char &t_base, const int &t_power);
	Monomial(const int &t_coefficient, const char &t_base, const int &t_power);
	Monomial(const Monomial &t_monomial);
	// // string version
	// Monomial(const std::string &t_coefficient);
	// Monomial(const char &t_base, const std::string &t_power);
	// Monomial(const std::string &t_coefficient,
	// 		 const char &t_base, const std::string &t_power);
	// Monomial(const int &t_coefficient,
	// 		 const char &t_base, const std::string &t_power);
	// Monomial(const std::string &t_coefficient,
	// 		 const char &t_base, const int &t_power);

	// // no const char
	// Monomial(char &t_base, const std::string &t_power);
	// Monomial(const std::string &t_coefficient,
	// 		 char &t_base, const std::string &t_power);
	// Monomial(const int &t_coefficient,
	// 		 char &t_base, const std::string &t_power);
	// Monomial(const std::string &t_coefficient,
	// 		 char &t_base, const int &t_power);

	void print();
};

void Monomial::print()
{
	std::cout << (m_coefficient > 0 ? "+" : "") << m_coefficient << m_base << '^' << m_power << std::endl;
}

// Monomial::Monomial() {}
Monomial::Monomial(const Monomial &t_monomial)
{
	m_coefficient = t_monomial.m_coefficient;
	m_base = t_monomial.m_base;
	m_power = t_monomial.m_power;
}

Monomial::Monomial(const int &t_coefficient)
{
	set_member_vars(t_coefficient, '_', 1);
}
Monomial::Monomial(const char &t_base)
{
	set_member_vars(1, t_base, 1);
}
Monomial::Monomial(const char &t_base, const int &t_power)
{
	set_member_vars(1, t_base, t_power);
}

Monomial::Monomial(const int &t_coefficient, const char &t_base, const int &t_power)
{
	set_member_vars(t_coefficient, t_base, t_power);
}

// // string versions
// Monomial::Monomial(const std::string &t_coefficient)
// {
// 	// evaluate_str_number(sign, t_coefficient);
// 	int sign = 1;
// 	std::string parsed_coefficient;
// 	if (t_coefficient[0] == '-')
// 	{
// 		sign = -1;
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else if (t_coefficient[0] == '+')
// 	{
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else
// 	{
// 		parsed_coefficient = t_coefficient;
// 	}
// 	set_member_vars(std::stoi(parsed_coefficient) * sign, '_', 1);
// }
// Monomial::Monomial(const char &t_base, const std::string &t_power)
// {
// 	set_member_vars(1, t_base, std::stoi(t_power));
// }
// Monomial::Monomial(const std::string &t_coefficient,
// 				   const char &t_base, const std::string &t_power)
// {
// 	// evaluate_str_number(sign, t_coefficient);
// 	int sign = 1;
// 	std::string parsed_coefficient;
// 	if (t_coefficient[0] == '-')
// 	{
// 		sign = -1;
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else if (t_coefficient[0] == '+')
// 	{
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else
// 	{
// 		parsed_coefficient = t_coefficient;
// 	}
// 	set_member_vars(std::stoi(parsed_coefficient) * sign, t_base, std::stoi(t_power));
// }
// Monomial::Monomial(const int &t_coefficient,
// 				   const char &t_base, const std::string &t_power)
// {
// 	set_member_vars(t_coefficient, t_base, std::stoi(t_power));
// }
// Monomial::Monomial(const std::string &t_coefficient,
// 				   const char &t_base, const int &t_power)
// {
// 	int sign = 1;
// 	std::string parsed_coefficient;
// 	if (t_coefficient[0] == '-')
// 	{
// 		sign = -1;
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else if (t_coefficient[0] == '+')
// 	{
// 		parsed_coefficient = t_coefficient.substr(1);
// 	}
// 	else
// 	{
// 		parsed_coefficient = t_coefficient;
// 	}
// 	set_member_vars(std::stoi(parsed_coefficient) * sign, t_base, t_power);
// }

void Monomial::set_member_vars(const int &t_coefficient,
							   const char &t_base, const int &t_power)
{
	m_coefficient = t_coefficient;
	m_base = t_base;
	m_power = t_power;
}

// void Monomial::evaluate_str_number(int &t_sign, std::string &t_str_number)
// {
// 	t_sign = 1;
// 	std::string parsed_coefficient;
// 	if (t_str_number[0] == '-')
// 	{
// 		t_sign = -1;
// 		t_str_number = t_str_number.substr(1);
// 	}
// 	else if (t_str_number[0] == '+')
// 	{
// 		t_str_number = t_str_number.substr(1);
// 	}
// }

#endif // __MONOMIAL_H__
