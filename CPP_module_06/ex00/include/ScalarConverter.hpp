/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/16 11:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <climits>
# include <cstdlib>
# include <cstring>
# include <cctype>

class ScalarConverter
{
    private:
        enum e_type
        {
            ERROR = 0, // unknown input type
            CHAR,      // char input type
            INT,       // integer input type
            FLOAT,     // float input type
            DOUBLE,    // double input type
            NAN_INF    // NaN or infinity types
        };

        // Constructors
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        // Destructors
        ~ScalarConverter();
        // Overloaded Operators
        ScalarConverter &operator=(const ScalarConverter &src);
        // Methods
		static e_type detectType(const std::string &literal);

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static bool isPseudoLiteral(const std::string &literal);
    public:
        // Methods
        static void convert(const std::string &literal);
        //Exceptions
        class ErrorException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif // !SCALARCONVERTER_HPP