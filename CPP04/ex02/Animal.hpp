/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:03:33 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 11:50:55 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal(void);

		AAnimal	&operator=(const AAnimal &substitue);
		virtual void	makeSound() const = 0;//virtuelle pure
		std::string	getType() const;
		
	protected:
		std::string	_type;
};

#endif