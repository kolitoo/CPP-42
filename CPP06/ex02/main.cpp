#include "Base.hpp"

Base*	generate(void)
{
	srand(time(NULL));
	int randomValue = rand() % 3;
	switch (randomValue)
	{
		case 0:
		{
			Base* Abase = new A();
			return (Abase);
		}
		case 1:
		{
			Base* Bbase = new B();
			return (Bbase);
		}
		case 2:
		{
			Base* Cbase = new C();
			return (Cbase);
		}
		default:
			return (NULL);
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Identify an Abase" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Identify a Bbase" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identify a Cbase" << std::endl;
	else
		std::cout << "ERROR: Unknow base" << std::endl;
}

int	main(void)
{
	Base* obj = generate();
	identify(obj);

	delete obj;
	return (0);
}