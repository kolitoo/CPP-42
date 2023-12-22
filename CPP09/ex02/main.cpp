#include "PmergeMeVec.hpp"

void	printBefore(char **av)
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
		try
		{
			PmergeMeVec	Vect(av);
			Vect.ParseAndPutInVector();
			//printBefore(av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	else
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}