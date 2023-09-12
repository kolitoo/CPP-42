/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:50 by abourdon          #+#    #+#             */
/*   Updated: 2023/09/12 13:44:22 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

class Form;
class	Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& substitue);
		Bureaucrat&	operator=(Bureaucrat const& substitue);
		~Bureaucrat(void);
		std::string const	getName(void) const;
		int			getGrade(void) const;
		void	incremGrade(void);
		void	decremGrade(void);
		void	signForm(Form& form);

	private:
		std::string	_name;
		int			_grade;
		class GradeTooHighException : public std::exception
		{
			public:
				 virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				 virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& flux, Bureaucrat const& bureaucrat);

#endif