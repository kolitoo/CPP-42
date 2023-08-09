/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:01:19 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:06:07 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class	Character;
class	ICharacter;
class	AMateria
{
	public:
		AMateria(std::string const& type);//constructeur
		AMateria(AMateria const& copy);
		virtual ~AMateria(void);

		AMateria&	operator=(AMateria const& substitue);

		std::string const& 	getType() const; //Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	_type;
};

#endif