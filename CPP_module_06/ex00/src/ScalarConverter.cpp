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

// 2. isChar()

// 3. isInt()

// 4. isFloat()

// 5. isDouble()

// 6. detectType()

// 7. convert()

