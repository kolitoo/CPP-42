/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:32 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/01 10:20:23 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int tosign, int toexecute): _tosign(tosign), _toexecute(toexecute)
{
	if (_toexecute < 1 || _tosign < 1)
		throw Form::GradeTooLowException();
	if (_toexecute > 150 || _tosign > 150)
		throw Form::GradeTooHighException();
	_name = name;
	_issigned = 0;
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const& substitue): _name(substitue._name), _tosign(substitue._tosign), _toexecute(substitue._toexecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form&	Form::operator=(Form const& substitue)
{
	if (this != &substitue)
	{
		_name = substitue._name;
		_issigned = substitue._issigned;
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

std::string const&	Form::getName(void) const
{
	return (_name);
}

int			Form::getTosign(void) const
{
	return (_tosign);
}

int			Form::getToexecute(void) const
{
	return (_toexecute);
}

bool			Form::getissign(void) const
{
	return (_issigned);
}

void			Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > getTosign())
	{
		throw Form::GradeTooLowException();
	}
	if (_issigned == 0)
		_issigned = 1;
}

std::ostream&	operator<<(std::ostream& flux, Form const& form)
{
	flux << "Form Name : " << form.getName() << "; Grade for sign : " << form.getTosign() << "; Grade for execute : " << form.getToexecute() << "; is signed " << form.getissign();
	return (flux);
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}
