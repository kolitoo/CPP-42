#include "PmergeMeVec.hpp"
#include "PmergeMeDeque.hpp"
#include <algorithm>
#include <sys/time.h>

void	printBefore(char **av)
{
	std::cout << "Before : ";
	for(unsigned int i = 1; av[i] != NULL; i++)
	{
		std::cout << av[i] << " ";
		if (i == 5 && av[i + 1] != NULL)
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;
}

template <typename T>
static void	printAfter(T conteneur)
{
	std::cout << "After :  ";
	for(unsigned int i = 0; i < conteneur.size(); i++)
	{
		std::cout << conteneur[i] << " ";
		if (i == 4 && i != conteneur.size() - 1)
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;
}

long long	GetTime(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	 return static_cast<long long>(ts.tv_sec) * 1000000 + ts.tv_nsec / 1000;
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			long long time_before = GetTime();
			PmergeMeVec	Vect(av, ac);
			Vect.SortVector();
			long long time_after = GetTime();
			printBefore(av);
			printAfter(Vect.GetArray());
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int> : " << time_after - time_before << " microsecondes" << std::endl;
			time_before = GetTime();
			PmergeMeDeque	Dequ(av, ac);
			Dequ.SortDeque();
			time_after = GetTime();
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::Deque<int> : " << time_after - time_before << " microsecondes" << std::endl;
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

