#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialRequestForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& substitue) : AForm(substitue), _target(substitue._target)
{
	std::cout << "PresidentialPardonForm copie constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& substitue)
{
	std::cout << "PresidentialPardonForm assignement called" << std::endl;
	if(this != &substitue)
	{
		*this = substitue;
		_target = substitue._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	checkGrade(executor);
	std::cout << _target << " you are forgiven by President Zaphod Beeblebrox." << std::endl;
}