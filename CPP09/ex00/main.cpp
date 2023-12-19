#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream file(av[1]);
		if (!file)
			return (std::cout << "Error: could not open file." << std::endl, 1);
		std::ifstream bdd("data.csv");
		if (!bdd)
			return (std::cout << "Error: BDD Error." << std::endl, 1);
		if (bdd.peek() == std::ifstream::traits_type::eof())
			return (std::cout << "Error: BDD empty." << std::endl, 1);
		try
		{
			BitcoinExchange	bitcoinex(bdd, file);
			bitcoinex.DoTasks();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	else
		std::cout << "Wrong number of arguments." << std::endl;
	return (0);
}