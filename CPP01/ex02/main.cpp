/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:03:37 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/20 10:52:03 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	/*montre les adresses*/
	std::cout << "         ADDRESS\n" << "-------------------------" << std::endl;
	std::cout << "str:       " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;
	std::cout << "-------------------------" << std::endl;


	/*montre la valeur pointee*/
	std::cout << "         VALUES\n" << "-------------------------" << std::endl;
	std::cout << "str:       " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	std::cout << "-------------------------" << std::endl;
}
