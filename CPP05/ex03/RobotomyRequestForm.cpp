#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& substitue): AForm(substitue), _target(substitue._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const&substitue)
{
	std::cout << "RobotomyRequestForm assignement called" << std::endl;
	if (this != &substitue)
	{
		*this = substitue;
		_target = substitue._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	checkGrade(executor);
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "*drill noise* " << _target << " was robotomised" << std::endl;
	else
		std::cout << "*drill noise* " << _target << " operation failed" << std::endl;
}