/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:24:11 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/02 10:45:43 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string nom);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);

		ClapTrap 	&operator=(const ClapTrap &substitue);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		int			_life_point;
		int			_energy_point;
		int			_attack_dmg;
};

#endif