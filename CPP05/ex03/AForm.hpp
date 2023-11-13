/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:00 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/13 21:26:51 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int tosign, int toexecute);
		AForm(AForm const& substitue);
		AForm&	operator=(AForm const& substitue);
		virtual ~AForm(void);
		std::string const&	getName(void) const;
		int			getTosign(void) const;
		int			getToexecute(void) const;
		bool			getissign(void) const;
		void			beSigned(Bureaucrat const& bureaucrat);
		virtual void execute(Bureaucrat const& executor) const = 0;
		void	checkGrade(Bureaucrat const& executor) const;
		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	UnsignedFormException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	OpenFileException : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		
	private:
		std::string	_name;
		bool		_issigned;
		const int	_tosign;
		const int	_toexecute;
};

std::ostream&	operator<<(std::ostream& flux, AForm const& form);

#endif