/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:07:04 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 17:28:29 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		virtual ~Cat(void);

		Cat	&operator=(const Cat &substitue);
		virtual void	makeSound() const;

};

#endif