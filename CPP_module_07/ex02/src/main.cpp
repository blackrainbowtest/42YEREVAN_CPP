/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:56:49 by aramarak          #+#    #+#             */
/*   Updated: 2026/09/12 18:57:08 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Array.hpp"
#include "color_palletre.hpp"

#define EXIT_SUCCESS 0
#define MAX_SIZE 120

void ft_empty_array()
{
	Array<int> a;
	std::cout << GREEN << std::setw(15) << std::setfill('-') 
			<< "EMPTY ARRAY" << std::setw(15) 
			<< std::setfill('-') << RESET << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;
}

void ft_sized_array()
{
	Array<int> a(5);
	std::cout << GREEN << std::setw(15) << std::setfill('-') 
			<< "5 ELEMENT ARRAY" << std::setw(15) 
			<< std::setfill('-') << RESET << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;
}

int main()
{
	srand(time(NULL));

	ft_empty_array();
	std::cout << std::endl;
	ft_sized_array();


	Array<int> numbers(MAX_SIZE);

	int *tmp = new int[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int value = rand() % 100; 
		numbers[i] = value;
		tmp[i] = value;
	}

	{

	}

	delete [] tmp;

	return (EXIT_SUCCESS);
}