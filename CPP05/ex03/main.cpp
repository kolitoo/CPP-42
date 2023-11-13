/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:44 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/13 21:22:05 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	Bureaucrat	p("Paul", 2);
	AForm* goodForm;
	AForm* badForm;

	try
	{
		goodForm = someRandomIntern.makeForm("robotomy request", "Bender");
		p.signForm(*goodForm);
		p.executeForm(*goodForm);
		badForm = someRandomIntern.makeForm("robotmy request", "Bender");
		p.signForm(*badForm);
		p.executeForm(*badForm);
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete goodForm;

	return (0);
}
