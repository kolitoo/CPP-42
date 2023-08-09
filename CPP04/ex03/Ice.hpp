/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:17:06 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:01:23 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Character;
class Ice : public AMateria
{
	public :
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);

		Ice	&operator=(Ice const& substitue);

		AMateria	*clone() const;
		void		use(ICharacter& target);
};

#endif