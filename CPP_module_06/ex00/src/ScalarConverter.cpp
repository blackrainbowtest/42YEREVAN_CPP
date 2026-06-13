/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/26 01:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "color_palletre.hpp"

// empty constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

// empty destructor
ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(
	const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

// 1. isPseudoLiteral()

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	if (literal == "nan"
		|| literal == "nanf"
		|| literal == "+inf"
		|| literal == "-inf"
		|| literal == "+inff"
		|| literal == "-inff")
	{
		return (true);
	}

	return (false);
}

// 2. isChar()
// "a"       -> true
// "1"       -> false
// " "       -> true
// "ab"      -> false
// ""        -> false
// "\n"      -> false

bool ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (true);

	return (false);
}

// 3. isInt()
// "42"      -> true
// "-42"     -> true
// "+42"     -> true
// "++42"    -> false
// "--42"    -> false
// "0"       -> true
// "+"       -> false
// "-"       -> false
// "42f"     -> false
// "42.0"    -> false
// "abc"     -> false
// ""        -> false

bool ScalarConverter::isInt(const std::string &literal)
{
	size_t i = 0;
	if (literal.empty())
		return (false);

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	if (i == literal.length())
		return (false);

	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}

	return (true);
}
// 4. isFloat()
bool ScalarConverter::isFloat(const std::string &literal)
{

}
// 5. isDouble()
bool ScalarConverter::isDouble(const std::string &literal)
{

}

// 6. detectType()
e_type ScalarConverter::detectType(const std::string &literal)
{

}
// 7. convert()
void ScalarConverter::convert(const std::string &literal)
{

}
