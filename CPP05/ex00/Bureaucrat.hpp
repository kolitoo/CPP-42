/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:50 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/01 09:32:41 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& substitue);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat const& substitue);
		
		std::string const	getName(void) const;
		int			getGrade(void) const;
		void			incremGrade(void);
		void			decremGrade(void);

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