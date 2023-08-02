/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:41:04 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/02 13:46:27 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &copy);
			~ScavTrap(void);

			ScavTrap &operator=(const ScavTrap &other);

			virtual void	attack(const std::string& target);
			void	guardGate();
			void	print_info(void);

};

#endif