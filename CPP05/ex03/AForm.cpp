/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:32 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/16 13:04:12 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int tosign, int toexecute): _name(name), _tosign(tosign), _toexecute(toexecute)
{
	if (_toexecute < 1 || _tosign < 1)
		throw AForm::GradeTooLowException();
	if (_toexecute > 150 || _tosign > 150)
		throw AForm::GradeTooHighException();
	_issigned = 0;
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const& substitue): _name(substitue._name), _tosign(substitue._tosign), _toexecute(substitue._toexecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm&	AForm::operator=(AForm const& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string const&	AForm::getName(void) const
{
	return (_name);
}

int			AForm::getTosign(void) const
{
	return (_tosign);
}

int			AForm::getToexecute(void) const
{
	return (_toexecute);
}

bool			AForm::getissign(void) const
{
	return (_issigned);
}

void			AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > getTosign())
	{
		throw AForm::GradeTooLowException();
	}
	if (_issigned == 0)
		_issigned = 1;
}

std::ostream&	operator<<(std::ostream& flux, AForm const& AForm)
{
	flux << "AForm Name : " << AForm.getName() << "; Grade for sign : " << AForm.getTosign() << "; Grade for execute : " << AForm.getToexecute() << "; is signed " << AForm.getissign();
	return (flux);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}

const char*	AForm::UnsignedFormException::what(void) const throw()
{
	return ("Error Form unsigned");
}

const char*	AForm::OpenFileException::what(void) const throw()
{
	return ("Error file can't be open");
}

void	AForm::checkGrade(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getToexecute())
		throw (AForm::GradeTooLowException());
	if (getissign() == 0)
		throw (AForm::UnsignedFormException());
}
