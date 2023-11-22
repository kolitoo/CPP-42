#include "whatever.hpp"

// int	main(void)
// {
// 	int	a = 5;
// 	int	b = 10;
// 	// double	a = 55.45;
// 	// double	b = 10.5484;

// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;

// 	std::cout << "----- MIN -----\n";
// 	std::cout << "Le min est : " << min(a, b) << std::endl;

// 	std::cout << "----- MAX -----\n";
// 	std::cout << "Le max est : " << max(a, b) << std::endl;

// 	std::cout << "----- SWAP -----\n";
// 	swap(a, b);
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// }

int main( void ) {

int a = 2;
int b = 3;

::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";

::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

return 0;

}