#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << static_cast<char>(
				std::toupper(static_cast<unsigned char>(argv[i][j]))
			);
			++j;
		}
		if (i + 1 < argc)
			if (argv[i][j - 1] != ' ' && argv[i + 1][0] != ' ')
				std::cout << ' ';
		++i;
	}
	std::cout << '\n';
	return (0);
}
