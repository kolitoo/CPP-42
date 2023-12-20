#include "RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			return (std::cout << "Error: Enter \"./RPN Polish mathematical expression\"" << std::endl, 1);
		Rpn	RPN(av[1]);
		RPN.ParseAv();
		RPN.Execute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
}