#include <iostream>

int	main(int argc, int argv)
{
	int	i;
	int	j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = -1;
	while (argc > 1 && argv[++i])
	{
		j = -1;
		while (argv[i] && argv[i][++j])
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}