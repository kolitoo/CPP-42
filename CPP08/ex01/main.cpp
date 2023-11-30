#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp = Span(100000);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "Span size: " << sp.size() << std::endl;
        sp.mltpaddNumber(10000);
        std::cout << "Span size: " << sp.size() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}