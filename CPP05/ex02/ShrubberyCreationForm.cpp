#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& substitue): AForm(substitue), _target(substitue._target)
{
	std::cout << "ShrubberyCreationForm constructor copy called" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const&substitue)
{
	if (this != &substitue)
	{
		_target = substitue._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	checkGrade(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n$$$$$$$$\n   ||   \n   ||   \n";
		file.close();
	}
	else
		throw (AForm::OpenFileException());
}