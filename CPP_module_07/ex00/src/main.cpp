/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 10:25:11 by aramarak          #+#    #+#             */
/*   Updated: 2026/08/03 16:16:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

template < typename I >

void    print(I &a, I &b)
{
        std::cout << "The max of " << "a: " << a << " and b: " << b
            << " is: " << max(a, b) << std::endl;
        std::cout << "The min of " << "a: " << a << " and b: " << b
            << " is: " << min(a, b) << std::endl;
        std::cout << "Before swaping a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "After swaping a: " << a << ", b: " << b << std::endl;
}

int main()
{
    // int
    {
        int a = 5;
        int b = 6;

        print(a, b);
    }
    // float
    {
        float a = 5.4f;
        float b = 3.7f;

        print(a, b);
    }
    // string
    {
        std::string a = "string a";
        std::string b = "string b";

        print(a, b);
    }
    return (0);
}