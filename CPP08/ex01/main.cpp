#include "Span.hpp"

int main(void)
{
	try
	{
		Span sp(100000);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "Span size: " << sp.size() << std::endl;
		sp.mltpaddNumber(10000);
		std::cout << sp.getVector()[100] << std::endl;
		
		//multiaddnumbers sans appel a addnumber en boucle
		std::vector<int> A(10);
		std::srand( time ( NULL ) );
		std::generate( A.begin(), A.end(), std::rand );
		Span sp1(A.size());
		sp1.addNumbers(A.begin(), A.end());
		for (std::vector<int>::iterator it = A.begin(); it!=A.end(); ++it)
			std::cout << *it << ' ';
		std::cout << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}