/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:44 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/21 11:52:34 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form		form("form", 50, 150);
		Bureaucrat	bureaucrat("Jean", 50);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);

	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}
}
