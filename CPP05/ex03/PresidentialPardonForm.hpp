/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:41:12 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/13 21:25:31 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& substitue);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(PresidentialPardonForm const&substitue);
		virtual void	execute(Bureaucrat const& executor) const;

	private :
		std::string	_target;
};

#endif