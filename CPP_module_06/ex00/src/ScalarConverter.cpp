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
#include <cmath>
#include <sstream>

static bool	isNan(double value)
{
	return (value != value);
}

static bool	isInf(double value)
{
	return (value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity());
}

static std::string	formatDecimal(double value, bool isFloat)
{
	std::ostringstream	oss;
	std::string			result;
	double				intpart;

	oss << value;
	result = oss.str();
	if (!isNan(value) && !isInf(value)
		&& std::modf(value, &intpart) == 0.0
		&& result.find('.') == std::string::npos
		&& result.find('e') == std::string::npos
		&& result.find('E') == std::string::npos)
		result += ".0";
	if (isFloat)
		result += "f";
	return (result);
}

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
	switch (detectType(literal))
	{
		case CHAR:
			convertFromChar(literal[0]);
			break;
		case INT:
		{
			long	value;
			
			value = std::strtol(literal.c_str(), NULL, 10);
			if (value < std::numeric_limits<int>::min()
				|| value > std::numeric_limits<int>::max())
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(value) << std::endl;
				return ;
			}
			convertFromInt(static_cast<int>(value));
			break;
		}
		case FLOAT:
			convertFromFloat(std::atof(literal.c_str()));
			break;
		case DOUBLE:
			convertFromDouble(std::atof(literal.c_str()));
			break;
		case NAN_INF:
			convertPseudoLiteral(literal);
			break;
		default:
			throw ErrorException();
	}
}

void ScalarConverter::convertFromChar(char value)
{
	int		i;
	float	f;
	double	d;

	i = static_cast<int>(value);
	f = static_cast<float>(value);
	d = static_cast<double>(value);

	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << formatDecimal(f, true) << std::endl;
	std::cout << "double: " << formatDecimal(d, false) << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
	char	c;
	float	f;
	double	d;

	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		c = static_cast<char>(value);
		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	f = static_cast<float>(value);
	d = static_cast<double>(value);
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << formatDecimal(f, true) << std::endl;
	std::cout << "double: " << formatDecimal(d, false) << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
	char	c;
	int		i;
	double	d;

	d = static_cast<double>(value);

	// CHAR
	if (isNan(d) || isInf(d) || d < 0 || d > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		c = static_cast<char>(value);
		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}

	// INT
	if (isNan(d) || isInf(d)
		|| d < static_cast<double>(std::numeric_limits<int>::min())
		|| d > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}

	// FLOAT
	std::cout << "float: " << formatDecimal(d, true) << std::endl;

	// DOUBLE
	std::cout << "double: "
		<< formatDecimal(value, false)
		<< std::endl;
}

void ScalarConverter::convertFromDouble(double value)
{
	char	c;
	int		i;
	float	f;

	// char
	if (isNan(value) || isInf(value) || value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		c = static_cast<char>(value);
		if (!std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: Non displayable";
		else
			std::cout << "char: '" << c << "'" << std::endl;
	}
	// int
	if (isNan(value) || isInf(value)
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		i = static_cast<int>(value);
		std::cout << "int: " << i << std::endl;
	}

	// float
	if (!isNan(value) && !isInf(value)
		&& (value < -static_cast<double>(
				std::numeric_limits<float>::max())
			|| value > static_cast<double>(
				std::numeric_limits<float>::max())))
	{
		std::cout << "float: impossible" << std::endl;
	}
	else
	{
		f = static_cast<float>(value);
		std::cout << "float: "
			<< formatDecimal(static_cast<double>(f), true)
			<< std::endl;
	}

	// double
	std::cout << "double: "
		<< formatDecimal(value, false)
		<< std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

const char	*ScalarConverter::ErrorException::what() const throw()
{
	return ("Error");
}
