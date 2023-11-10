/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:09:44 by abourdon          #+#    #+#             */
/*   Updated: 2023/11/01 09:43:03 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		//Bureaucrat	bureaucrat("Jean", -2);
		//Bureaucrat	bureaucrat("Jean", 1);
		Bureaucrat	bureaucrat("Jean", 150);
		//Bureaucrat	bureaucrat("Jean", 149);

		bureaucrat.decremGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incremGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}