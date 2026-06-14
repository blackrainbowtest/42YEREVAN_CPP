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

/*
** VALID FLOATS
**
** 42.0f
** -42.0f
** +42.0f
** 42.000f
** 0.0f
** 0.f
** .0f
** 123456.789f
**
** VALID DOUBLES
**
** 42.0
** -42.0
** +42.0
** 42.000
** 0.0
** 0.
** .0
** 123456.789
**
** VALID PSEUDO LITERALS
**
** nan
** nanf
** +inf
** -inf
** +inff
** -inff
**
** VALID INTS
**
** 42
** -42
** +42
** 0
** 2147483647
** -2147483648
**
** VALID CHARS
**
** a
** z
** A
** Z
** *
** +
** @
** ?
**
** INVALID INPUTS
**
** ""
** +
** -
** .
** f
**
** 42f
** +42f
** -42f
**
** 42..0f
** 42..0
**
** 42.0ff
** 42.0fff
**
** 42.0f42
** 42.0abc
**
** abc
** test
**
** ++42
** --42
** +-42
**
** 42-42
** 42+42
**
** nanff
** infinf
*/

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
// requirements:
// "42.0f"   -> true
// "-42.0f"  -> true
// ".0f"  -> true
// "42f"     -> false
// "42.0"    -> false
// "abc"     -> false
// ""        -> false
bool ScalarConverter::isFloat(const std::string &literal)
{
	size_t	i = 0;
	bool	hasDecimalPoint = false;
	bool	hasDigit = false;

	if (literal.empty())
		return (false);

	if (literal[literal.length() - 1] != 'f')
		return (false);

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	if (i == literal.length() - 1)
		return (false);

	while (i < literal.length() - 1)
	{
		if (literal[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (std::isdigit(literal[i]))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDecimalPoint && hasDigit);
}

// 5. isDouble()
bool ScalarConverter::isDouble(const std::string &literal)
{
	size_t	i = 0;
	bool	hasDecimalPoint = false;
	bool	hasDigit = false;

	if (literal.empty())
		return (false);

	if (literal[i] == '-' || literal[i] == '+')
		i++;

	if (i == literal.length())
		return (false);

	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (std::isdigit(literal[i]))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDecimalPoint && hasDigit);
}

// 6. detectType()
ScalarConverter::e_type ScalarConverter::detectType(const std::string &literal)
{
	if (isPseudoLiteral(literal))
		return (NAN_INF);
	if (isChar(literal))
		return (CHAR);
	if (isInt(literal))
		return (INT);
	if (isFloat(literal))
		return (FLOAT);
	if (isDouble(literal))
		return (DOUBLE);
	return (ERROR);
}
// 7. convert()
void ScalarConverter::convert(const std::string &literal)
{
	(void)literal;
}
