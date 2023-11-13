/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:44 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/13 15:30:00 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	b("Paul", 5);
	PresidentialPardonForm	p("TEST");

	b.signForm(p);

	b.executeForm(p);
}

// /*Form arbre*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	ShrubberyCreationForm	p("TEST");

// 	b.signForm(p);

// 	b.executeForm(p);
// }

// /*Form robot*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	RobotomyRequestForm	p("TEST");

// 	b.signForm(p);

// 	b.executeForm(p);
// }

// /*Pas de signature*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 1);
// 	PresidentialPardonForm	p("TEST");
// 	b.executeForm(p);
// 	b.executeForm(p);
// }

/*Signature impossible*/
// int	main()
// {
// 	Bureaucrat	b("Paul", 123);
// 	PresidentialPardonForm	p("TEST");

// 	b.signForm(p);

// 	b.executeForm(p);
// 	b.executeForm(p);
// }
