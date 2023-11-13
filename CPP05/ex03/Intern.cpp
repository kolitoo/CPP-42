#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const& substitue)
{
	(void)substitue;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(Intern const& substitue)
{
	if (this != &substitue)
	{
	}
	return (*this);
}

const char*	Intern::NoMatchNameException::what() const throw()
{
	return ("No form match for this name");
}

AForm*	Intern::makeForm(std::string nameForm, std::string target)
{
	AForm	*form;
	int	i = 0;
	std::string	formTab[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	while (i < 3 && formTab[i] != nameForm)
		i++;
	switch (i)
	{
		case (0):
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			break;
		case (1):
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			break;
		case (2):
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			break;
	
		default:
			throw NoMatchNameException();
			break;
	}
	return (form);
}