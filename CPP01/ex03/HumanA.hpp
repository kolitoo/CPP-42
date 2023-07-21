/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:15 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:41:49 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string str, Weapon &weaponA);
		~HumanA(void);

		void	attack(void);

	private:
		Weapon &_weaponA;
		std::string _name;
};

#endif