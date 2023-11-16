/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:52 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:24 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& substitue): _name(substitue._name), _grade(substitue._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


std::string const	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incremGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decremGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error grade too low");
}

std::ostream&	operator<<(std::ostream& flux, Bureaucrat const& bureaucrat)
{
	flux << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (flux);
}

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	std::cout << _name << " signed " << form.getName() << std::endl;
}