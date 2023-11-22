#include "iter.hpp"

//char array
int	main(void)
{
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLenght = sizeof(charArray) / sizeof(char);

	iter(charArray, charArrayLenght, printelem<char>);
}

//int array
// int	main(void)
// {
// 	int intArray[] = {1, 2, 3, 4, 5};
// 	size_t intArrayLenght = sizeof(intArray) / sizeof(int);

// 	iter(intArray, intArrayLenght, printelem<int>);
// }

// //char* array
// int	main(void)
// {
// 	const char* charArray[] = {"bordeaux", "lille", "paris", "marseille", "lyon"};
// 	size_t charArrayLenght = sizeof(charArray) / sizeof(char*);

// 	iter(charArray, charArrayLenght, printelem<const char*>);
// }