#include <iostream>
#include <string>
#include <iomanip>

#include "whatever.hpp"
#include "color_palletre.hpp"

// #define EXIT_SUCCESS 0

// template < typename T >

// void	print(T &a, T &b)
// {
//     std::cout << CYAN << "The max of a: " << GREEN << a << CYAN << " and b: " << GREEN <<  b
//         << CYAN << " is: " << GREEN << ::max(a, b) << RESET << std::endl;
//     std::cout << CYAN << "The min of a: " << GREEN << a << CYAN << " and b: " << GREEN << b
//         << CYAN << " is: " << GREEN << ::min(a, b) << RESET << std::endl;

//     std::cout << CYAN << "Before swapping: a: " << GREEN << a
//         << CYAN << ", b: " << GREEN << b << RESET << std::endl;
//     ::swap(a, b);
//     std::cout << CYAN << "After swapping: a: " << GREEN << a
//         << CYAN << ", b: " << GREEN << b << RESET << std::endl;
//     std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
// }

// int main(void)
// {
//     {
//         int a = 5;
//         int b = 6;

//         print(a, b);
//     }
//     {
//         float a = 5.4f;
//         float b = 3.7f;

//         print(a, b);
//     }
//     {
//         std::string a = "string a";
//         std::string b = "string b";

//         print(a, b);
//     }
//     return (EXIT_SUCCESS);
// }

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}