/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:03:33 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 17:28:26 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		Animal	&operator=(const Animal &substitue);
		virtual void	makeSound() const;
		std::string	getType() const;
		
	protected:
		std::string	_type;
};

#endif