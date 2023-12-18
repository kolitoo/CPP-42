#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream fichier(av[1]);
		if (!fichier)
			return (std::cout << "Error: file or argument isn't a file" << std::endl, 1);
		try
		{
			std::ifstream file("data.csv");
			if (!file)
				return (std::cout << "Error: BDD Error" << std::endl, 1);
			BitcoinExchange	bitcoinex(file);
			bitcoinex.PutDataInMap();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return (0);
}