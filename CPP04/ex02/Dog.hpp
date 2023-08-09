/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:07:04 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 11:50:41 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		virtual ~Dog(void);

		Dog	&operator=(const Dog &substitue);
		virtual void	makeSound() const;

	private:
		Brain	*_Brain;
};

#endif