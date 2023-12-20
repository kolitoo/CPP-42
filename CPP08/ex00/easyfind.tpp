#include "easyfind.hpp"

template <typename T>
int	easyfind(T& first, int second)
{
	if (std::find(first.begin(), first.end(), second) == first.end())
		return (0);
	else
		return (1);
}
