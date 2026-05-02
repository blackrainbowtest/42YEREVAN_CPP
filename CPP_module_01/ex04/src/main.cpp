/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 17:19:24 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define RESET "\033[0m"

bool	create_outname_file(const std::string &str, std::ofstream &outfile)
{
	if (str.empty())
		return (false);
	
	std::string outname = str + ".replace";
	outfile.open(outname.c_str());
	return (outfile.good());
}

std::string replace_all(std::string line, 
						const std::string &s1, 
						const std::string &s2)
{
	size_t pos = 0;
	
	if (s1.empty())
	{
		return (line);
	}
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return (line);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << MAGENTA << "Wrong number of args"
				<< RESET << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::ofstream	outfile;
	std::ifstream	infile(argv[1]);
	std::string		line;
	std::string		content;

	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	
	if (!infile)
	{
		std::cout << BG_MAGENTA << "ERROR" << RESET << ": "
				  << "file does not exist or cannot be opened\n" << RESET;
		return (EXIT_FAILURE);
	}
	if (!create_outname_file(argv[1], outfile))
	{
		std::cout << BG_MAGENTA << "ERROR" << RESET << ": "
				  << "cannot create file\n" << RESET;
		return (EXIT_FAILURE);
	}
	if (s1.empty())
	{
		std::cout << BG_MAGENTA << "ERROR" << RESET << ": "
				<< "s1 cannot be empty\n" << RESET;
		return (EXIT_FAILURE);
	}
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';	
	}
	outfile << replace_all(content, s1, s2);

	return (EXIT_SUCCESS);
}