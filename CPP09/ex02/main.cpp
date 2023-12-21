#include "PmergeMeVec.hpp"

static void	printBefore(char **av)
{
	std::cout << "Before : ";
	for(unsigned int i = 1; av[i] != NULL; i++)
	{
		std::cout << av[i] << " ";
		// if (i == 5)
		// 	break ;
	}
	// for(unsigned int i = 1; av[i] != NULL; i++)
	// {
	// 	if (i > 5)
	// 	{
	// 		std::cout << "[...]";
	// 		break ;
	// 	}
	// }
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		printBefore(av);
	}
	else
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}