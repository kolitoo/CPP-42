/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:24:02 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:01:27 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Character;
class Cure : public AMateria
{
	public :
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		Cure	&operator=(Cure const& substitue);

		AMateria	*clone() const;
		void		use(ICharacter& target);
};

#endif