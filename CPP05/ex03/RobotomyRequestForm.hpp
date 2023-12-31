/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:39:59 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/13 21:26:16 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& substitue);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(RobotomyRequestForm const&substitue);
		virtual void	execute(Bureaucrat const& executor) const;

	private :
		std::string	_target;
};

#endif