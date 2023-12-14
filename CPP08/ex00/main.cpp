#include "easyfind.hpp"
#include <vector>

int	main(void)
{
	std::vector<int>	int_container;

	for(int i = 0; i <= 5; i++)
		int_container.push_back(i);
	if (easyfind(int_container, 5) == 1)
		std::cout << "Value found in the container" << std::endl;
	else
		std::cout << "Value not found in the container" << std::endl;
}
