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

#include "iter.hpp"
#include <iostream>
#include <cctype>

template <typename T>
void	printElement(const T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	incrementElement(T &element)
{
	element++;
}

void	ft_toupper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

int main()
{
	int		numbers[] = {1, 2, 3, 4, 5};
	char	text[] = "hello";
	std::string	words[] = {"one", "two", "three"};

		std::cout << "Numbers:" << std::endl;
	iter(numbers, 5, printElement<int>);

	iter(numbers, 5, incrementElement<int>);

	std::cout << "Incremented numbers:" << std::endl;
	iter(numbers, 5, printElement<int>);

	iter(text, sizeof(text) / sizeof(text[0]) - 1, ft_toupper);

	std::cout << "Uppercase text: " << text << std::endl;

	std::cout << "Words:" << std::endl;
	iter(words, 3, printElement<std::string>);
	return (0);
}