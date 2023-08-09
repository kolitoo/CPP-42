/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:35:06 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:10:23 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	AMateria;
class	ICharacter;
class Character : public ICharacter
{
	public:
		Character (std::string name);
		Character(const Character &copy);
		~Character(void);

		Character	&operator=(const Character &substitue);

		std::string const& getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idc, ICharacter &target);

	private:
		AMateria *_inventaire[4];
		std::string	_name;
};

#endif