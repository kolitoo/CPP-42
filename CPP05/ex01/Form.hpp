/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:32:00 by abourdon          #+#    #+#             */
/*   Updated: 2023/09/11 14:45:19 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int tosign, int toexecute);
		Form(Form const& substitue);
		Form&	operator=(Form const& substitue);
		~Form(void);
		std::string const&	getName(void) const;
		int			getTosign(void) const;
		int			getToexecute(void) const;
		bool			getissign(void) const;
		void			beSigned(Bureaucrat const& bureaucrat);
		
	private:
		std::string	_name;
		bool		_issigned;
		const int	_tosign;
		const int	_toexecute;
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
		
};

std::ostream&	operator<<(std::ostream& flux, Form const& form);

#endif