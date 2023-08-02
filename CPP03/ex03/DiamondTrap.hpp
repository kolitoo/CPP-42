/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:22:17 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/02 16:15:16 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class	DiamondTrap : public ScavTrap , public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap(void);
		
		DiamondTrap 	&operator=(const DiamondTrap &substitue);
		void	whoAmI(void);
		void	print_info(void);
		void	attack(const std::string& target);
		
	private:
		std::string	_name;
};

#endif

